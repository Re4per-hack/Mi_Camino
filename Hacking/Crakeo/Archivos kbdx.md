Para este caso podemos usar la herramienta keepass2john, esta herramienta nos permite extraer el hash del archivo kdbx:

```ruby
keepass2john file.kdbx > hash.txt
```

Ahora podemos crackear el hash usando:

## John

```ruby
john --wordlist=/ruta/al/wordlist hash.txt
```

## HashCat

```ruby
hashcat -a 0 -m 
```


# !! IMPORTANTE !!!

En caso de que esto falle o no se reconozca el hash leer lo siguiente:

Para este caso vamos a hacer uso de la herramienta keepass4brute (disponible [aquí](https://github.com/r3nt0n/keepass4brute)), su uso es el siguiente:

# Uso

```python
./keepass4brute.sh <kdbx-file> <wordlist>
```






