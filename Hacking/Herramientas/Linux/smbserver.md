Esta herramienta nos permite crear un servidor SMB, muy util para pasarnos archivos a través, a continuación una pequeña guia de uso:

## Crear un servidor SMB sin credenciales

```python
smbserver.py {NOMBRE_RECURSO} {RUTA_A_COMPARTIR} -smb2support #En caso de ser windows menor a 10 omitir este ultimo parametro 
```
## Creando un servidor con credenciales

```python
smbserver.py {NOMBRE_RECURSO} {RUTA_A_COMPARTIR} -smb2support -username test -password test123  
```
