xdd es una herramienta que nos permite transformar un archivo en su forma hexadecimal, también permite hacer lo contrario, convertir un código hexadecimal al binario original: 

``` shell
cat archivo.txt | xxd // Convertir el contenido de un archivo a hexadecimal 
cat hexadecimal.hex | xdd -r // Pasar el hexadecimal a archivo
```

Si se quiere mostrar solamente el código hexadecimal se puede usar el parámetro -ps: 

``` shell 
cat archivo.txt | xxd -ps 
```

