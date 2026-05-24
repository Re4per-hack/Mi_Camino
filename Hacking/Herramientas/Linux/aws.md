

# General
#### Configurar Access Keys

Si vamos a interactuar con un servidor aws es importante tener las credenciales indicadas si es que no vamos a hacer un null session, para esto podemos usar el siguiente comando que nos va a ayudar a definir las secret keys:

```ruby
aws configure
```

#### Especifica endpoint

Muchas veces, sobre todo en laboratorios privados, no vamos a interactuar directamente con los servidores en amazon, sino que vamos a interactua con un servidor que emula la api de aws, para ello agregamos el parametro **`--endpoint-url`**

Ejemplo:

```r
aws s3 ls --endpoint-url {url||ej:http://{ip}:{PUERTO}}
```

# S3
#### Listar contenidos de S3 

```r
aws s3 ls  s3://{Bucket-Name}
```





