Las etiquetas custom pueden tener el nombre que uno quiera, siempre y cuando no tengan el nombre de una etiqueta ya existente, para este ejemplo mi etiqueta custom se llamará \<xss>, esta vulnerabilidad suele surgir cuando  se están filtrando todas las etiquetas existentes, por lo que tendremos que jugar con estas customizadas, el payload en total es el siguiente:


```html
<xss tabindex="1" onfocus="alert(1)" id="x">
```

## Atributos:

- tabindex: Este atributo define si la etiqueta puede ser enfocada, además de si se puede tabular, esto es importante para que funcione el atributo onfocus.

- onfocus: Este atributo define que pasará si la etiqueta está enfocada ( en el foco )

- id: este atributo es el indicativo de la etiqueta y nos ayudará a hacer que se enfoque inmediatamente cuando la victima entre con la url dada usando un hashtag, ejemplo:

```python
http://paginavulnerable/#x
```



