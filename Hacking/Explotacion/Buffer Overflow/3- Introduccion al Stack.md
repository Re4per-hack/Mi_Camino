El Stack, o pila, se divide en varias zonas, explicadas con la siguiente imagen: 

![[Buffer_Overflow2.png]]
(Creditos a: payatu.com)

Como expliqué anteriormente, el Stack crece hacia abajo, por eso en la imagen aparecen invertidas las direcciones de memoria, porque está "de cabeza", esto puede ser confuso al principio pero poco a poco se entenderá mejor, iré al grano, nuestro objetivo es el Return Address.

## Buffer

El Buffer es en donde se guardan esos datos que agregamos en las funciones al momento de la ejecución y es donde surge el nombre de Buffer Overflow, esto lo explicaré en otra seccion

## Return Address

El Return Address almacena la dirección en memoria de la siguiente instrucción que debe ser ejecutada, Lo explicaré:


```Assembly
CALL func   ; Llama a la función `func`
MOV EAX, 1 ; Instrucción siguiente a la llamada de la función
```


1. El procesador guarda en el Return Address la dirección de "MOV EAX, 1".

2. El EIP apunta a la función ("func") para ser ejecutada.

3. Cuando la función termina, el procesador extrae la dirección almacenada en el Return Adress (proceso a cual se le llama "pop")  y  carga lo que haya en esa direccion usando el EIP.


## ESP

El ESP siempre va a indicar la dirección del ultimo dato ingresado, es decir, el ESP va a tener siempre la dirección en memoria mas baja, ya que este representa el crecimiento máximo de la pila, esto como ya vimos anteriormente es hacia abajo, es decir, direcciones mas bajas.

Podemos verlo como el top de el Buffer.


## EBP 

El EBP es la base del marco de la pila, lo podemos ver como la base del Buffer.


Ya con estos conceptos aprendidos vamos a hablar de [4-Como funciona una explotación Buffer Overflow](/Hacking/Explotacion/Buffer%20Overflow/4-%20Como%20funciona%20una%20explotación%20Buffer%20Overflow.md)



