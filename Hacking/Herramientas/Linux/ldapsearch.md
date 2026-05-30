
# Null Session 


```python
ldapsearch -H ldap://{DOMINIO} -x  base namingcontexts 
```


- **`-h {DOMINIO}`**: Especifica el **Host**.

- **`-x`**: Activa la **Autenticación Simple**. Le dice al servidor que intente una "Simple Bind". 

- **`-s base`**: Define el **Scope** (alcance) como "base".

- **`namingcontexts`**: Este es el atributo específico que le estás pidiendo al servidor.
#### Respuesta:

- `result: 0 Success` == Null Session



#  Enumerar password in attributes (Info, Description, Comment)


```python
sudo ldapsearch -H ldap://10.129.51.75 -D '{User}@{Domain}'-w '{PASSWORD}' -b "DC=support,DC=htb" | grep -E "info|description|comment"
```