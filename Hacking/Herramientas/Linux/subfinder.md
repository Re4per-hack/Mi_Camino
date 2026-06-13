subfinder es una herramienta para encontrar subdominios, bastante utilizando en bugbounty porque no interactua directamente con los servidores, sino que basa su reconocimiento de forma 100% pasiva, esto permite evitar bloqueos de IP entre otras cosas, y es por esto que no tenemos que indicar un wordlist:

## Uso común

```ruby
subfinder -d mi-objetivo.com
```

# Definir output

```ruby
subfinder -d mi-objetivo.com -o subdirecories_founded.txt
```


