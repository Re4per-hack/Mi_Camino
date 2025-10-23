
Para esta tarea haremos uso de  ldapsearch, una herramienta que nos permite enumerar los diferentes atributos de los objetos en un AD (Directorio Activo).

A continuación un ejemplo basico: 

```ruby
ldapsearch -x -H ldap://10.10.11.70 -D "ANT.EDWARDS@PUPPY.HTB" -W -b "DC=puppy,DC=htb" "(sAMAccountName=ADAM.SILVER)"
```


- **ldapmodify**: Comando que nos permite modificar distintos atributos de un objeto

- **-x**: Autenticación simple (No usará autenticación SALS kerberos, NTLM u otras) Usar si no se tiene configurada la autenticación **SASL (Simple Authentication and Security Layer)**

- **-H**: Para indicar el servidor a conectarse (ldap://servidorLDAP), si no se indica  intentará autenticarse al local host

- **-D:** Se usa para indicarse el usuario y dominio al que queremos conectarnos ("usuario@dominio.local") 

- **-W:** Se usa para que nos pida contraseña y no tenerla que pasar directamente en la linea de comandos, importante, sino se tomaría como que no enviamos la contraseña para ese usuario, en caso de que queramos pasar la contraseña directamente podemos usar la opción -w (ewn minuscula) (ej. -w "password123!")

- **-b:** Este es el filtro que vamos a usar para que nos muestre lo que necesitamos, para esto podemos usar los [[Identificadores DN]] o atributos especificos.


### Filtros de LDAP 

En la siguiente pagina se explica bastante bien como podemos usar los filtros de LDAP, o, lo que es lo mismo, la opción -d:

https://docs.simego.com/how-to/active-directory/ldap/