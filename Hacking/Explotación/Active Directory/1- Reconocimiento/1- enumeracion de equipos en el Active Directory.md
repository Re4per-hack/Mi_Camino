Para realizar un sondeo de los dispositivos disponibles en el Active Directory, es tan simple como usar la herramienta Netexec de la siguiente forma: 

EJEMPLO:
```ruby
cme smb 102.168.184.0/24
```

Lo anterior es un ejemplo y la IP obviamente varia según la IP y mascara Subred, recomiendo investigar [[Para que sirve la mascara de subred]], esto no solo nos mostrará los equipos en el directorio activo, también nos dirá si están firmados o no, esto condicionara que ataques podemos hacer y cuales no.