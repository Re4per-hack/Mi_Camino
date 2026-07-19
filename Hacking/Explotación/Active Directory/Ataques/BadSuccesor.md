
Esta vulnerabilidad esta en versiones adelante de Windows Server 2025,  consiste en que nuevas versiones hubo la implementacion de cuentas dMSA (delegated Managed Service Accounts), estas cuentas sirven para ser usadas por servicios (SQL, IIS, HTTP, etc) no por humanos, pero aparte de este uso tienen una carateristica interesante. 


# Managed Service Predecessor

Este tipo de cuentas permiten apuntar el parametro msDS-ManagedServicePredecessor al DN (Ej: DN:Administrator,OU:) de cualquier usuario, esto implica que cuando la dMSA pida un ticket al KDC, este le de un ticket que para cualquier servicio, seria como si fuera un ticket del usuario que tenga en el parametro ManagedAccountPrecededByLink por ejemplo, administrador, esto significa una elevacion de privilegios absoluta e instantanea.


# Deteccion

Para explotar  esta vulnerabilidad, se tienen que cumplir 3 condiciones:

- CREATE_CHILD sobre algun Organization Unit:

```shell
sudo bloodyAD -u 'Juan' -p 'Pass' -d 'dominio.local' --host {IPDC} --dc-ip {IPDC} get writable 
```

- Windos Server 2025 o superior'

# Explotación

Primero tenemos que crear una cuenta dMSA con el atributo ManagedAccountPrecededByLink apuntando hacia el admin y el parametro  `msDS-DelegatedMSAState = 2` esto lo podemos lograr con la herramienta BadSuccessor, que podemos encontrar [aquí](https://raw.githubusercontent.com/LuemmelSec/Pentest-Tools-Collection/refs/heads/main/tools/ActiveDirectory/BadSuccessor.ps1): 

![[Pasted image 20260419130611.png]]

Listo, ya está creada la cuenta que nos permite Hacer la escalada de privilegios, y ahora podemos pedir un ticket como esa cuenta, nos entregarán el ticket de Administrator:







