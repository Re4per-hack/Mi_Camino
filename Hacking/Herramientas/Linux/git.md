
git es una herramienta que nos permitirá interactuar con repositorios de github.

# Instalar repositorios

Podemos clonar un repositorio usando clone:

```shell
git clone https://github.com/usuario/repositorio
```

# Revisar commits existentes de un repositorio

En Github un repositorio puede ser actualizado/cambiado, a estas actualizaciones se les conocen como commits, y podemos ver estos commits con sus respectivos cambios usando el siguiente comando:

## Para revisar los commits existentes

```shell
git log 
```

## Para cambiar de comit

```shell
git checkout  {commit}
```

# Revisar contenido de diferentes branchs

En github, una branch se refiere a una rama del mismo repositorio, esto se puede entender mas como que un mismo repositorio puede tomar diferentes caminos, y estos caminos se les conocen como branch, de forma predeterminada el branch se llama main.

## Para ver el branch actual

```shell
git branch
```

## Para ver los branchs disponibles

```shell
git branch -r
```

## Cambiar de branch

Cambiar de branch hará que el repositorio no vaya por el camino/branch main, sino por el branch indicado, es decir, es probable que muchos archivos sean diferentes:

```shell
git checkout {Branch}
```


# Para ver etiquetas disponibles

```shell
git tag
```

## Para ver una etiqueta

```shell
git show {etiqueta}
```

## Hacer un push a un repositorio

Añadir archivo a la lista de cambios:

```shell
git add {FILE}
```

Crear commit:

```shell
git commit -m "{titulo}"
```

Hacer Push:

```shell
git push -u origin master
```



