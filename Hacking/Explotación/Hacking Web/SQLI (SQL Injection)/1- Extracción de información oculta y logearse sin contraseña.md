## Datos ocultos

En este tipo de vulnerabilidad SQLi se pueden ver algunos datos que la base de datos filtra mediante la consulta, la cual puede ser algo asi:

```mysql
SELECT * FROM products WHERE category = 'Gifts' AND released = 1
```

Donde "released" es el estado de la publicación, publico siendo 1, por lo tanto la consulta llama a todos los productos que tengan el estado 1 y pertenezcan a la categoria de "Gifts", el Payload correspondiente para este tipo de vulnerabilidad seria algo semejante a esto:

```mysql
SELECT * FROM products WHERE category = 'Gifts' OR 1=1-- -' AND released = 1
```

La primera comilla sirve para cerrar la comilla anterior y luego la sentencia " OR 1=1" al ser verdadera, hace que la categoria no se tome en cuenta y los guiones que estan despues sirven para comentar " ' AND released = 1", haciendo que no se interprente la comilla restante, ni el estado de la publicación, tambien se podria poner solo lo siguiente

```mysql
SELECT * FROM products WHERE category = 'Gifts'-- -' AND released = 1
```

Pero esto solo haria que se presenten todos los productos en la categoria seleccionada, el problema es que la idea es ver todos los datos, si, esto ayudaria a ver mas productos de lo normal, pero no todo lo que neesitamos, en cambio a usar " ' OR 1=1-- -" no se interpretaran ninguna de las sentencias

## Login sin contraseña

En este caso la vulnerabilidad SQLi se presenta en un login, para este caso la consulta normalmente seria: 

```mysql
SELECT * FROM Users WHERE username = 'Usuario_ingresado' AND pass = 'Contraseña_ingresada'
```

En este caso la base de datos busca en la columna username el usuario ingresado, y si la contraseña que tiene la base de datos no es la misma que la ingresada pues enviara una respuesta con valor False, lo que significa que no encontró el usuario especificado con la contraseña especificada, y pues si el valor es True es porque si coincidieron.

Para poder entrar en determinado usuario sin la contraseña, digamos "administrator", tendriamos que hacer lo siguiente.

```mysql
SELECT * FROM Users WHERE username = 'administrador'-- -' AND pass = 'Contraseña_ingresada'
```

De parte del usuario se vería algo como "administrator'-- -", aquí lo que estamos haciendo es comentar la parte de la consulta donde se llama a la tabla "pass", por lo tanto con tal de exista el usuario "administrator" la base de datos enviara un valor True, y esto nos permitiría entrar en la cuenta de ese usuario.

Pero hay otra forma, y es usándolo "OR 1=1-- -", si, el que aprendimos anteriormente, normalmente esto daría error, pero no sobra probarlo, ya que esto nos puede dar acceso a la información de todos los usuarios.










