# Kerberos

#### KRB_AP_ERR_SKEW

Error: \[\-\] Got error while trying to request TGT: Kerberos SessionError: KRB_AP_ERR_SKEW(Clock skew too great)

```ruby
timedatectl set-ntp off  
rdate -n <IP_DC>
```

#### STATUS_NOT_SUPPORTED

Este error la mayoria de las veces significa que NTLM está deshabilitado, y por ende la autenticacion tiene que ser por Kerberos, podemos confirmar esto obteniendo el ticket TGT para nuestro usuario: 

Para esto podemos usar la herramienta de impacket:

```python
getTGT.py '{DOMINIO}'/'{USERNAME}':'{PASSWORD}'
```

# Cannot find KDC for REALM "{domain}.example"

Este error quiere decir que la herramienta que estemos usando no esta pudidendo resolver el dominio, en muchos casos, tambien podremos ver algo como:

Unspecified GSS failure. Minor code may provide more information

![[Pasted image 20251021124936.png]]

Para arreglar el problema crear un archivo con el siguiente contenido :

```ruby
[libdefaults]
  default_realm = VOLEUR.HTB
  dns_lookup_kdc = false

[realms]
  VOLEUR.HTB = {
    kdc = 10.10.10.5
    admin_server = 10.10.10.5
  }

[domain_realm]
  .voleur.htb = VOLEUR.HTB
  voleur.htb = VOLEUR.HTB
```



