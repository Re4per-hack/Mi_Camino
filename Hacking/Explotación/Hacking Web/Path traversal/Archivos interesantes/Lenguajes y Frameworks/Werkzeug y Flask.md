
## Que es Werkzeug

Werkzeug es un framework que se  encarga de manejar todo lo que incluye interacciones con el servidor web, entre esto se encuentran: peticiones, API_endpoints, etc...

## Que es Flask

Flask es un framework que opera sobre Werkzeug e incluye otras caracteristicas aun mas interesantes, como jinja2 (soporte de plantillas), con este framework podmeos crear una pagina web de forma simple sin usar tantas lineas de codigo, lo cual aumenta su legibilidad y simplicidad.


## Archivos utiles

Esto puede variar según si se usa Flask o Werkzeug puro, pero es mucho mas común que se encuentre flask, igualmente vamos a ver formas de detectarlo, lo primero es revisar las variables de entorno u otros archivos del sistema a ver si podemos encontrar a Flask en alguna parte, usualmente cuando hay flask corriendo se suele ver en las variables de entorno, igualmente si no lo ves no lo descartes totalmente:


```ruby
/proc/self/environ
```

```ruby
/etc/environment
```


Ahora podemos intentar leer el archivo pronci, que listemos por los siguientes pposibles archivos:

!! si encontramos una variable de entorno llamada "FLASK_APP" esta variable contiene el archivo principal !!

- app.py
- run.py
- main.py
- server.py

## Archivo de configuracion

Usualmente podemos encontrar un archivo llamado config.py, el cual puede eocntener informacion de conexion a bases de datos:

- config.py
- templates/config.py











