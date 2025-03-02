En JavaScript hay varias formas de declarar una string, una forma de estas de literal templae, el cual se hace con tildes invertidas (\` \`), esto ahce que todo el texto que se ponga dentrod e esto se interprete de forma literal:

```js
var string_normal = "hola"
var literal_string = `hola que tal
soy un texto
${string_normal}
`
```

Esta interpretación literal detecta saltos de linea, tabulaciones y se pueden insertar variables directamente, además se pueden inyectar comandos, por lo que el payload quedaría algo así:

```js
${alert(1)}
```
