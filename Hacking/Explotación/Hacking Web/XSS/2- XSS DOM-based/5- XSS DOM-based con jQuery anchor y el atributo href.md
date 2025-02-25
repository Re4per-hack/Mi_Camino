Para empezar, ¿que es anchor?, anchor se refiere a la etiqueta \<a>, esta etiqueta es usada para hacer links, es decir, texto que lleva a una pagina web externa, a una parte de la propia web o un recurso, y el atributo href se refiere a el link al que lleva al usuario cuando se da click, un ejemplo de un uso normal de esta etiqueta seria el siguiente:

```html
<a href="http://google.com">
	Click aqui para ir a google
</a>
```

Bueno, pues con jQuery se puede cambiar este enlace, y digamos que hay alguna función la cual permite que el usuario pueda alterar el enlace, pero no se puede poner explícitamente código JavaScript, por lo que haremos algo un poco diferente.

Para esto tenemos que recordar como algunos protocolos se pueden llamar desde el navegador como si fueran URLs tradicionales, por ejemplo:

- ftp://
- file://
- data://

Y mas, bueno, pues ==hay uno que es javascript:{codigo JavaScript}== , este normalmente se podía usar desde el navegador para ejecutar código js directamente pero por razones de seguridad los navegadores ya no permiten realizar búsquedas cuando se usa este protocolo, en este caso la entrada de datos que tenemos como usuarios es el parámetro returnPath, entonces usaremos javascript:alert(1) y luego daremos click en donde esté el anchor que usa este href vulnerable   