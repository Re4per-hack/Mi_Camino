awk es un lenguaje de programación basado en la administración de datos en forma de texto. 


## Filtrar texto

Podemos usar awk para filtrar, así como lo hacemos con grep, digamos que tenemos un archivo con varios nombres y sus respectivas edades:

```
Juan - 17 años
Pablo - 13 años
Silvia - 17 años
Margarita - 30 años
Steven - 20 años
Eddy - 17 años
```


```shell
awk '/17/' nombres.txt
```

Esto nos daría como resultado:

```
Juan - 17 años
Silvia - 17 años
Eddy - 17 años
```
## Recortar texto

Podemos recortar el texto usando los espacios, siguiendo con el ejemplo anterior podemos mostrar únicamente los nombres, ejemplo:

``` shell
awk '/17/' nombres.txt | awk '{print $1}'
```

El resultado seria:

```
Juan
Silvia
Eddy
```

Lo que pasa aquí es que los valores devueltos se tratan como  [[4- Argumentos]], por lo tanto se pueden manejar como variables.

## Mostrar únicamente el ultimo elemento de la linea

Para demostrar el ultimo elemento de cada linea nos basta con hacer lo siguiente, sigueindo  con el ejemplo anterior: 

``` shell
awk '/17/' nombres.txt | awk 'NF{print $NF}'
```

El resultado seria:

```
años
años
años
```

## Mostrar una linea especifica

Para mostrar una linea especifica usando awk usaremos lo siguiente, siguiendo con el ejemplo principal:

``` shell
awk '/17/' nombres.txt | awk 'NR==3'
```

```shell
Eddy - 17 años
```




