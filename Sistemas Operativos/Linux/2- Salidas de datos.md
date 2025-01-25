Hay 3 tipos de salidas de datos, salidas estandar (stdout) , salidas para los errores (stderr) y las entradas estandar (stdin), cada uno de estos es representado por un numero en Bash:

```ruby
stdin - 0
stdout - 1
stderr - 2
```

Esto nos puede ayudar a eliminar las representaciones en terminal de los errores, o procesos que no fueron completados exitosamente, como falta de permisos, archivos no encontrados, operaciones imposibles, etc...

Para hacer esto solo tenemos que redirigir los errores a una ruta en el sistema que elimina todo lo que se envie allí , esta ruta es /dev/null, para redirigir esto solo tenemos que hacerlo de la siguiente manera:

``` ruby
{comando} 2>/dev/null
```

