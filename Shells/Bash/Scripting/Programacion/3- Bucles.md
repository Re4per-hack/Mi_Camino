Los bucles sirven para ejecutar una porción de código la cantidad de veces que sea necesario, hay 3 tipos de bucles en Bash, bucles for, bucles while y bucles until, empezaré hablando sobre los bucles for:

# Bucle for 

Para definir la cantidad de veces que se va a ejecutar una porción de código con un bucle for se suelen usar listas con las cuales se pasa sobre cada ítem, también se pueden usar rangos de números, como del 1 al 10, por dar un ejemplo:

### Bucle for con rangos numericos


```shell
#!/bin/bash

for  i in {1..50} 
do
	echo "Esta porcion de codigo se ha ejecutado $i veces"
done
```

### Bucle for con una lista

```shell
#!/bin/bash

lista=(item1 item2 item3 item4)

for  i in ${lista[@]}
do
	echo "Esta porcion de codigo se ha ejecutado $i veces"
done
```

# Bucle while

Con el bucle while, el código se va a seguir repitiendo siempre y cuando se cumpla la condicion definida:

```shell
#!/bin/bash

variable=2
while [[ $variable -eq 2 ]]
do
	echo "Esto se va a dejar de ejecutar hasta que variable deje de ser 2"
done
```

También se puede hacer run bucle infinito usando un valor booleano:

```shell
#!/bin/bash

while true
do
	echo "Esto se va a dejar de ejecutar hasta que variable deje de ser 2"
done
```

# Bucle until

El bucle until es similar que el bucle while, solo que este bucle solo se ejecutara siempre y cuando la condición sea incorrecta, es decir, se ejecutara hasta que la condición sea correcta, aquí un ejemplo:

```shell
#!/bin/bash

variable=2

until [[ variable -eq 3 ]]
do
	echo "Esta porcion de codigo sera ejecutada hasta que variable sea igual a 3"
done
```

