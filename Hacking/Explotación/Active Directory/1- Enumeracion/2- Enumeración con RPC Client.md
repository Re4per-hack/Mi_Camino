**RPC (Remote Procedure Call)** es un protocolo que permite que un programa ejecute funciones o procedimientos en otro equipo dentro de una red, como si fueran locales. Es una tecnología fundamental en sistemas Windows, y se usa mucho en **Active Directory**, administración remota, servicios de archivos, impresoras, etc.

## Verificar si se puede un null session

Lo primero que debemos probar es si podemos entrar usando una Null session (entrar sin contraseña) con RPC client, para esto usaremos el siguiente comando:

```python
rpcclient -U "" {IP_DC} -N 
```

## En caso de no poder ingresar con Null session


```python
rpcclient -U "[NOMBRE_DOMINIO/][USUARIO]%[CONTRASEÑA]" {IP-DC}
```

### Enumerar usuarios y sus descripciones

Comandos de RPC interesantes

- enumdomusers: Enumera todos los usuarios del dominio junto con sus rid's

- queryuser {RID}: Enumera los datos de un usuario, como a que grupo pertenece, su descripción, nombre, etc...

- enumdomgroups: Enumera los grupos existentes en el dominio y sus respectivos rid's 

- querygroup {Group_RID}: 


