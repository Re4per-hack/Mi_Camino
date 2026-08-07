
Ejecutar los siguientes comandos:

```ruby
sudo su
docker build -t python2-environ .
docker run --rm -it --net=host -v "$PWD:/work" python2-environ
```

## Instalar nano 

```ruby
sed -i 's/deb.debian.org/archive.debian.org/g' /etc/apt/sources.list
sed -i 's|security.debian.org/debian-security|archive.debian.org/debian-security|g' /etc/apt/sources.list 
sed -i '/buster-updates/d' /etc/apt/sources.list 
apt-get -o Acquire::Check-Valid-Until=false update && apt-get install -y nano
```


