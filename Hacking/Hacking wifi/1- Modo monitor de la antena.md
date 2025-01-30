
## Usando wifite

Antes de conectar nuestra antena tenemos que matar los procesos conflictivos, para esto vamos a usar:

```shell
sudo wifite --kil
```

Naturalmente estos procesos conflictivos suelen ocurrir por el NetworkManager, pero por las dudas y evitar quebraderos de cabeza, usaremos wifite para que lo haga automaticamente, cuando el comando se haya completado conectamos la antena y ponemos la antena en modo monitor usando:

```shell
sudo wifite wlan0
```

## Usando aircrack-ng 
