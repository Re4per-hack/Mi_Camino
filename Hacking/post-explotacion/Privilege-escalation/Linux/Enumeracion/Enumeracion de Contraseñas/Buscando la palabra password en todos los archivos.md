Este comando nos permite buscar palabras clave en todos los archivos del sistema partiendo de la raiz ("/"), por ejemplo:

```bash
grep --color=auto -rnw '/' -ie "PASSWORD=" --color=always 2> /ev/null
```

