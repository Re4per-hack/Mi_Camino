para esta tarea podemos hacer uso de [[smbclient]]  o aun mejor, de [[smbmap]], primero veremos como hacerlo con smbmap ya que es la mejor opcion:
# SMBMap
### Null session con smbmap

Excelente para intentar sin credenciales previas, para esto tenemos que indicar un usuario pero no importa lo que pongamos, si no existe se tomará automaticamente como un Null session

```python
smbmap -H {IP_DC} -u 'cualquiercosa'
```

Esto nos va a mostrar los recursos compartidos y los respectivos permisos que tengamos sobre ellos

### Autenticación con smbmap

En caso de que tengamos credenciales, lo mejor es listar que recursos podemos ver

```python
smbmap -H {IP_DC} -u '{USUARIO}' -p '{CONTRASEÑA}'
```

###  Ver lo que hay en un recurso

Si despues de listar los recursos vemos que alguno tiene Readable permissions.

```python
smbmap -H {IP_DC} -u '{USUARIO}' -p '{CONTRASEÑA}' -r '{RECURSOS}'
```

### Descargar archivos con smbmap

```python
smbmap -H {IP_DC} -u '{USUARIO}' -p '{CONTRASEÑA}' --download '{PATH}'
```
# SMBClient

### Null session con smbclient

Como dije antes esta o es la mejor opcion pero por cualquier documentaré el uso por aquí 

```python
smbmap -L {IP_DC} -N
```

### Autenticación con smbclient

```python
smbclient -L {IP_DC} -U [DOMINIO]/[USUARIO]%[CONTRASEÑA]
```




