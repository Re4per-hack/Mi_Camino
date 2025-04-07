Para entender este documento y los que vienen por delante, revisa [[7- Que es la SameSite cookie]], en este caso tenemos un exploit server y sabiendo que la cookie es Lax, podemos probar varias cosas:

- Probar si el sitio web en el que queremos comer el CSRF permite subir los datos por un metodo GET

En caso de que esto no funcione, podemos probar si el sitio web permite un método override, pero, ¿Que es un método override?, esta es una función que tienen algunos servidores para que podamos enviar datos con un método, pero que el servidor lo procese como el especificado, es decir, podemos enviar un request GET, pero que el servidor lo procese como un GET, esto nos sirve, porque como sabemos la SameSite Cookie con valor Lax no envía la cookie session con peticiones POST, para hacer esto únicamente tenemos que agregar un parámetro mas que es \_method=POST, nuestro exploit server quedaría algo así:

```html
<form method="GET" action="http://example.com/change-email">
	<input type="hidden" name="email" value="mail@mail.com"/>
	<input type="hidden" name="_method" value="POST">
</form>

<script>
	document.forms[0].submit();
</script>
```


