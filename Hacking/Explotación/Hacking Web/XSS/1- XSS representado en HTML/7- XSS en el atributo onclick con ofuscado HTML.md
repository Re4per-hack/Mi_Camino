Esta inyección sucede cuando el XSS se inyecta dentro de un script JavaScript que está dentro del atributo onclick, en este caso todos los caracteres especiales están siendo ofuscados (", ', \\, <, >, etc...), para bypassear está medida de seguridad haremos uso de una entidad que representa a una comilla simple, así cuando sea interpretado por el navegador e tomará como una comilla simple, el payload quedaria algo así:

```js
&apos;-alert(1)-&apos;
```


