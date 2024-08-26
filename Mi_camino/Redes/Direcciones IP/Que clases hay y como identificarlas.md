Tenemos las siguientes clases:

- Clase A: "00"
- Clase B: "10" 
- Clase C: "11"

eoss numeros al lado de las clases son los primeros numeros d euna direccion IP en binario, lo cual las caracteriza, por ejemplo:

192.168.0.13

11000000.10101000.00000000.00001101

Esta IP es de clase C porque sus dos primeros numeros son "11"


Normalmente la mascara de subred (de la cual hablo en [[Para que sirve la mascara de subred]]) se distribuye asi para cada clase:

- Clase A: 255.0.0.0
- Clase B: 255.255.0.0
- Clase C: 255.255.255.0

Pero esto no es obligatorio y se puede personalizar
