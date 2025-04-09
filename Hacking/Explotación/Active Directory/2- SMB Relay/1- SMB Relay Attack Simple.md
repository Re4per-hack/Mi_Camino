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

- -w: Activa un servidor WPAD (Web Proxy Auto-Discovery protocol) falso, WPAD es un protocolo que permite a las maquinas configurar automáticamente los proxies necesarios para cada caso, en concreto este es un archivo, el cual define estas configuraciones proxy, la localización de este archivo es definida por el DHCP, pero también hace una búsqueda automática con diferentes dominios como wpad.local o wpad.{dominioactual}

Al iniciar este comando solo basta con esperar y veras como te van llegando esos Hashes

## Ejemplo 


![[SMB Relay 1.png]]

Ya con el Hash podemos hacer una de estas cosas: 

