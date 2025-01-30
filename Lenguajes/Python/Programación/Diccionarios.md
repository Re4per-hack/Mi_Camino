Los diccionarios son un conjunto de datos de tipo clave:valor, esto quiere decir que solo existe una clave con un nombre único que puede contener distintos tipos de contenido, si se especifica alguna clave con el mismo nombre que una pasada, pues se sobrescribirá ese espacio, incluso no hay problema con repetir el valor de otras claves, siempre y cuando tenga una clave diferente:

```python
diccionario = {
	"Clave1":"Ejemplo_valor",
	"Clave2":"Ejemplo_valor",
	"Clave3":"Ejem_valo"	
}
```

Otra característica de los diccionarios es que a diferencia de otros lenguajes los valores pueden ser de diferentes valores:

```python
diccionario = {
    "Int":2
    "String":"asd",
    "Boolean":True
}
```

La forma en la que  se llaman a los valores de estos mapas es usando los corchetes "\[ \]":

```python
diccionario = {
    "Int":2
    "String":"asd",
    "Boolean":True
}

valor_String = diccionario["String"]
```

