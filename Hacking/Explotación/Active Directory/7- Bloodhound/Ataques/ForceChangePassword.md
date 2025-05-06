Cuando Bloodhound nos muestra esta configuración significa que podemos cambiar la contraseña de otro usuario especifico, para este caso, digamos que Usuario A tiene privilegios ForceChangePassword sobre Usuario B:


Para este caso nos tenemos que posicionar en dos posibilidades, una es si nos podemos loggear con nuestro usuario y contraseña de Usuario 1 (Que NetExec marque como pwned!), y la otra es en caso de que no, empezamos hablando de el primer caso:

## Si NO podemos acceder como Usuario A a una maquina

Para este caso vamos a usar la herramienta net, la cual nos permite interactuar con servicios de AD desde linux, específicamente para cambiar la contraseña de el usuario B siendo nosotros el usuario A usaremos la siguiente sintaxis:

```python 
net rpc password UsuarioB -U 'UsuarioA' -S [IP_DC]
```

Posteriormente nos va a pedir la nueva contraseña para el usuario B y luego la contraseña de nuestro usuario A 

## Si podemos acceder como Usuario A a una maquina

En este caso el propio BloodHound nos debería ayudar con la solución 