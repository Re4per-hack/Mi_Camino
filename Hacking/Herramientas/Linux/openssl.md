Openssl es una herramienta relacionada a la criptografía, que además de ayudarnos a generar texto encriptado, claves privadas, etc, también  nos puede ayudar a establecer conexiones encriptadas, lo que podemos hacer de la siguiente manera:


### Extablecer conexión encriptada

```shell
openssl s_client -connect {IP}:{Puerto}
```

- s_client: Con este parámetro le indicamos que queremos actuar como clientes y conectarnos a un servidor de manera encriptada.

- connect: Con este parámetro le indicamos la dirección a la que queremos conectarnos.

## Error KeyUpdate 

```
-ign_eof
```


# Interactuar con archivos PFX

### Ver el contenido sin extraer nada:

```bash
openssl pkcs12 -in archivo.pfx -info -noout
```

### Extraer todo (clave + certificados) a un solo PEM:

```bash
openssl pkcs12 -in archivo.pfx -out todo.pem -nodes
```

- -nodes: No proteger la clave privada con encriptación. 

### Extraer solo la clave privada:

```bash
openssl pkcs12 -in archivo.pfx -nocerts -out clave.key -nodes
```

#### Extraer solo el certificado (sin la clave):

```bash
openssl pkcs12 -in archivo.pfx -clcerts -nokeys -out certificado.pem
```

#### Extraer la cadena de CAs intermedias:

```bash
openssl pkcs12 -in archivo.pfx -cacerts -nokeys -out cadena_ca.pem
```

En cada comando te pedirá la contraseña de importación del PFX de forma interactiva.

- **Error típico con OpenSSL 3.x**: si el PFX es antiguo (generado por Windows viejos o Java), puede usar algoritmos legacy como RC2 y verás un error tipo `unsupported algorithm`. La solución es agregar `-legacy`:

bash

```bash
openssl pkcs12 -in archivo.pfx -out todo.pem -nodes -legacy
```