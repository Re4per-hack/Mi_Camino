
Para esto vamos a hacer uso del protocolo ARP, ARP significa **Address Resolution Protocol** (Protocolo de Resolución de Direcciones)

Es un protocolo de red usado en redes IPv4 para **traducir direcciones IP en direcciones MAC** (físicas) dentro de una red local (LAN).

arpscan envía **paquetes ARP broadcast** a todas las IPs posibles dentro de la subred local (por ejemplo, 192.168.1.0/24).

```shell
arp-scan -I {Interfaz de red} --localnet
```


