Esta vulnerabilidad surge cuando javascript usa document.write, esto sirve para escribir directamente en el documento, por ejemplo el siguiente codigo:

```js
function trackSearch(query) {
                            document.write('<img src="/resources/images/tracker.gif?searchTerms='+query+'">');
                        }
                        var query = (new URLSearchParams(window.location.search)).get('search');
                        if(query) {
                            trackSearch(query);
                        }
```

Estos scripts se pueden ver inspeccionando la pagina.

Como se puede ver JavaScript está escribiendo "\<img src="/resources/images/tracker.gif?searchTerms='+query+'">" directamente en el documento HTML, donde query es igual al valor del parámetro search. Una inyección que podríamos hacer aquí es la siguiente:

```html
"><script>alert(1)</script>
```

Para desglosar esto, las primeras comillas dobles, junto con el (>) cierran la etiqueta img que se escribiendo por el document.write, y a partir de ahí podemos escribir nuestro script, respecto a lo que queda sobrando de lo que escribe el document.write se toma como texto



