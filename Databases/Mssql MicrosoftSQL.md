
Puerto: 1433

|**Nivel**|**MySQL**|**MSSQL**|
|---|---|---|
|**Contenedor Principal**|Database (o Schema)|Database|
|**Organización Interna**|No tiene (las tablas van directo a la DB)|**Esquema** (capa intermedia)|
|**Referencia Completa**|`base_de_datos.tabla`|`BaseDeDatos.Esquema.Tabla`|
|**Seguridad**|A nivel de base de datos/tabla|A nivel de base de datos/esquema/tabla|

# Conectarse remotamente

para esto podemos usar la herramienta mssqlclient de impacket:

```shell
impacket-mssqlclient '[DOMAIN]/[USER]:[PASS]@[IP]'
```


# Mirar las Bases de Datos


```mysql
SELECT name FROM sys.databases;
```

Bases de datos por defecto:

- master
- model
- msdb
- tempdb

# Mirar usuarios de login (Server Principals)

Con impacket-mssql:

```shell
(mssql)> enum_logins
```

o, con syntaxis mysql:

```
(mssql)> 
```

# Mirar usuarios de base de datos (Database Principals)