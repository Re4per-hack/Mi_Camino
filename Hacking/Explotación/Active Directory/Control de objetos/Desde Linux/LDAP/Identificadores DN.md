Cuando hablamos de un DN es como la ruta absoluta hacia un objeto, porque si, al usar LDAP, se usa una jerarquia en arbol de archivos, bastante similar a lo que vemos en linux por ejemplo:

```r
                          (raíz del árbol)
dc=empresa,dc=com                
 ├── ou=Usuarios,dc=empresa,dc=com
 │    ├── cn=Juan Perez,ou=Usuarios,dc=empresa,dc=com
 │    └── cn=Maria Gomez,ou=Usuarios,dc=empresa,dc=com
 ├── ou=Grupos,dc=empresa,dc=com
 │    ├── cn=Admins,ou=Grupos,dc=empresa,dc=com
 │    └── cn=Developers,ou=Grupos,dc=empresa,dc=com
 └── ou=Equipos,dc=empresa,dc=com
      ├── cn=PC01,ou=Equipos,dc=empresa,dc=com
      └── cn=PC02,ou=Equipos,dc=empresa,dc=com
```

## Que significa cada RDN 


- **DC** → dominio (DC=puppy,DC=htb).

- **OU** → unidad organizativa (carpeta lógica).

- **CN** → nombre común del objeto (usuario, grupo, equipo).

- **DN** → toda la ruta que combina DC, OU, CN = identificador único.


