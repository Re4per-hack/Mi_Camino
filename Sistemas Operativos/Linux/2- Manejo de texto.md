Para manejar texto podemos usar diferentes herramientas con sus diferentes parámetros, en caso de grep, es una herramienta para filtrar texto y a continuación están sus funciones:

## Filtrar por líneas que contengan algo en ellas

En este caso grep se usa sin argumentos y se pasa la palabra de donde queremos que se resalten las lineas:

```bash
echo "hola como estas está todo Bien ? \ntodo bien y tu?\n yo tambien" | grep  "bien"
```

- En este caso solo se va a mostrar "todo bien y tu?" y "Bien también",  la primera linea no porque la "B" está en mayúscula
## Expresiones regulares

Para indicarle a grep que queremos usar una expresion regular usamos el parametro -oP, para entender como funcionan las expresiones regulares mirar el archivo [Expresiones Regulares](3-%20Expresiones%20regulares)

```bash
echo "hola como estas está todo Bien ? \ntodo bien y tu?\n yo tambien" | grep -oP "bien"
```


