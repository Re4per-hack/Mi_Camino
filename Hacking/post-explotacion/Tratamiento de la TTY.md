A continuación están los comandos necesarios para la sanitización la TTY (arreglar terminal de una reverse Shell)

- script /dev/null -c bash
- Ctrl+z: Suspendemos el proceso
- stty rawx -echo; fg
- export TERM=xterm
- export SHELL=bash
- reset xterm: Reseteamos la terminal
- (En nuestra maquina pantalla completa) stty size
- stty rows {VALOR_IZQUIERDA} columns {VALOR_DERECHA}








 