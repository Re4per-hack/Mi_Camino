# Peticiones web

Para realizar peticiones web en python haremos uso de la libreria requests, la cual nos permite enviar solicitudes como POST, GET, HEAD, etc.

```python
import requests

url = "https://youtube.com/"

response = requests.get(url = url) 

```

Como se vio arriba, tambien podemos almacenar las respuestas a las solicitudes que hagamos, con ellas podemos sacar cosas como el texto, la url, los headers, las cookies, etc:


```python
import requests

  

url = "https://youtube.com"

  

respuesta = requests.get(url)

  

respuesta.text

respuesta.headers

respuesta.url

respuesta.encoding

respuesta.raw

# ETC...
```

## Agregar una cookie a la petición

Para añadir una cookie a nuestro request necesitaremos construir nuestras cookies en forma de [[Diccionarios]]


``` python
import requests

url = "https://youtube.com"

cookie = {
	"Nombre_coockie":"valor_Cookie",
	"Nombre_Cookie2":"valor_Cookie2"
		  
}

respuesta = requests.get(url, cookies = cookie)

# ETC...
```
