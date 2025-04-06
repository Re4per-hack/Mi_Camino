
En caso de que solo sea permitida la etiqueta \<svg> se puede combinar con la etiqueta \<animatetransfor> y para estas dos etiquetas hay un atributo que nos puede ayudar a ejecutar código JavaScript, este atributo es ==onbegin==, este atributo sirve para que apenas se inicia la animación:

```html
<svg><animatetransfor onbegin="alert(1)">
```