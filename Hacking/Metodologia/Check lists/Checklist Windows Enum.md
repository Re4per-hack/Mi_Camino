
# Sin Credenciales

### Escaneo de puertos:

```python
sudo nmap {IP} -p- -Pn -n -vvv --min-rate 5000 -oG ports.grep 
```

### Escaneo de versiones 

```python
sudo nmap {IP} -p{PORTs} -v -T5 -sCV -oN normal.scan
```

### Buscar  SMB Null Session

```python
netexec smb {IP}
```

### RPC client Null session

```python
rpcclient -U "" {IP_DC} -N 
```

### LDAP Null Session

```python
ldapsearch -h {DOMINIO} -x -s base namingcontexts
```

### Enumerar recursos SMB

```python
smbmap -H {IP_DC} -u 'cualquiercosa'
```

```python
smbmap -H {IP_DC} -u 'cualquiercosa' -r 'recurso'
```

