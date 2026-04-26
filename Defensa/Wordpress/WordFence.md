### 1. Firewall (WAF) y Optimización

El firewall de Wordfence es potente, pero si no está optimizado, solo actúa a nivel de aplicación (PHP), lo cual es ineficiente ante ataques de fuerza bruta.

- [ ] **Optimizar el Firewall:** Asegúrate de que diga **"Extended Protection"**. Esto escribe en tu `.user.ini` o `.htaccess` para que Wordfence cargue _antes_ que cualquier otra cosa en el servidor.
    
- [ ] **Modo de Firewall:** Cámbialo de "Learning Mode" a **"Enabled and Protecting"** (hazlo después de una semana de uso para evitar falsos positivos).
    
- [ ] **Detección de IP:** Verifica que Wordfence detecte tu IP real y no la del servidor/proxy (mira en _All Options > General Wordfence Options > How does Wordfence get IPs_).
    
- [ ] **Reglas en tiempo real:** Si tienes la versión Premium, asegúrate de que el **Real-Time IP Blocklist** esté activado.
    

### 2. Login Security (La Capa Crítica)

Como Red Teamer, sabes que el login es el vector #1. Vamos a blindarlo.

- [ ] **2FA (Autenticación de Dos Factores):** **Obligatorio** para todos los Administradores y Editores. Usa Google Authenticator o Authy.
    
- [ ] **Códigos de recuperación:** Genera y guarda los recovery codes en un lugar seguro (KeePass o Bitwarden).
    
- [ ] **XML-RPC:** Desactiva la autenticación XML-RPC a menos que uses la app móvil de Jetpack. Es un vector común de fuerza bruta.
    
- [ ] **Hide WordPress Version:** Asegúrate de que la versión de WP no sea pública para evitar el reconocimiento de vulnerabilidades específicas.
    
- [ ] **reCAPTCHA v3:** Actívalo en el formulario de login y registro para detener bots sin molestar a los usuarios.
    

### 3. Brute Force Protection (Ajustes Agresivos)

Wordfence viene "suave" por defecto. Para un sitio de seguridad, necesitamos ser más estrictos:

- [ ] **Lock out after failure:** Baja el límite de intentos. Recomendado: **3 intentos**.
    
- [ ] **Lock out after forgot password:** Recomendado: **3 intentos**.
    
- [ ] **Count failures over time:** Ponlo en **12 o 24 horas**.
    
- [ ] **Duration of lockout:** No uses los 5 minutos por defecto. Pon **2 meses** o más. Si alguien falla 3 veces en 24 horas, es un ataque.
    
- [ ] **Inmediatamente bloquear:** Añade nombres de usuario comunes a la lista negra como `admin`, `administrator`, `test`, `root` o el nombre de tu dominio. Quien intente entrar con esos nombres debe ser bloqueado de por vida.
    

### 4. Scan Settings (Detección de Intrusos)

- [ ] **Scan Scheduling:** Configúralo para que se ejecute al menos **una vez al día** (preferiblemente de madrugada).
    
- [ ] **High Sensitivity:** Activa la opción "Use extremely low resource scanning" si tu hosting es compartido, pero asegúrate de que el escaneo sea **exhaustivo** (check en _Scan images, binary files as if they were executable_).
    
- [ ] **Monitorización de archivos:** Wordfence debe comparar tus archivos de core, themes y plugins con el repositorio oficial de WordPress.org para detectar cambios maliciosos.
    

### 5. Advanced Rules (Red Teaming Mode)

- [ ] **Rate Limiting:** Si un bot (crawler no identificado) accede a más de **240 páginas por minuto**, bloquéalo.
    
- [ ] **Country Blocking:** Si tu audiencia es principalmente de Colombia o España, considera bloquear el login (no el sitio completo) para países con alta actividad de botnets si no esperas tráfico legítimo de ahí.
    
- [ ] **Live Traffic:** Revísalo una vez al día para identificar patrones de escaneo (ej. alguien buscando `/wp-content/plugins/revslider/`).