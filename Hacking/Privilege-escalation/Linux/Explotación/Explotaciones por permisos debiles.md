En este caso suele ser muy común revisar los permisos del archivo /etc/shadow, el cual contiene las contraseñas hasheadas pero realmente esta seccion pretenda explotar todos los archivos que contengan permisos débiles, es decir, archivos con información delicada con permisos que no deberían tener, y la explotación de esto, hay casos especiales en los que hay scripts con permisos especiales, pero empecemos con archivos locales del sistema con información sensible. 

El archivo /etc/shadow contiene las contraseñas hasheadas, las cuales se puede desencriptar usando hascat con el siguiente comando:

````zsh
hashcat -a 0 -m 0 hash.txt /Path/to/wordlist/file
````

Voy a desglosar este comando

- hashcat: Herramienta para desencriptar hashes y recuperar contraseñas

- -a: Attack Mode

- 0: Modo de ataque: Straight (ataque de diccionario)

- -m: Modo de Desencriptación 

- 1800: Tipo de hash (para ver los tipos de hash disponibles visite la siguiente [pagina](https://hashcat.net/wiki/doku.php?id=example_hashes))

- hash.txt: Archivo que contiene el hash a crackear

- /Path/to/wordlist/file: Ruta de el wordlist

