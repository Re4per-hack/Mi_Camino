Para esto vamos a usar una petición LDAP (Lightweight Directory Access Protocol) que nos permitirá alterar diferentes atributos de un objeto en Active Directory, aquí peude sver como se crea una request de modificación: [[Cambiar atributos de un objeto ldapmodify (Manualmente)]].

```bash
ldapmodify -x -H ldap://10.10.11.70 -D "usuario@dominio.local" -W << EOF
dn: CN=Adam D. Silver,CN=Users,DC=PUPPY,DC=HTB
changetype: modify
replace: userAccountControl
userAccountControl: 66048
EOF
```


- **ldapmodify**: Comando que nos permite modificar distintos atributos de un objeto

- **-x**: Autenticación simple (No usará autenticación SALS kerberos, NTLM u otras) Usar si no se tiene configurada la autenticación **SASL (Simple Authentication and Security Layer)**

- **-H**: Para indicar el servidor a conectarse (ldap://servidorLDAP), si no se indica  intentará autenticarse al local host

- **-D:** Se usa para indicarse el usuario y dominio al que queremos conectarnos ("usuario@dominio.local") 

- **-W:** Se usa para que nos pida contraseña y no tenerla que pasar directamente en la linea de comandos, importante, sino se tomaría como que no enviamos la contraseña para ese usuario, en caso de que queramos pasar la contraseña directamente podemos usar la opción -w (ewn minuscula) (ej. -w "password123!")