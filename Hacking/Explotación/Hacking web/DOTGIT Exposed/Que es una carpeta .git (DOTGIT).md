como se puede leer en el titulo de esta vulnerabilidad, esto ocurre cuando hay una carpeta llamada .git expuesta, esas carpetas son remanentes de proyectos de GitHub, lo cual significa que pueden contener información sensible, en este caos especifico esta carepeta está expuesta en una pagina web, como lo podemos identificar?, bueno, pues si cuando vamos al directorio .git en una URL nos da un resultado, especialmente una carpeta con información, si confirmamos que existe esta carpeta podemos descargarnos este .git a nuestro equipo, ¿Pero como?, usando el siguiente comando:

```shell
wget --mirror -I .git http://example.com/.git
```

