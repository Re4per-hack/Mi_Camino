Si el servicio ldap está activo, al igual que con RPC-client, aquí podemos hacer uso de cualquier credencial, no necesariamente el usuario tiene que ser administrador de dominio, en este caso podemos usar la herramienta  ldapdomaindump.py, básicamente nos hace una especie de servidor web de forma automática para ver toda la información del dominio de una manera mucho mas grafica, esta herramienta se usa de la siguiente manera

!!EL COMANDO DEBE SER OCUPADO EN LA WEB ROOT (comúnmente /var/www/html)¡¡

```python
sudo ldapdomaindump.py -u "[DOMINIO]\{Usuario}" -p "Contraseña" {IP_DC}
```

