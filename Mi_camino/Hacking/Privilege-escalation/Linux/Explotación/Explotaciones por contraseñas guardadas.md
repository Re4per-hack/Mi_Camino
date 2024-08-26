Hay diferentes archivos y comandos a utilizar, con los cuales podemos ver contraseñas guardadas y la base de toda esta "explotación" son las contraseñas recolectadas en la fase de Enumeracion Explicada en "Enumeración de Contraseñas", por ejemplo con el comando "history", o accediendo a el archivo /home/{user}/.{SHELL}\_history

```bash
history | grep "pass"
```


Otra forma en la que podemos encontrar contraseñas guardadas es usando el payload de [Payloads for all the things](https://swisskyrepo.github.io/InternalAllTheThings/redteam/escalation/linux-privilege-escalation/#looting-for-passwords)

```zsh
find . -type f -exec grep -i -I "PASSWORD" {} /dev/null \;
```


Aunque en lo personal prefiero el siguiente Payload, ya que muestra con color


```bash
grep --color=auto -rnw '/' -ie "PASSWORD" --color=always 2> /dev/null
```

La herramienta Linpeas.sh tambien nos ofrece una busqueda de contraseñas, entonces es altamente recomendable usarlo si no se encuentra nada con la busqueda manual


