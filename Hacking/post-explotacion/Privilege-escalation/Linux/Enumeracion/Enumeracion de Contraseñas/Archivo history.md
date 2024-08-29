El comando "history" muestra todo el historial de comandos que el usuario ha ejecutado, si, DEL USUARIO, mas no de la sesión como tal, esto nos puede ayudar a conseguir contraseñas o datos delicados de diferentes usarios en el sistema, o simplemente de la elevacion de privilegios de un usuario que lo haya hecho anteriormente, un gran ejemplo de esto es cuando se accede a una base de datos de la siguiente forma: 


```bash
$> history

respuesta:
mysql -uroot -ppassword123
```


Aqui se muestra una contraseña, la cual si se repite mas de una vez se puede usar con otros usuarios del sistema

Pero como se puede ver en el titulo, esto se trata de un archivo, no solo de un  comando, pues este comando, en esencia, solo le hace un cat (muestra la informacion) de el archivo /home/{USER}/.{SHELL}\_history

Por ejemplo:

	/home/juan/.bash_history

O:

	/home/juan/.zsh_history

Etc...

