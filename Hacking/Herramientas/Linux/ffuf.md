
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