diff es una herramienta que nos permite listar las diferencias que hay entre diferentes archivos, por ejemplo, digamos que tenemos dos archivos con 100 contraseñas, passwords.old y passwords.new, al archivo passwords.new, lo único que se cambio fue una contraseña, por lo tanto tendremos una contraseña unica que fue la que se cambio, para usar diff es de la siguiente manera:

```shell
diff passwords.old passwords.new
```

El resultado seria algo así:

```
42c42
< x2gLTTjFwMOhQ8oWNbMN362QKxfRqGlO
---
> ktfgBvpMzWKR5ENj26IbLGSblgUG9CzB
```

- "<" : Representa que esa linea se quitó

- ">" : Representa que esa linea fue agregada


