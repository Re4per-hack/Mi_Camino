### Conexión común

```ruby
evil-winrm -u '{USUARIO}' -p '{CONTRASEÑA}' -i {IP_MAQUINA}
```

### Usar certificados para autenticarse

Para esto necesitamos la llave privada y el certificado, estos se pueden encontrar en archivos pfx, si es el caso visita [[openssl#Interactuar con archivos PFX]] para saber como se extraen este par de datos en archivos separados:

```ruby
evil-winrm -i <IP_de_la_máquina> -S -c legacyy.crt -k legacyy.key
```

### Conexión por ssl (Certificados)

En algunos casos, sobre todo cuando está abierto el puerto de winrm por HTTPS, segurmaente solo se permita la conexión por ese puerto, en ese caso lo ideal es siempre conectarse usando este protocolo, para esto se usa la opción `-S`:

```ruby
evil-winrm -u '{USUARIO}' -p '{CONTRASEÑA}' -i {IP_MAQUINA} -S
```

