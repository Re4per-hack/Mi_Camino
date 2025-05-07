# Conectarse remotamente

## Realizar un Kerberoasting

Para mas informacion visitar el apartado [[2- Realizando un Kerberoasting]]

### Usando psexec

```python
psexec {DOMINIO}/{Usuario}:{Contraseña}@{IP} cmd.exe
```
## Usando evil-winrm

```python
evil-winrm -u '{USUARIO}' -p '{CONTRASEÑA}' -i {IP_MAQUINA}
```

## Enumerar contenido


Revisar los módulos [[4- Enumeración con RPC Client]] y [[5- Enumeración con ldap]]

## Kerberoasting

Revisar el modulo [[2- Realizando un Kerberoasting]]


