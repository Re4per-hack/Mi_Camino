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

# Extraer información de la base de datos

### En bases de datos PostgreSQL, MySQL y MicrosoftSQL

Ya con la idea de como se extrae información  en un entorno de SQLi, en donde ya hay una cantidad  de columnas llamadas y tenemos que acomodarnos a ella, será fácil explicar como extraer información de la base de datos, solo hace falta que entendamos como cuales son las tablas que nos dan información privilegiada, esto lo documento [Aquí](/Hacking/Explotación/Hacking%20Web/SQLI%20(SQL%20Injection)/Hoja%20de%20trucos%20SQLi###Información%20de%20columnas)


Usaremos la tabla information_schema.columns, ya que contiene los nombres de tablas y columnas existentes en la base de datos, en este caso la vulnerabilidad se presenta en el llamado a una serie de textos, después de determinar la cantidad de columnas podremos saber cuantos datos podremos mostrar, en este caso son 2 columnas, normalmente la URL es asi:

```python
https://{Vulnerablepage}/filter?category=Gifs
```

Entonces hice lo siguiente:

```Mysql
https://{Vulnerablepage}/filter?category=Gifs' UNION SELECT column_name,table_name FROM information_schema.columns-- -
```

Esto me dio como resultado un montón de columnas con sus respectivas tablas, entonces filtré por "username" y "password" y asi montón las columnas y tablas correspondientes a el usuario del que tenia que conseguir la contraseña, en este caso "administrator"

```Mysql
https://{Vulnerablepage}/filter?category=Gifs' UNION SELECT usernames_xkuj, passwords_lhia FROM users_lkasf -- -
```

### En bases de datos Oracle

En el caso de Oracle la cosa no cambia mucho, únicamente como se llaman las tablas que contienen información, estas tablas y sus respectivas columnas están en [Aquí](/Hacking/Explotación/Hacking%20Web/SQLI%20(SQL%20Injection)/Hoja%20de%20trucos%20SQLi###Información%20de%20columnas####Oracle)
