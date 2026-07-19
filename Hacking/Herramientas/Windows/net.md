


# Interaccion con SMB 

### Ver a que shares tengo acceso como el usuario actual

```ruby
net 
```

:: Ver a qué shares estás conectado net use :: Conectar a un share (te pide montar el recurso) net use \\10.10.10.5\ShareName :: Conectar CON credenciales (clave en pentesting cuando tienes user/pass) net use \\10.10.10.5\C$ /user:DOMINIO\usuario password :: Montar como letra de unidad net use Z: \\10.10.10.5\ShareName :: Desconectar net use \\10.10.10.5\ShareName /delete
### Autenticarse a un recurso compartido

```ruby
net use Z: \\192.168.1.50\CarpetaCompartida /user:NombreUsuario ContraseñaSegura
```

