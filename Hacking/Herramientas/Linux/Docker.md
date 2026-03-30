# Ejecutar un DockerFile

Cuando queremos ejecutar una imagen docker File, primero necesitamos crear la imagen de la que Docker se va a fijar 

#### Creacion de imagen

```ruby
docker build -t nombre-de-tu-imagen .
```

#### Iniciar el contenedor como un servicio

Ya creada la Imagen podemos iniciar el Contenedor como un servicio, es decir, vamos a convertir uno de nuestros puertos en un puerto del contenedor:

```ruby
docker run -d -p 8000:8000 nombre-de-tu-imagen
```

#### Iniciar y entrar en el conetenedor 

```ruby
docker run -it --entrypoint nombre-de-tu-imagen
```

# Ver los contenedores activos  (Y sus IDs)

```ruby
docker ps
```


# Meter archivos de la maquina al contenedor 

Esto es necesario ahcerlo **FUERA DEL CONTENEDOR**, tambien tenemos que saber el ID del contenedor que queremos meterle el archivo, despues de eso ejecutar el siguiente comando:

```ruby
docker cp /archivo/para/mover {ID_CONTENEDOR}:/ruta/destino
```


