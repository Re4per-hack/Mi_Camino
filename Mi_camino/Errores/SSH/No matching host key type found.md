
# Error

Este Error se representa asi:

```bash
ssh {user}@{IP}

Unable to negotiate with {IP} port 22: no matching host key type found. Their offer: ssh-dss
````


# Solución

La solución a este error es usar la siguiente opción para loguearse:

```bash
ssh -oHostKeyAlgorithms=+ssh-dss {user}@{IP}
```



