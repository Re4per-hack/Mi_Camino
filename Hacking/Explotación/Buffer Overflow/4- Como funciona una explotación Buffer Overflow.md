A continuación adjuntare un par de imagenes y un codigo que me ayudaran a explicar como funciona una explotación Buffer Overflow, no tienen que entenderlas de a primeras.

![[Buffer_Overflow3.png]]
(Creditos a: avietworks.com)

![[Buffer_Overflow4.png]] 
(Creditos a: imperva.com)


```c
/*
Creditos a: Julio Ureña
Twitter: @JulioUrena
Video: https://youtu.be/7KZ5LCFr6Sw
*/

#include <stdio.h>
#include <string.h>

int vuln(char *str)
{
	// Aqui se define el tamaño del buffer de la variable "buf"
	char buf[64];
	// Aqui se copian los datos de la variable "str" en la variable "buf"
    strcpy(buf,str);
   	printf("Input:%s\n",buf);
    return 0;
}
int main(int argc, char* argv[]) 
{	
	vuln(argv[1]);
}

```

Explicare este codigo para que sea mucho ams facil de entender:

1. El codigo llama a la función vuln y le pasa el argumento 1, los argumentos en este contexto son cuando iniciamos un programa desde terminal:

```bash
$> ./program Hola Mundo 
```

- En este caso "./program" es el nombre del programa, y cuenta como un argumento, el "0" para ser especifico, "Hola"  es el argumento 1 y "Mundo" es el argumento 2

2. En la función vuln se crea una varible de tipo char con el nombre "buf" y un espacio para 64 bytes (64 caracteres)

3. Se usa la funcion strcpy para copiar el conetenido de la variable "str" a la variable "buf"

4. Se imprime el conetenido de la variable buf

5. El return(0) se devuelve a la función main del principio y finaliza el programa

ya con esto entendido puedo explicar que pasaría en caso de un uso indebido de este programa:

## Buffer Overflow

Digamos que somos un usuario malintencionado y a propósito lanzamos una cantidad de bytes mucho mayor a 64, por ejemplo 100 "A"s , va a ocurrir un desbordamiento del buffer, esto quiere decir que esos datos que sobre pasaron los 64 bytes empezaran a sobrescribir otros datos, esta sobre escritura va hacia direcciones de memoria mas altas, es decir, hacia el Return Address, pasando por el EBP.

El momento del desbordamiento realmente ocurre cuando usamos la función strcpy(), ya que esos 100 bytes se meten en un buffer que no tiene suficiente espacio, y esto es un problema, porque esos datos sobrantes sobrescriben tanto el EBP como el EIP, haciendo que el valor de EBP sea "41414141" y el del Return Address "41414141", esto es porque el código hexadecimal de la "A" es 41, como ya habia explicado, el Return Address guarda la direccion a la que posteriormente el EIP va a apuntar, esto quiere decir que sobreescribir el Return Address es proporcional a sobreescribir el EIP (por lo tanto de ahora en adelante me referire al Return Address como EIP) el cual señala la dirección en la que estará la siguiente instrucción que seguirá el procesador, y como en la direccion de memoria 0x41414141 no hay nada pues ocurre una denegación de servicio, esta denegación tambien ocurre si tan solo sobre escribimos el EBP ya que marca como base "0x41414141" lo cual tampoco existe 


Ahora, a pesar de que ya explique como y porque surge una Denegación de servicio, quiero dejarlo bien claro, y lo explicaré en [5- DoS con Buffer Overflow](5-%20DoS%20con%20Buffer%20Overflow.md)
