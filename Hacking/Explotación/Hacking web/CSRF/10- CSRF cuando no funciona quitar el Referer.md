En este caso, quitando el Referer, como hicimos en el anterior documento ( [[9- CSRF cuando la validacion del referer depende de si está siendo presentado]]), podemos ver que no funciona, por lo que tendremos que jugar un poco con el valor de este referer, ya que tal vez siempre que el referer contenga la URL lo pasará como valido, entonces intentemos esto, el exploit seria el mismo que en [[2- Cuando no hay protecciones CSRF]], para poder hacer que la URL destino aparezca en el referer podremos usar pushState, con el siguiente ejemplo se entenderá mejor:

Nuestro servidor como atacantes seria http://explopit-server/exploit, y el dominio de la pagina con la que vamos a cometer el CSRF seria www.victima.com, por lo que podemos hacer que el referer quede algo como: http://exploit-server/exploit?www.victima.com, ¿pero como?, para esto podemos usar history.pushState("","","?www.victima.com"), esto haría que se cambie la url sin que se recargue la pagina, el exploit quedaría algo así:

```html
<form method="POST" action="https://URL/">
	<input type="hidden" name="email" value="newmail@pwned.com"/>
</form>

<script>
	history.pushState("","","?www.victima.com")
	document.forms[0].submit();
</script>
```

