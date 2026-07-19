
Ejecutar los siguientes comandos:

```ruby
docker build -t python-environ .
docker run --rm -it --net=host -v "$PWD:/work" python2-enviro
```
