- Podemos usar el siguiente comando para conocer el identificador del usuario en el que estamos actualmente:

	id

- En cambio si queremos listar todos los usuarios podemos usar el archivo /etc/passwd de la siguiente manera:

	cat /etc/passwd | cut -d : -f 1

- El comando "cut" determina un delimitador y a partir de este podemos elegir secciones del texto que nos sean utiles, en este caso es ":" y se elige la primera seccion (recomiento ver como es el archivo "/etc/passwd" para entenderlo mejor y experimentar con este comando)

- El archivo "/etc/group" muestra informacion de los grupos con la siguiente estructura

1:2:3:4

1- Nombre Grupo
2- Contraseña(no usado)
3-Id del grupo (GID)
4-Usuarios que pertenecen a ese grupo