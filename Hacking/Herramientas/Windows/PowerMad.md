Esta es una herramienta orientada a la manipulación y explotación de msDS-MachineAccountQuota, que define la cantidad de maquinas que pueden ser creadas por un usuario.

# Instalación

```ruby
. ./Powermad.ps1
```

## Creación de cuenta de maquina / Machine Account Creation

En este caso vamos a crear una cuenta de maquina llamada **`FAKE-COMP01`**

```ruby
New-MachineAccount -MachineAccount FAKE-COMP01 -Password $(ConvertTo-SecureString 'Password123' -AsPlainText -Force)
```

### Buscar una cuenta de maquina existente

En este caso vamos a buscar la cuenta de maquina llamada FAKE-COMP01, sirve para verificar su existencia, adicionalmente podemos usar esto para comprobar la maquina anteriormente creada:

```ruby
Get-ADComputer -identity FAKE-COMP01
```


