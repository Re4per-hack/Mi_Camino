

# Windows Registers
#### VNC

```ruby
reg query "HKCU\Software\ORL\WinVNC3\Password"
```

#### Windows autologin

```ruby
reg query "HKLM\SOFTWARE\Microsoft\Windows NT\Currentversion\Winlogon"
```

#### SNMP Paramters

```ruby
reg query "HKLM\SYSTEM\Current\ControlSet\Services\SNMP"
```

#### Putty

```ruby
reg query "HKCU\Software\SimonTatham\PuTTY\Sessions"
```

#### Search for password in registry

```ruby
reg query HKLM /f password /t REG_SZ /s
reg query HKCU /f password /t REG_SZ /s
```

# [Puertos abiertos](https://hacktricks.wiki/es/windows-hardening/windows-local-privilege-escalation/index.html?highlight=windows%20local%20priv#puertos-abiertos)

Comprueba los **restricted services** desde el exterior

```ruby
netstat -ano | findstr 'LISTENING'
```

### Privilegios locales


```ruby
echo %username%
```

O:

```ruby
whoami /all
```


**PRIVILEGIOS LLAMATIVOS**


 - **SeImpersonatePrivilege** El rey. Habilita ataques tipo _Potato_ (PrintSpoofer, JuicyPotato, GodPotato) → SYSTEM. Típico en cuentas de servicio.
 
- **SeAssignPrimaryTokenPrivilege**: Similar, permite manipular tokens.

- **SeBackupPrivilege**: Leer _cualquier_ archivo (incluido el SAM, hashes).

- **SeRestorePrivilege**: Escribir _cualquier_ archivo.

- **SeDebugPrivilege**: Inyectar en procesos de SYSTEM.

- **SeLoadDriverPrivilege**: Cargar drivers maliciosos.

- **SeTakeOwnershipPrivilege**: Apropiarte de objetos protegidos.


### Historial de comandos

```python
cat $env:APPDATA\Microsoft\Windows\PowerShell\PSReadLine\ConsoleHost_history.txt
```

- `$env:APPDATA`: Equivale a `C:\Users\<NombreUsuario>\AppData\Roaming`

### Información del sistema

```ruby
systeminfo | findstr /B /C:"OS Name" /C:"OS Version" /C:"System Type"
```


### Nombre de maquina

```ruby
hostname
```

### Listar actualizaciónes instaladas 

#### Versiones antiguas de windows

```ruby
 wmic qfe get Caption,Description,HotFixID,InstalledOn
```

#### Versiones modernas de windows

```python
Get-HotFix | Select-Object HotFixID, Description, InstalledOn, Caption
```

### Usuarios en el sistema

```ruby
net user
```

O tambien podemos ver informacion de un usuario especifico:

```ruby
net user {usuario}
```

### Archivos de windows interesantes

```ruby
c:\sysprep.inf  
c:\sysprep\sysprep.xml  
%WINDIR%\Panther\Unattend\Unattended.xml  
%WINDIR%\Panther\Unattended.xml_
```

# Configuración red

### Interfaces disponibles

```ruby
ipconfig /all
```

### Tabla de enrutamiento

```ruby
arp -A 
```

# Variables de entorno

```ruby
set
Get-ChildItem Env: | ft Key,Value
```

### Ver contraseña de wifi

```ruby
netsh wlan show profile
netsh wlan show profile <SSID> key=clear
```

## Busqueda de contraseñas en archivos  

```python
cd C:\ & findstr /SI /M "password" *.xml *.ini *.txt
findstr /si password *.xml *.ini *.txt *.config 2>nul >> results.txt
findstr /spin "password" *.*
```







