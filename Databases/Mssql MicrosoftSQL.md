
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

```ruby
(mssql)> enum_logins
```

o, con syntaxis mysql:

```ruby
(mssql)> SELECT name, type_desc, is_disabled FROM sys.server_principals WHERE type_desc IN ('SQL_LOGIN', 'WINDOWS_LOGIN');
```

# Mirar usuarios de base de datos (Database Principals)

con impacket-mssql:

```ruby
(mssql)> enum_users
```

o, con syntaxis-mssql:

```ruby
SELECT name FROM sys.database_principals WHERE type_desc IN ('SQL_USER', 'WINDOWS_USER');
```


# Ejecutar comandos como otro usuario (si tenemos permisos impersonate)


con impacket-mssql:

```ruby
(mssql)> exec_as_login {usuario_para_hacerse_pasar}
```

o, con syntaxis-mssql:

```ruby
execute as login = 'appdev'
```



