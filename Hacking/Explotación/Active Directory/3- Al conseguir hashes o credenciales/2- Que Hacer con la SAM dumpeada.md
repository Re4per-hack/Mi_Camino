# Pass The Hash Attack

Los hashes almacenados en la SAM (a diferencia de los NTLMv2 que obtenemos en SMB Relay attack simple) nos permiten acceder a la maquina sin crackearlos, es decir, usarlos como una especie de llave valida, para esto podemos usar una herramienta llamada wmiexec.py:

```ruby
wmiexec.py NOMBRE_DOMINIO/USUARIO@IP -hashes HASH_OBTENIDO 
```

