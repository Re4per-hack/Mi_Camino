
Muchas veces cuando descargamos un archivo, el archivo a descargar se indica a travez de algun parametro, podemos testear un posible LFI o Path traversal, usualmente podemos usar la siguiente carga util:

```ruby
../../../../../../../../etc/passwd
```

En caso de que obtengamos el /etc/passwd, revisar el siguiente cocumento: [[Testeo de Path traversal]]
