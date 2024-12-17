Al dumpear la SAM podemos hacer PassTheHash si un equipo es privilegiado sobre otro, por ejemplo, si juan tiene privilegios sobre silvia, y dumpeamos la sam de este, y encontramos el hash del dominio, podemos usarlo para autenticarnos contra silvia, mas no para autenticarnos en la maquina de juan:

```ruby
wmiexec.py {dominio}/{usuario}@{IP_de_la_victima} -hashes {Hash del usuario}
```

