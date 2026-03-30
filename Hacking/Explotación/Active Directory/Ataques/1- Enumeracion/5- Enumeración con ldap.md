`Si el servicio ldap está activo, al igual que con RPC-client, aquí podemos hacer uso de cualquier credencial, no necesariamente el usuario tiene que ser administrador de dominio, en este caso podemos usar la herramienta  ldapdomaindump.py, básicamente nos hace una especie de servidor web de forma automática para ver toda la información del dominio de una manera mucho mas grafica.

Ejecutar el comando en una carpeta, ya que va a crear varios archivos:

```python
sudo ldapdomaindump.py -u "[DOMINIO]\{Usuario}" -p "Contraseña" {IP_DC}
```

Ya con todos estos archivos en la carpeta podemos iniciar un servidor http con python:

```python
sudo python3 -m http.server 80
```

