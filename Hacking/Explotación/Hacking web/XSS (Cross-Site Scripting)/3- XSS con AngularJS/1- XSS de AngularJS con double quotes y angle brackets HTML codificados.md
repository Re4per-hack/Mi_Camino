Esto pasa cuando se está usando el descontinuado  desde 2010 AngularJS, del cual se puede ejecutar código siempre que esté entre dobles llaves ( {{ }} ), pero no se puede ejecutar código así como: {{ alert(1) }}, ya que no funcionará, para hacer esto usaremos lo siguiente

```js
{{ $on.constructor('alert(1)') () }}
```





