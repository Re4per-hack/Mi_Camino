
Para este caso primero debemos obtener los atributos  iniciales del objeto para saber que modificar exactamente, [[Obteniendo informacion con LDAP (Manualmente)]].

```shell
ldapmodify -x -H ldap://10.10.11.70 -D "ANT.EDWARDS@PUPPY.HTB" -W << EOF
dn: CN=Adam D. Silver,CN=Users,DC=PUPPY,DC=HTB
changetype: modify
replace: userAccountControl
userAccountControl: 66048
EOF
```


La estructura es la siguiente:

- dn: Primero el identificador DN (ruta al objeto destino), mas información aquí [[Identificadores DN]]

```r
dn: <distinguishedName>
changetype: modify
<operation>: <attributeName>
<attributeName>: <value>
<attributeName>: <value>   # (puede repetirse)
-
<operation>: <attributeName>
...
```

Donde \<operation\> es uno de: add, delete, replace. El - separa cada operación dentro del mismo dn.

Siempre sigue una estructura similar, es recomendable hacer cambios en objetos de esta forma ya que nos permite tener control total sobre las peticiones 




