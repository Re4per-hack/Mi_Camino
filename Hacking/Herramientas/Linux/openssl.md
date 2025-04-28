openssl es una herramienta relacionada a la criptografía, que además de ayudarnos a generar texto encriptado, claves privadas, etc, también  nos puede ayudar a establecer conexiones encriptadas, lo que podemos hacer de la siguiente manera:

```shell
openssl s_client -connect {IP}:{Puerto}
```

- s_client: Con este parámetro le indicamos que queremos actuar como clientes y conectarnos a un servidor de manera encriptada.

- connect: Con este parámetro le indicamos la dirección a la que queremos conectarnos.


