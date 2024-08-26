
Como se vio en [[Explotando escapado de Shell con sudo]], hay algunos comandos que aunque tengan permisos de ejecución con sudo sin proporcionar una contraseña, hay muchos otros que no, pero que sin embargo, por funcionalidades de ese comando podemos visualizar archivos que nos hagan escalar de privilegios, como puede ser /etc/shadow o algun archivo personalizado del sistema, algunos de ellos pueden ser apache2, wget u otros, y los iré agregando cada que los encuentre, pero por ahora empezare con apache2:

En el caso de apache2, tiene una funcionalidad que para definir la configuración pide un archivo, bueno, pues si le pasamos un archivo que no contiene la configuración, nos mostrara un error, en el cual representara la primera linea del archivo, aqui un ejemplo practico:

Comando:

```bash
sudo apache2 -f /etc/shadow
```

Respuesta:

```bash
Syntax error on line 1 of /etc/shadow:
Invalid command 'root:$6$bxwJfzor$MUhUWO0MUgdkWfPPEydqgZpm.YtPMI/gaM4lVqhP21LFNWmSJ821kvJnIyoODYtBh.SF9aR7ciQBRCcw5bgjX0:17298:0:99999:7:::', perhaps misspelled or defined by a module not included in the server configuration
```

Como pueden ver, es algo bastante util, ahora conseguiremos esta información pero ahora usando wget:

