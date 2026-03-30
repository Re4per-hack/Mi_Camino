primero debemos encontrar cual es la direccion de la API, esto lo podemos encontrar en las variables de entorno, en mi caso está en 10.43.0.1:443 (https):
 

# Campos

- **kind:** Tipo de dato 

-  
# Testear API

Para testear la API podemos usar la siguiente petición de curl:

```ruby
curl https://10.43.0.1/api --cacert={CA.crt FILE} -H 'Authorization: Bearer <Token>' 
```

Es importante definir tanto el ca certificate como el token de autorización

# Listar secretos 

Para listar secretos de un namespace especifico (en mi caso default):

```ruby
curl https://10.43.0.1/api/v1/namespace/default/secrets --cacert={CA.crt FILE} -H 'Authorization: Bearer <Token>' 
```

Es importante definir tanto el ca certificate como el token de autorización


