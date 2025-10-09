
DPAPI es la API propia de windows, usada para proteger algunos de los secrets dentro de windows (credenciales, archivos, tokens, etc...).

Para proteger estos datos, el sistema los encripta usando la Master Key, la cual a su vez se encuentra en un archivo encriptado con la contraseña derivada del usuario, lo que da como resultado a lo que conoce como BLOB (Binary large object)

# Generación de la MasterKey

**“DPAPI initially generates a strong key called a MasterKey, which is protected by the user’s password. DPAPI uses a standard cryptographic process called Password-Based Key Derivation, described in PKCS #5, to generate a key from the password. This password-derived key is then used with Triple-DES to encrypt the MasterKey, which is finally stored in the user’s profile directory.” Source: [Windows Data Protection](https://learn.microsoft.com/en-us/previous-versions/ms995355\(v=msdn.10\)?redirectedfrom=MSDN) [1]

**As noted, the MasterKey is stored on the local filesystem, where $SID is the user’s SID, and $GUID is the unique identifier for the key:***

```r
PATH:  
C:\Users\$USER\AppData\Roaming\Microsoft\Protect\$SID\$GUID
```

Hay dos formas en las que se encripta un BLOB:

- Modo User
- Modo Machine

# Modo User

### Encontrando BLOBS 

Los BLOBS suelen ser archivos OCULTOS que pueden estar en cualquier partepero el lugar mas usual en donde se pueden encontrar es , por ende se deben  ver usando `DIR -h`, no tienen porque ser archivos pueden estar en el registro de windows, pero si son archivos, el sitio mas comun para encontrarlos es aquí:

```shell
cd C:\Users\{Usuario}\AppData\Roaming\Microsoft\Credentials\
```

## Encontrando la MasterKey 

Tenemos que encontrar la MasterKey para poder desencriptar el BLOB, sobre todo su nombre, ya que pueden haber varias MasterKeys.

Cada MasterKey tiene de nombre un GUID (Global Unique IDentifier), para encontrar este GUID, lo podemos ver en el propio BLOB que deseamos desencriptar, para identificarla tenemos que leer el dumpeado del blob, por ejemplo:

![[Pasted image 20250927110850.png]]

Aquí hay muchos bytes, pero para encontrar lo que nos interesa se deben cumplir las siguientes condiciones:

- Estar seguido de la version del BLOB DPAPI : `0100 0000`

- Tener 16 Bytes de longitud 


En este caso vemos dos que empiezan por `0100 0000`, pero sollo uno es el correcto:

![[Pasted image 20250927113301.png]]

El problema es que despues de la primera secuencia `0100 0000`, lo qeu deberia ser el GUID solo tiene 2 bytes, lo cual, recordemos, es incorrecto, deben de haber 16 bytes para construir el GUID, por lo que la verdadera secuencia es la segunda, en donde vemos exactamente 16 bytes, ahora debemos convertir estos bytes en un GUID, el guid tiene esta estructura:

```
XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX
```

Nosotros tenemos los siguientes bytes:

```shell
1224 6a55 7512 cf4c b721 e6a0 b4f9 0407
```

- Un GUID de 16 bytes se forma con reordenamiento:

   - bytes 0..3 → primer campo (DWORD) **little-endian**
   - bytes 4..5 → segundo campo (WORD) **little-endian**
   - bytes 6..7 → tercer campo (WORD) **little-endian**
   - bytes 8..9 → cuarto campo (2 bytes, orden directo)
   - bytes 10..15 → quinto campo (6 bytes, orden directo)

Como resultado tenemos lo siguiente:

```shell
556a2412-1275-4ccf-b721-e6a0b4f90407
```

Entonces el nombre de archivo a buscar es `556a2412-1275-4ccf-b721-e6a0b4f90407`

Ya sabiendo el GUID (El nombre de la masterkey) esta llave se suele encontrar en:

```powershell
CD %APPDATA%\Microsoft\Protect\<SID del usuario>\
```

o lo que es lo mismo:

```powershell
CD C:\Users\{Usuario}\AppData\Roaming\Microsoft\Protect\<SID del usuario>\
```

### Desencriptando  MasterKey usando credenciales

```ruby
impacket-dpapi masterkey -file masterkey_blob -password '{Password}' -sid S-1-5-21-1487982659-1829050783-2281216199-1107 
```

### Desencriptando BLOB con masterkey

```ruby
impacket-dpapi credential -file credential_blob -key {MasterKey(OBTENIDA ANTERIORMENTE)}   
```




