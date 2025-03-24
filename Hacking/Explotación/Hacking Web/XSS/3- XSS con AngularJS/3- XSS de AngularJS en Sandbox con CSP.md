CSP (Content Security Policy) esto es algo que viene de forma nativa en AngularJS, e impide varios ataques, pero puede ser bypasseado de diferentes formas, estas politicas las podemos ver reflejadas en los headers de las respuestas del servidor:

## CSP Básico

```html
<input id=x ng-focus=$event.composedPath()|orderBy:'(z=alert)(1)'>
```
## CSP estricto



