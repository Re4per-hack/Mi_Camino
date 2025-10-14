
El comando grep nos permite obtener informacion especifica de la salida de un comando, se suele usar sobre todo junto a las pipes, las cuales son una forma de redirigir el stdin en bash, para mas información sobre las salidas de datos visite [[2- Salidas de datos]], para mas información sobre las pipes, visite [[3- Redireccion en bash]], un ejemplo del uso de grep puede ser el siguiente, digamos que tenemos un archivo con varios nombres y sus respectivas edades:

```
Juan - 17 años
Pablo - 13 años
Silvia - 17 años
Margarita - 30 años
Steven - 20 años
Eddy - 17 años
```

Grep nos puede ayudar a encontrar los nombres que tienen 17 años, en este caso no se van a usar pipes y a que no es necesario, ejemplo:

```shell
grep "17" nombres.txt
```

El resultado seria:

```
Juan - 17
Silvia - 17 
Eddy - 17
```

## Mostrar el numero de la linea

Para mostrar el numero de la linea usando grep, es tan simple como usar el parmetro -n:

```shell
grep -n "17" nombres.txt 
```

El resultado seria:

```
1:Juan - 17
3:Silvia - 17 
6:Eddy - 17
```

## Mostrar líneas de arriba/Mostrar líneas de abajo

Se puede recordar este parametro por las palabras que los representan en ingles (Above/abajo) o (Below/arriba)
### Mostrar líneas abajo de (Above):

```shell
grep -A 2 "Juan" nombres.txt 
```

El resultado seria:

```
Juan - 17 años
Pablo - 13 años
Silvia - 17 años
```
### Mostrar líneas arriba de (Below):

```shell
grep -B 2 "Margarita" nombres.txt 
```

El resultado seria:

```
Pablo - 13 años
Silvia - 17 años
Margarita - 30 años
```

## Mostrar lineas abajo y arriba de: 


```shell
grep -C 2 "Margarita" nombres.txt 
```

El resultado seria:

```
Pablo - 13 años
Silvia - 17 años
Margarita - 30 años
Steven - 20 años
Eddy - 17 años
```


## NO mostrar cierta linea (efecto contrario)

En caso de que tengamos algun archivo en el que queremos que no nos muestre una linea con cierto criterio podemos hacer uso del parametro -v de grep, para este caso usare de ejemplo lo mismo de antes:

```
Juan - 17 años
Pablo - 13 años
Silvia - 17 años
Margarita - 30 años
Steven - 20 años
Eddy - 17 años
```

En este caso digamos que no queremos mostrar las personas con 17 años:

```shell
grep -v "17 años" nombres.txt
```

El resultado seria el siguiente: 

```
Pablo - 13 años
Margarita - 30 años
Steven - 20 años
```


# Solo mostrar las coincidencias 

En caso de que tengamos algun archivo en el que queremos que no nos muestre una linea completa, sino únicamente la coincidencia para esto usaremos el parametro -o:

```
Juan - 17 años
Pablo - 13 años
Silvia - 17 años
Margarita - 30 años
Steven - 20 años
Eddy - 17 años
```

En este caso digamos que solo queremos que se resalten los "Pablo" en el texto, pero no la linea completa, en un caso normal se vería algo así:

```shell
grep "Pablo" nombres.txt
```

El resultado seria el siguiente: 

```
Pablo - 13 años
```

Pero con la opción se vería algo así:


```shell
grep -o "Pablo" nombres.txt
```

El resultado seria el siguiente: 

```
Pablo
```


# Buscar palabra especifica en diferentes archivos

Esto es util cuando queremos filtrar por  palabras especificas en diferentes archivos

```bash
grep -rnw / -ie "PASSWORD" 
```

- -r: IMPORTANTE, para que busque dentro de carpetas de forma recursiva

- -n: Para que muestre la linea en la uqe se encuentra esa coincidencia 

- -w: Para que solo Matchee con palabras es decir, PASSWORDXD no lo va a agarrar, en cambio PASSWORD si 

# Filtrar por expresiones regulares


```
Juan - 17 años
Pablo - 13 años
[Silvia] - 17 años
[Margarita] - 30 años
Steven - 20 años
Eddy - 17 años
```

En este caso digamos que solo queremos filtrar por el contenido que está entre Corchetes (\[ ]):

```shell
grep -P "\[.+?\]" nombres.txt
```

El resultado seria el siguiente: 

```
[Silvia] - 17 años
[Margarita] - 30 años
```

## Filtrar con multiple matching 


# Evitar distinción entre Mayúsculas y Minúsculas

Para esto vamos a usar la opción -i, para este ejercicio tendremos el siguiente ejemplo

