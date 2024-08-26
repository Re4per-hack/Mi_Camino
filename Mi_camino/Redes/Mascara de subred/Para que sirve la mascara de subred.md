
Para responde la esta pregunta es necesario saber de que necesidad salio la creacio de esta mascara, la necesidad de crear esta subred fue por el orden que hay en una red, para hacerla mas rapida y entendible para el usuario, quiero que se entienda que el termino "subred" solo tiene sentido en una red privada, y esto lo entenderan mas adelante, pero para resumir, la mascara subred pone "limites a la red", ¿A que me refiero con esto? bueno pues, la mascara subred nos permite a nosotros como usuarios, definir el numero maximo de dispositivos que se pueden conectar, y que IPs van utilizar, y ademas, nos ayuda a que en nuestra propia red podamos dividir las conexiones para hacer todo mucho mas simple


## Como se definen estas limitaciones

Evidentemente esto es mucho mas util en empresas, donde la red puede llegar a ser un poco caotica, pero ahora, ¿Como se definen estas delimitaciones?

Okay, todo este tema de las redes, las subredes y asi, es el tema mas rompe cabeza y aburrido que he visto en el hacking hasta la fecha, pero es importante entenderlo y lo voy a explicar lo mas sencillo posible, ten en cuenta que tu mascara subred no es mas que la forma que le das a tu computadora, celular, IoT o lo que sea, para que interprete una red, es muy diferente que un computador tenga la IP 192.168.13.10 y la mascara subred 255.255.255.0, a que tenga la misma IP pero la mascara subred 255.255.0.0, ¿Porque?, bueno, pues lo explicare aqui abajo:

Primero hay que entender como funciona una mascara subred, y para ello vamos a pasar la mascara del primer ejemplo a binario (si, todo aqui se trata con binarios, incluida la IP):

- 255.255.255.0

11111111.11111111.11111111.00000000

Entonces, que significa esto, bueno, pues vamos a dividirlo y vamos a identificarlo en diferentes secciones:

    1       2        3         4
11111111.11111111.11111111.00000000

Bien, ahora,  miremos las ultimas dos secciones, veremos que cada seccion representa un numero decimal diferente, en caso de la seccion 3 representa el 255 y en el de la seccion 4 el "0", y que significa esto?, bueno, pues significa que en la ultima seccion de la IP con la que usemos esta mascara podremos usar todos los caracteres que queramos, ya qeu esos son los numeros conocidos como "Numeros hosts" es decir, el rango de IPs disponibles para distribuir a los usuarios va desde 192.168.13.0 hasta 192.168.13.255, todas las IPs que esten en este rango se podran conectar entre si.

En resumen, esos "0" que estan libres, son "0" que podemos usar para distribuir en host.

Y si eres inteligente supongo que supondras que lo mismo pasa si quitamos los "1" de la seccion 3:

11111111.11111111.00000000.00000000

En este caso el rango de IP's van desde 192.168.0.0 hasta 192.168.255.255, y asi sucesivamente, entonces, ¿lo ves? en computador es quien debe definir la mascara de subred ya que la forma de interpretación es completamente diferente,¿ y que pasa si una maquina tiene de mascara 255.255.255.0 y otra 255.255.0.0?, bueno, pues que mientras que una va a conectarse a otros computadores siempre y cuando las primeras 3 secciones de su IP sean 192.168.13, la otra solo le bastara con que empiece con 192.168

PD: no es necesario que la IP sea "192.168.13..." obviamente es un ejemplo la IP puede ser "192.168.0..." o "182.421.123..." etc, lo hice asi para que se entendiera mejor