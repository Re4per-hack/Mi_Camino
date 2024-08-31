# NRLM Relay Attack basico
## Teoría

Un ataque NTLM Relay Attack consta de interceptar los Hashes NTLMv2 mediante la suplantación de un recurso inexistente, a continuación lo explicaré paso a paso, pero quiero dejar claro el panorama para que se entienda bien, digamos que hay un dominio registrado con:


1. El equipo silvia quiere llamar al Equipo Juan, pero se equivoca y escribe jaun, por ejemplo:

```java
smb:\\jaun\resource
```

- En un caso normal no pasaría nada, un simple error sin consecuencias, pero que pasa si hay un Hacker en la red.

2. Un Hacker Intercepta el usuario y el hash del equipo de Silvia.

- Bueno, explicaré esto, como dije antes, esto si que es un problema ya que cada ves que se busca un nombre de dominio que el DC no tiene asociado con ninguna red, el equipo de silvia (quien realizo el "smb:\\\\jaun\\resource" ) envía peticiones a todo el rango de IP's  segun la mascara subred, todo esto de las IP's y mascaras subred está explicado [aquí](/Redes/Direcciones%20IP/Que%20clases%20hay%20y%20como%20identificarlas), el punto es que un atacante podria decirle a una de estas peticiones: "Si!! yo soy jaun, pero necesito tus credenciales para que te conectes a mi" y asi conseguimos el usuario con su respectivo hash NTLMv2 el cual si es de una contraseña debil lo podremos crackear fácilmente, este ataque se centra especialmente en a posteriori de recibir NTLM "pasarselo" a otra maquina, pero me estoy adelantando, eso ya lo veremos mas adelante.

3. El hacker intenta Crackear esa contraseña y si lo logra Silvia ha sido pwneada.

## Practica

Bueno, ya vimos la parte Teorica, pero vamos a ensuciarnos las manos un poco y iremos a la Practica, hay una herramienta muy versatil que nos sirve para envenenar redes y nos permite darle esa respuesta de "Yo soy lo que estas buscando!!" a las victimas de este ataque, y fuera de tanto suspenso hablo de el famoso Responder.py, a continuación su uso:

```java
responder -I eth0 -d -w -v
```

- -I: Especifica la interfaz por la que vamos a recibir los hashes 

- -d: 

- -v: Este parámetro indica que queremos mas información, yo lo suelo usar porque cuando hacemos este ataque y capturamos los hashes, no nos los vuelve a mostrar, entonces usemos este para metro para evitar esas cosas

- -w: 


Al iniciar este comando solo basta con esperar y veras como te van llegando esos Hashes

# NTLM Relay Attack avanzado 

## Teoría

Decir "Avanzado" hace ver como si esto fuera super dificil, pero para nada, ya veras lo facil que es de entender, empecemos por diferenciar el basico por el avanzado, en el basico lo unico que haciamos era  capturar el NTLMv2 que nos llegaba, pero con este ataque podemos hacer algo mucho mas interesante, pero para esto ya dependeremos de que la victima no tenga activado el windows defender ya que nos puede chapar esta tecnica, pero bueno, vamos al grano, ¿de que consta esta otra tecnica?

En el NTLM Relay Attack avanzado lo que hacemos es lo mismo que en el basico, pero esta vez vamos a coger este NTLMv2 y lo usaremos para ejecutar comandos en una maquina sobre la cual el usuario y hash que nos haya llegado tengan privilegios, intentaré hacerme entender, imaginemos que existen 2 usuarios en un Active Directory, sin contar el administrador, estos dos usuarios son Juan y Silvia, pero Juan tiene privilegios sobre Silvia, esto significa que juan puede ejecutar comandos en la maquina de Silvia, ya con esto entendido vamos a la maquina atacante:



- Supongamos que juan queria buscar:

```java
smb:\\sqlserver\pass
```

- Pero terminó buscando:

```java
smb:\\sqlselver
```

- Como este recurso no existe, pues pasara lo que yo ya había explicado arriba, a nosotros que como atacantes tendremos el responder ejecutándose vamos a recibir el hash y la contraseña, pero esta vez tenemos otras herramientas ejecutándose, que nos permiten coger ese NTLMv2 que nos llega y redirigirlo a Silvia, haciéndonos pasar por juan, y haciendo que ejecute un comando, y asi se tiene acceso a la maquina de Silvia

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

-  