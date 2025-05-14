
Esta herramienta nos permite tener acceso remoto a una maquina windows, lo cual es muy util  para tener un acceso grafico a la maquina, importante que el rdp debe estar habilitado para que esto funcione: 

```python
xfreerdp /u:Juan /p:Password1 /v:[IP_VICTIMA]
```
## Si hay problemas con el certificado

En este caso unicamente agregar el parametro /cert:ignore:

```python
xfreerdp /u:Juan /p:Password1 /v:[IP_VICTIMA] /cert:ignore
```

## Para usar pantalla completa

Para esto  agreguemos el parametro /f:

```python
xfreerdp /u:Juan /p:Password1 /v:[IP_VICTIMA] /f
```





