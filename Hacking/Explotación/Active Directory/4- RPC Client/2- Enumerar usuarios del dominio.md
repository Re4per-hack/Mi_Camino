Si tenemos las credenciales de cualquier usuario podemos usarlas para loguearnos mediante RPC al controlador de dominio (DC), esto nos permitirá enumerar los usuarios del dominio, y aun mas importante, las descripciones que estos pueden tener, esto se hace de esta manera ya que en muchos casos se suelen documentar credenciales o información delicada en estas descripciones, para loguearnos usaremos el comando rpcclient con la siguiente estructura:

``` ruby
rpcclient -U "{Nombre_dominio}\{usuario}%{contraseña}" {IP_DEL_DC}
```

Si queremos trabajar con la salida del comando podemos indicarle directamente a rpcclient el comando que queremos ejecutar, para esto podemos usar el parametro "-c ", ejecutaremos el comando 

