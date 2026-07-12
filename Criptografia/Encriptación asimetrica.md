En la encriptación asimetrica tenemos 2 elementos, la llave publica y la llave privada, y estas se pueden usar tanto para firmar datos (Mantener integridad), como para encriptarlos (Mantener confidencialidad), esto se logra dependiendo con que se encripte y como funcione, usualmente de la siguiente forma:


### Encriptación 

Para encriptar un dato se usa la llave publica que funciona como una especie de candado, cuanto tu encriptas algo con una llave publica solo puede ser desencriptado por la llave privada.

Esto permite que solo el propietario de la llave privada pueda ver el contenido.

### Firma

En caso de la firma se usa la llave privada para encriptar los datos, claro que cualquiera puede usar la llave publica para desencriptarlo pero el objetivo de la forma es verificar que ese dato proviene de quien tiene esa llave privada. 