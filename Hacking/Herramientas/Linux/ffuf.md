
## Indicar una cookie

```shell
ffuf -u http://target/FUZZ -w wordlist.txt -b "nombre_cookie=valor"
```
## Indicar el método

```shell
ffuf -X '{METHOD}' -u {URL} -w {PATH_TO_WORDLIST}
```

## Indicar header especifico

```shell
ffuf -u https://example.com/FUZZ -w wordlist.txt -H "User-Agent: MiUserAgentPersonalizado"
```

## Indicar un parámetro

```shell
ffuf -u https://target.com/login -X POST -d "username=admin&password=FUZZ" -H "Content-Type: application/x-www-form-urlencoded" -w /path/to/wordlist.txt
```

