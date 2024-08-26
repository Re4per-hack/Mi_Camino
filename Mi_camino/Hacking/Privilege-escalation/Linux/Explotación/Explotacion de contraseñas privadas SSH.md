Cuando estamos por un sistema y ejecutamos la enumeracion que enseño en: [[Buscando nombres de archivo que contengan palabras clave]], sí tenemos la suerte de encontrarnos con contraseñas ssh privadas eso nos sera extremadamente util, y ya te mostraré porque:


Esto es sumamente util porque si esta maquina tiene el servicio ssh abierto (lo cual es lo mas probable) significa que podremos identificarnos con esta clave, ¿Pero como?:

- Lo primero que debemos hacer es crear un archivo en el que guardemos la calve privada 

- ¡¡¡¡IMPORTANTE!!!!: recuerda guardar TODA la clave en el archivo, esto incluye la parte que no está hasheada como tal, por ejemplo "-------END OPENSSH PRIVATE KEY-------" (tambien la parte de inicio)

- Ahora con este archivo tenemos que darle permisos re lectura y escritura:

```bash
sudo chmod 600 {Nombre_archivo}
```

- Y ahora por ultimo nos logueamos usando esta clave:

```bash
ssh -i {Archivo_con_la_key} {usuario}@{IP_a_conectarse}
```

