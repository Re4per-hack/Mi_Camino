
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


