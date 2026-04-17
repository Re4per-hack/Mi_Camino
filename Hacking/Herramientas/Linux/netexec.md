
### Buscar dispositivos pertenecientes al dominio

```python
netexec ldap 10.10.11.0/24 -u '{Usuario}' -p '{Contraseña}' 
```

### Authentication Spraying

Esta es una tecnica en la que si tenemos un usuario y una contraseña, podemos pasar esas credenciales en todas las maquinas de la red, para así saber en cuales puedes entrar:

```python
netexec ldap 10.10.11.12 -u '{Usuario}' -p '{Contraseña}' 
```

### Password Spraying

```python
netexec ldap 10.10.11.12 -u '{Usuario}' -p contraseñas.txt
```

### Password and user Spraying

```ruby
netexec ldap 10.10.11.12 -u users.txt -p contraseñas.txt
```


# Fuerza bruta de RIDs (Busqueda de usuarios)

```ruby
sudo netexec 10.10.11.12 -u 'kevin' -p 'pasas' --rid-brute
```

#  Listar o usar los modulos disponibles

!!!ATENCION!!!: Es importante aclarar que dependerá el servicio que elijamos nos mostrará unos modulos u otros, en este caso vamos a hacer la prueba con mssql


```ruby
sudo netexec mssql 10.10.11.12 -u 'kevin' -p 'pasas' -L  
```

![[Pasted image 20260411165325.png]]

La opción `-L`  es la que se encarga de listar los diferentes modulos, ahora veramos como se usarian estos respectivos modulos, por ejemplo, digamos que quiero saber que privilegios tiene el usuario kevin sobre mssql, para esto tenemos que usar el modulo mssql_priv:

```ruby
sudo netexec mssql 10.10.11.12 -u 'kevin' -p 'pasas' -M mssql_priv
```


![[Pasted image 20260411165602.png]]

Podemos ver que el usuario tiene permisos para impersonar (hacerse pasar) a el usuario appdev.








