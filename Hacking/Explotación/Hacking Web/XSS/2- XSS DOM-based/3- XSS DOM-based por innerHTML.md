En este caso también un script en java se encarga de poner el valor de un parámetro de la url en el documento HTML, pero esta vez lo pone de forma normal, lo que podría hacernos pensar que podemos hacer la típica inyección:

```html
<script>alert(1)</script>
```

Pero esto no funcionaria ya que los navegadores modernos no ejecutan scripts inyectados por innerHTML, pero como una alternativa podemos ejecutar codigo JavaScript con una imagen y asì bypassear esta medida de seguridad, la forma seria la siguiente:

```html
<img src="ImagenInexistente" onerror=alert(1)>
```



