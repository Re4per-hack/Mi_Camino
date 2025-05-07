Esta herramienta nos permite actuar como clientes SAMBA (SMB) y listar diferentes recursos de sistema, es mayormente recomendado usar esta herramienta para conexiones smb, y para enumerar información usar [[smbmap]]:
### Null session con smbclient

Como dije antes esta o es la mejor opcion pero por cualquier documentaré el uso por aquí 

```python
smbmap -L {IP_DC} -N
```

### Autenticación con smbclient

```python
smbmap -L {IP_DC} -U [DOMINIO]/[USUARIO]%[CONTRASEÑA]
```

