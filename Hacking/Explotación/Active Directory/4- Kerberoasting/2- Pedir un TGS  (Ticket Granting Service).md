El TGS es el ultimo ticket que nos da el servicio Kerberos para autenticarnos al SPN (Service Principal Name) deseado, está encriptado con la contraseña del servicio al que estamos enviando una petición, para esto necesitamos tener credenciales validas, con esto podremos pedir un TGS, el cual está encriptado con la contraseña del servicio que estamos solicitando, gracias a este contexto podemos crackearlo y obtener la contraseña del servicio en cuestión.

Primeramente vamos a listar los SPN (Service Principal Name) en el AD (Active Directory), para ello necesitamos credenciales validas, no tiene que ser administrativas, solo de cualquier usuario del dominio:

```Python
GetUserSPNs.py juancorp.local/Juan:Password1
```

Ahora, podemos usar la opcion --request para obtener el TGS-REP, que contiene el Ticket Granting Service, 


![[Pasted image 20250423105234.png]]


