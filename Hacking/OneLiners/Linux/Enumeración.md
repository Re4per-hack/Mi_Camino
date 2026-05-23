
# Extraer datos

#### Extraer puertos nmap

```shell

```

# Busqueda hosts

#### Busqueda de hosts con curl

```bash
for i in $(seq 1 254); do (curl -s --connect-timeout 1 http://192.168.65.$i:2375/ 2>/dev/null && echo "192.168.65.$i:2375 OPEN") & done; wait
```
#### Busqueda de hosts con ping

```shell
for i in $(seq 1 254); do (ping -c 2 http://192.168.65.$i:2375/ 2>/dev/null && echo "192.168.65.$i:2375 OPEN") & done; wait
```





