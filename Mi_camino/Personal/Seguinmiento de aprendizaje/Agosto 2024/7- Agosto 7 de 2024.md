El Protocolo SMTP corre en el puerto 25, el puerto 587 para clientes de correo y rara vez en 465

Para entrar/interactuar con este protocolo, es recomendable hacer uso de herramientas como NetCat o TelNet, con la siguiente estructura:

- nc {IP} {PUERTO SMTP(25, 587 o 465)}
- telnet {DOMINIO (Ejemplo: mailing.htb)} 

HELO y EHLO dan un reconocimiento inicial del servidor y te identifica para iniciar el proceso de envio de correo u otros, ambos comandos hacen lo mismo, pero HELO muestra tan solo el estado de conexión 

Despues de identificarnos al servidor podemos hacer varias cosas, entre ellas: 

AUTH LOGIN: permite el inicio de sesion para el posterior envio de correos

- Para mas informacion use el comando HELP

Me faltó aprender a hacer que los correos se interpreten como codigo html pero lo dejaré para despues en mi lista de pendientes como: [[Correos interpretados como HTML]]




