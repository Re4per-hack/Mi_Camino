

Entendido. Para el laboratorio **GOAD v2 (Game of Active Directory)**, que es una joya para practicar Red Team, vamos a omitir lo básico (Null Sessions y Passwords en descripciones) y nos enfocaremos en vulnerabilidades estructurales y de configuración.

Aquí tienes 4 vulnerabilidades dirigidas al **Domain Controller (DC)** y 2 dirigidas a **máquinas del dominio (Workstations/Servers)** dentro de este entorno:

---

### Vulnerabilidades al Domain Controller (DC)

#### 1. AS-REP Roasting (Usuarios sin Pre-Autenticación)

En GOAD, hay cuentas configuradas con el atributo `DONT_REQ_PREAUTH`. Esto permite solicitar un ticket de autenticación al DC sin conocer la contraseña. El DC responde con una parte del ticket cifrada con el hash del usuario.

- **Impacto:** Puedes extraer ese hash de forma offline y crackearlo (como el script de Python que estábamos viendo) para obtener la contraseña en texto claro.
    

#### 2. Constrained Delegation (Abuso de Delegación)

Algunos objetos en el AD de GOAD tienen configurada la "Delegación Restringida" con `S4U2Proxy`. Esto permite que un servicio suplante a un usuario ante otro servicio específico.

- **Impacto:** Si comprometes la cuenta que tiene el permiso de delegación, puedes generar un ticket de servicio para un Administrador del Dominio y comprometer el DC.
    

#### 3. GPP Password (en SYSVOL)

Aunque es una vulnerabilidad antigua, GOAD la incluye para realismo. Se trata de contraseñas guardadas en archivos XML dentro de las **Group Policy Preferences**. Aunque están "cifradas", la clave AES es pública (publicada por Microsoft hace años).

- **Impacto:** Permite obtener credenciales de administrador local o de dominio que fueron usadas para desplegar configuraciones.
    

#### 4. ACLs Abusables (GenericAll / WriteDacl)

En el laboratorio, existen relaciones de control donde un usuario con pocos privilegios tiene permisos de **GenericAll** o **WriteDacl** sobre un objeto más poderoso (o incluso sobre el contenedor del dominio).

- **Impacto:** Puedes modificar los permisos del objeto para darte control total, cambiarle la contraseña a un Admin o añadir tu usuario a un grupo privilegiado como "Enterprise Admins".
    

---

### Vulnerabilidades a Máquinas (Workstations / Servers)

#### 1. SMB Signing Disabled

En varias máquinas del laboratorio (como las estaciones de trabajo), la firma de SMB no está requerida.

- **Impacto:** Permite realizar ataques de **SMB Relay**. Si logras capturar una autenticación (vía LLMNR/NBT-NS Poisoning con Responder), puedes reenviarla a otra máquina para ejecutar comandos de forma remota (usando `ntlmrelayx.py`) y obtener una shell.
    

#### 2. Unquoted Service Paths (Rutas de servicio sin comillas)

Algunos servicios instalados en las máquinas de GOAD tienen rutas con espacios y sin comillas (ej: `C:\Program Files\Servicio Vulnerable\bin.exe`).

- **Impacto:** Si tienes permisos de escritura en la carpeta raíz (ej: en `C:\`), puedes subir un binario malicioso llamado `Program.exe`. Cuando el servicio intente iniciar, Windows ejecutará tu malware en lugar del servicio real, normalmente con privilegios de **SYSTEM**.
    

---

### ¿Cómo se conecta esto con tu viaje?

Si vas a estar practicando estas técnicas en el bus hacia **San Gil**, recuerda que GOAD v2 es bastante pesado para la RAM. Asegúrate de encender solo las máquinas que necesites para la ruta de ataque específica (ej: solo el DC y una Workstation) para que tu laptop no sufra con el calor del viaje.

¿Cuál de estas vulnerabilidades te interesa que profundicemos para tu laboratorio?

