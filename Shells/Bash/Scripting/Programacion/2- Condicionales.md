Los condicionales nos permiten ejecutar un código u otro dependiendo de si se cumple una sentencia, para ello se usan comparaciones (Mayor que, Menor que, Igual que), para hacer estas comparaciones varia según si se compara texto o números, esto pasa sobre todo en Bash, aquí se ve de forma mas clara:

![[Pasted image 20250108215700.png]]

Ya que tenemos una idea sobre como hacer estos dos tipos de comparaciones a continuación hay un ejemplo:
### Comparación de Texto

``` shell
variable="Hola"

if [[ $variable == "Hola" ]]
then
    echo "la variable es Hola"
else
	echo "la variable no es Hola"
fi
```

### Comparación de números

```shell
variable=2

if [[ $variable -eq 2 ]]
then
    echo "el valor de la variable es 2"
else
	echo "el valor de la variable no es 2"
fi
```

También se pueden usar valores booleanos, ya sea almacenados por variables o puestos directamente

```shell
variable=true

if variable
then
	echo "la variable tiene un valor verdadero"
else
	echo "la variable tiene un valor falso"
fi
```