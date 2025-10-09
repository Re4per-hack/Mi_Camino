
Cuando vemos que uno de nuestros inputs se refleja en la pagina usualmente podemos estar en frente a un XSS, podemos intentar enviar un XSS basico para ver como se comporta la aplicacion:

```html
<script>alert(1)</script>
```

```html
<img src="x" onerror="alert(1)"/>
```

### Se refleja en un Link


# XSS 

A veces nuestro input se usa para un link, por ejemplo cuando podemos indicarsi tenemos una pagina web, en este caso podemos usar la siguiente injeccion:

```js
javascript:alert(1)
```

# SSTI 

Tecnologias que pueden delatar un SSTI 

 - **Python**: Django, Jinja2, Mako, ...
- **Java**: Freemarker, Jinjava, Velocity, ...
- **Ruby**: ERB, Slim, ...

En la mayoria de los casos en los que nos encontramos un SSTI (Server Side Template Injection) es a travez de python gracias a la libreria de administracion de plantillas como jinja2, o simplemente cuando se usa el input de un usuario en una plantilla usando un framework, esta vulnerabilidad la podemos detectar con la siguiente carga util:

```python
${{<%[%'"}}%\.
```

Esto deberia causar un error en donde se refleja la injeccion.

https://cheatsheet.hackmanit.de/template-injection-table/

https://swisskyrepo.github.io/PayloadsAllTheThings/Server%20Side%20Template%20Injection/#inject-template-syntax











