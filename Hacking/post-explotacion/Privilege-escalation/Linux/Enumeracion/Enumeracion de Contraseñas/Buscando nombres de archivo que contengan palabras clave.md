
Con este comando podremos ver todos los archivos que contengan una palabra clave en concreto, esto nos puede ayudar a encontrar contraseñas

```bash
locate password | more
```

## Busqueda de claves de SSH

Para buscar estas claves podemos usar las palabras clave id_name o authorized_keys

````zsh
find / -name id_name 2> /dev/null
````


Tambien es importante revisar si tenemos acceso a un determinado usuario para asi apoderarnos de la private key de este, incluyendo root.

Exploto esta vulnerabilidad en [[]]