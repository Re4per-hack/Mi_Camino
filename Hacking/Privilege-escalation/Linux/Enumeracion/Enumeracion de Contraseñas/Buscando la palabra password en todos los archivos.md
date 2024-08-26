Este comando nos permite buscar palabras clave en todos los archivos del sistema partiendo de la raiz ("/"), por ejemplo:

	grep --color=auto -rnw '/' -ie "PASSWORD=" --color=always 2> /dev/null
