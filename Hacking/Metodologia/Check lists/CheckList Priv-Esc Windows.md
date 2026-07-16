### [Puertos abiertos](https://hacktricks.wiki/es/windows-hardening/windows-local-privilege-escalation/index.html?highlight=windows%20local%20priv#puertos-abiertos)

Comprueba los **restricted services** desde el exterior

```ruby
netstat -ano
```

### Privilegios locales

```ruby
whoami /all
```

### Historial de comandos

```python
cat $env:APPDATA\Microsoft\Windows\PowerShell\PSReadLine\ConsoleHost_history.txt
```

- `$env:APPDATA`: Equivale a `C:\Users\<NombreUsuario>\AppData\Roaming`



