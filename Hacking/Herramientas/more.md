More es un comando que nos permite leer archivos, cuando un archivo es demasiado grande para ser mostrado completo en la terminal, more lo "pagina" es decir, te lo separa en parte spara que puedas ver completo usando las flechas del teclado, el caso es que con more podemos spawnear alguna shell o leer otros archivos:

## Leer otros archivos dentro de more

Para esto tendremos que estar en modo lectura, sabes que estas en modo lectura si no puedes editar el archivo, ahora hay que presionar "v", apartir de ahora podemos ejecutar acciones, para ejecutar estas acciones usaremos escribiremos dos puntos (":") y escribiremos lo sigiente

```shell
:e /archivo/que/quieras/leer
```

# Spawnear una bash

El proceso es igual que antes pero ahora vamos a escribir:

```
:set shell=/bin/bash
```

Y luego:

```
:shell
```


