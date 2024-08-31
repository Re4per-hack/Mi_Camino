Esto a simple vista puede parecer inútil, pero es sumamente importante para poder realizar un ataque UNION, el cual veremos en [3- Ataques UNION](3-%20Ataques%20UNION.md), pero por ahora veremos como descubrir la cantidad de columnas que llama la consulta, es importante hacer énfasis en "que llama la consulta", ya que esta técnica no descubre la cantidad de columnas totales de una tabla, solo las que son llamadas, es diferente llamar dos: 

(En el siguiente ejemplo la tabla contiene 3 columnas: price, description, category )

```Mysql
SELECT price,description FROM productos WHERE category = 'Gifs'
```

Que llamar a todos:

```Mysql
SELECT * FROM productos WHERE category = 'Gifs'
```

Ya con esta idea simple entendida, podemos pasar a descubrir la cantidad de columnas, la mayoría de bases de datos cuentan con la palabra clave "ORDER" la cual como ya te imaginaras, ordena las columnas, pero lo que nos interesa es usar "ORBER BY", en este caso, en vez de tener que especificar que columna queremos ordenar, podemos indicarlo con números:

```mysql
' ORDER BY 1-- 
' ORDER BY 2--
' ORDER BY 3--
etc...
```

En el caso de arriba es como se usaría para conocer La cantidad de columnas, simplemente hay que encontrar el input que es vulnerable a SQLi e ir poniendo ORDER BY 2-- -, y si no da error ORDER BY 3-- -, y asi sucesivamente, el momento en el que de error es porque no se encontró esa cantidad de columnas, por lo tanto, sí dio error "ORDER BY 4-- -" es porque hay 3 columnas, y asi de simple se hace esta comprobación.