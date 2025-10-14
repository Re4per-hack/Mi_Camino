AES es un metodo de encriptacion simetrico (se encriptan los datos usando una llave simetrica), y por ende es crackeable (si está en base a una contraseña debil), para creackear este tipo de archivos hay que extraer el "hash" antes que nada, lo cual lo podemos hacer con este archivo [aquí](https://raw.githubusercontent.com/hashcat/hashcat/master/tools/aescrypt2hashcat.pl):

```ruby
perl encripted_file.aes > hash 
```

Ahora podemos crackear el hash usando hashcat:

```ruby
hashcat -a 0 -m 22400  hash /path/to/wordlist
```


Luego lo podemos desencriptar usando python:

```python
import pyAesCrypt

password = "foopassword"
pyAesCrypt.decryptFile("data.txt.aes", "dataout.txt", password, bufferSize)
```


