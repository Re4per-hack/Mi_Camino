 Kerbrute es una herramienta que nos permite enumerar contenido de un dominio aprovechándonos del protocolo kerberos:
## Validar una lista de usuarios

Si tenemos una lista de usuarios pero no sabemos si son validos, podemos hacer uso de esta herramienta para verificar cuales lo son y cuales no:

¡¡¡RECUERDA DEFINIR LA IP DEL NOMBRE DE DOMIIO EN EL ARCHIVO /etc/hosts PARA QUE KERBRUTE LO PUEDA ENCONTRAR!!!

```python
kerbrute --dc [IP_DC] -d [NOMBRE_DOMINIO] users.txt
```
