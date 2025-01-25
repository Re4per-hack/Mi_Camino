ssh es una herramienta simple pero potente que nos permite conectarnos y tener control sobre otras maquinas que estén dentro o fuera de nuestra red, la diferencia con [[telnet]], es que ssh tiene un método de encriptación que mantiene seguros a los datos, mediante el uso de una clave privada y una clave publica, para conectarse a un servidor por ssh podemos hacerlo de la siguiente manera:

```shell
ssh {usuario}@{IP o Host}
```

En caso de que dispongamos de una clave privada podemos autenticarnos de la siguiente manera:

```shell
ssh -i {archivo_con_clave_privada}  {usuario}@{IP o Host}
```

## Crear claves publicas y pricadas en ssh

Para crear nuestras propias claves publicas y privadas en ssh usaremos el siguiente comando:

```shell
ssh-keygen
```

Esto nos creará una clave publica y una privada en la carpeta .ssh que está, la clave publica (id_rsa.pub) la guardaremos en la siguiente ruta:

```ruby
~/.ssh/
```