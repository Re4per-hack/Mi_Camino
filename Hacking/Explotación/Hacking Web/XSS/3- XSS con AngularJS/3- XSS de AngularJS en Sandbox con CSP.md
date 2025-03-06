CSP (Content Security Policy) esto es algo que viene de forma nativa en en AngularJS, e impide varios ataques, pero puede ser bypasseado de diferentes formas:

## CSP Básico

```html
<input id=x ng-focus=$event.composedPath()|orderBy:'(z=alert)(1)'>
```
## CSP estricto

