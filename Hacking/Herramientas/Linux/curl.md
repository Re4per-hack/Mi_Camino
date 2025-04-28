curl es una herramienta que nos permite hacer llamadas a URL's
## Ver las cabeceras de una consulta con curl

Para ver las cabeceras o los headers de un request con python podremos usar el parámetro --head:

```bash
curl --head {URL}
```
## Evitar modificaciones

Cuando queremos ejecutar payloads que requieres varios "../" en la URL, curl suele eliminarlos, es decir, modificar la URL, para evitar que curl modifique la URL usaremos:

```bash
curl --path-as-is {URL}
```



