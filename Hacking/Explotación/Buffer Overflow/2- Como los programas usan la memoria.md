Esto puede variar de lenguaje en lenguaje, pero como se está hablando de Buffers Overflows, pues voy a centrarme mas en C, que es donde habitualmente se presentan, voy a hacer que todo esto sea lo mas entendible que se pueda, empezare hablando de la memoria fisica, la RAM como tal, ya que el programa no la necesita toda, y hay otros programas, incluidos los del propio sistema operativo, estos necesitan también de la RAM, que como explique antes, es la encargada de estos procesos en ejecución, bueno, prosigo, la manera que tiene el kernel/sistema operativo, para comunicar a los programas con la RAM es asignando partes de la memoria, y estas partes varían según el tamaño y necesidades del programa, pero la estructura casi siempre es la misma: 

![[Buffer_Overflow1.png.png]]

Vamos a empezar a ver de abajo hacia arriba: 

## Segmentos estáticos:

Primero hablare de los segmentos estáticos, ¿A que me refiero con esto?, bueno, cuando un programa aparta la memoria que necesita para su ejecución tiene que tener en cuenta de que su tamaño puede variar, ya que muchas aplicaciones hacen uso de "inputs" o entradas de datos que tienen que ser proporcionadas por los usuarios y ser guardadas en variables, o usadas por alguna aplicación, por lo tanto hay zonas de memoria tanto para estos datos nuevos, y también los hay para datos que ya se sabe que serán ocupados, como el propio código, variables declaradas y con un valor asignado en el propio código, variables estáticas, etc... 

- La dirección mas baja de la memoria está reservada para el código que aparta este segmento de memoria como tal. 

- Luego está el segmento de datos que almacena las variables predefinidas y estáticas.

- El segmento BSS almacena las variables inicializadas pero que no se les ha dado ningún valor.

## Segmentos variables

Aqui se guardan los datos que van cambiando conforme se ejecuta el programa en cuestión

- El segmento "Heap" almacena los datos que se ingresan en medio de la ejecución, como se ve en la imagen, los datos almacenados crecen hacia direcciones mas altas de memoria, es decir, hacia 0xffffffff

- El segmento de pila, o en ingles y mas conocido "Stack",  almacena las funciones, los argumentos y las variables declaradas dentro de funciones.  Los datos almacenados crecen hacia abajo, es decir, a direcciones mas bajas 0x00000000

Como se puede ver en la imagen, hay un espacio vacío entre el Heap y el Stack, pues ese espacio es el cual usaran estos dos para guardar sus datos, y mientras que el Heap crece de manera esperada, "Hacia arriba" o direcciones de memoria mas altas, el Stack es diferente, ya que crece "Hacia abajo" o direcciones de memoria mas bajas, esto hace que todo el comportamiento de la pila sea al revés. 

Para buffer Overflow se puede explotar tanto el Heap como el Stack, pero hablare solo del stack ya que es por lejos el mas común y extendido a lo largo del mundo, para seguir visita la sección [[3- Introduccion al Stack]] 



