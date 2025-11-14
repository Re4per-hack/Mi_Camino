primero debemos encontrar cual es la direccion de la API, esto lo podemos encontrar en las variables de entorno, en mi caso está en 10.43.0.1:443 (https):

# Listar secretos 

Para listar secretos de un namespace especifico (en mi caso default):

```http
GET /api/v1/namespace/default/secrets
```



