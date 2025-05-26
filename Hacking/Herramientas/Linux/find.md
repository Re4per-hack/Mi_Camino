find , como dice el nombre, es un comando que nos permite encontrar archivos y carpetas, lo interesante es que nos permite especificar varios parámetros, si no se le da ningún parametro va a mostrar todos los archivos desde el directorio actual en adelante, si se le indica una ruta va a mostrar desde allí:

``` shell
find {ruta_desde_donde_buscar}
```

## Buscar solo archivos o carpetas

```shell
find {ruta_desde_donde_buscar} -type f // En caso de querer buscar un archivo
```

## Buscar por los permisos

```shell
find -readable // Mostrar archivos con permisos de lectura
find -executable // Mostrar archivos con permisos de ejecucion
find -writable // Mostrar archivos con permisos de escritura
```

En Bash, para indicar lo contrario a lo que hace el parámetro, por ejemplo:

```shell
find ! -readable // Mostrar archivos sin permisos de lectura
find ! -executable // Mostrar archivos sin permisos de ejecucion
find ! -writable // Mostrar archivos sin permisos de escritura
```

## Buscar por archivos con un peso especifico

```shell
find -size 1000c // Tamaño en bytes
find -size 1000k // Tamaño en kilobytes
find -size 1000M // Tamaño en Megabytes
find -size 1000G // Tamaño en Gigabytes
```


Buscar por propietarios