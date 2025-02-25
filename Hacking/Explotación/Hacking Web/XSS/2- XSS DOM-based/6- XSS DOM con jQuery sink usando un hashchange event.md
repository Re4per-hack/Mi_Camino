En este caso se usa del hashtag para desplazar hacia la zona seleccionada, un ejemplo de esto es wikipedia, se pueden usar hashtags para ir a una parte especifica del documento HTML, en el siguiente ejemplo jQuery, cuando se tratan estos datos con jQuery pueden ser interceptados, pero por medida de seguridad no se interpretan las etiquetas script, por lo que tendremos que usar lo siguiente:

```html
<img src="noexistente" onerror=alert(1)>
```

Podemos poner esto con el propio hashtag, pero algo interesante que podemos hacer, es que podemos crear un servidor malicioso el cual contenga el siguiente cuerpo:

```html
<iframe src="http://ruta-a-servidor-vulnerable/#" onload="this.src+='<img src=x onerror=alert(1)>'"></iframe>
```

Esto hará que se ejecute la otra pagina desde nuestro servidor y automaticamente se ejecute la vulnerabilidad, podemos hacer que una victima acceda a nuestro servidor y así vulnerar su acceso si robamos alguna cookie.