Esta vulnerabilidad se presenta cuando una pagina representa contenido que pueda alterar el usuario pero que no es guardado como tal, por ejemplo, una pagina con una barra de busqueda y que abajo aparezca lo que se buscó, ya que eso se está representando en el HTML podemos inyectar algo como esto:

```html
<script>alert(1)</script>
```

Esto es un método para probar si se puede inyectar código js, si cuando se cargue la pagina aparece un pop-up, efectivamente la pagina es vulnerable