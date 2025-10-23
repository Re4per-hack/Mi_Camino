- 

Muchas veces nos podemos encontrar con que hay usuarios que han sido elimiandos del dominio y tenian permisos o recursos que nos servian, primero tenemos que buscar el usuario:

```shell
Get-ADObject -Filter 'isDeleted -eq $true -and objectClass -eq "user"' -IncludeDeletedObjects
```

En este caso filtramos por  un usuario eliminado y cuyo tipo es un usuario, ahora a restaurarlo

Podemos usar el mismo Get-ADObjet para obetener el usuario, y pasarselo a Restore-ADObject , pero tenemos que asegurarnos de que solo pase un objeto, es decir, la salida se debe ver algo así:

![[Pasted image 20251022074119.png]] 

Solo hay un Objeto que es el del usuario Todd Wolfe, esto es justo lo que necesitamos para pasarselo a Restore-ADObject de la siguiente forma:

```shell
Get-ADObject -Filter 'isDeleted -eq $true -and objectClass -eq "user"' -IncludeDeletedObjects | Restore-ADObject 

```
 
