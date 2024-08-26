A continuación están los comandos necesarios para la sanitización la TTY (arreglar terminal de una reverse Shell)

- script /dev/null -c bash
- Ctrl+z: Suspendemos el proceso
- stty raw -echo; fg
- reset xterm: Reseteamos la terminal

# Si surge algún error

- EXPORT=xterm




 