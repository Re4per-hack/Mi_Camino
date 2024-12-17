Cuando miramos los permisos de un archivo en linux, al principio de la linea veremos la sección de los permisos, hay mas información cuando vemos un archivo en Linux, pero la omitiré para hacer esto mas didactico, en fin, en la parte de los permisos veremos algo como esto:

	-rwxr--r-x juan juan test.txt

Como puedes ver  en la primera parte hay un conjunto de letras y guiones, esto pueede parecer confuso, pero es mucho mas simple de lo que piensas, para hacerlo mas comprensible lo voy a divodir en 4 secciones:

	|-|rwx|r--|r-x juan juan test.txt

Estos datos se dividen en 4 secciones, la primera indica el tipo de archivo, siendo "-" un archivo normal y "d" un directorio (una carpeta), la segunda sección representa los permisos que tiene el creador del archivo, la letra  "r" representa permisos de lectura, la letra "w" representa permisos de escritura y la letra "x" representa permisos de ejecución, esto se aplica para las demas secciones, en la tercera seccion se representan los permisos del grupo  de archivos, y la cuarta seccion representa los permisos de "World" o "todo el mundo".

El usuario que aparece primero es el creador del archivo, y el segundo es el grupo dueño del archivo.




