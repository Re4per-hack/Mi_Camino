wget nos puede ayudar a interactuar con paginas web, y usarlas a nuestro beneficio de diferentes formas:

## Un conjunto de directorios expuestos

Seguramente alguna vez hayas visto una serie de directorios expuestos, que son una especie de carpetas y archivos web, bueno, pues podemos replicar esta rama de directorios en nuestro equipo con el siguiente comando:

```shell
wget --mirror -I {DesdeQueSubDirectorioDescargar} {URL}
```

Ejemplo:

```shell
wget --mirror -I .git https://example.com/
```

