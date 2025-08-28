
PKINIT no es mas que una pequeña extension para el servicio de kerberos, la cual nos permite autenticarnos sin usar una contraseña, esto gracias a certificados, claves publicas y claves privadas.

Lo único que cambia PKINIT con respecto a la autenticación Kerberos de toda la vida, es la autenticación inicial, es decir, en donde se usa la contraseña, ya que con PKINIT, la autenticacion sigue el siguiente protocolo: 


1. **AS-REQ with PKINIT:** The client sends a request to the KDC, including a timestamp signed with the client’s private key and the corresponding public key.

2. **Public Key Validation:** The KDC checks the client’s public key against the **msDS-KeyCredentialLink** attribute in Active Directory. Means, instead of directly using the certificate for authentication, the KDC is validating if any of the public keys in the **msDS-KeyCredentialLink** attribute of the user matches the one used in the AS-REQ. If the key is valid, the KDC decrypts the timestamp and verifies the signature.


3. **AS-REP:** If validation is successful, the KDC issues a TGT to the client.


PKINIT tiene dos formas diferentes de funcionar, dependiendo de si se usa el atributo msDS-KeyCredentialLink o no, en caso de que sea usado el proceso es igual a como se presentó arriba, en caso de que no sea así, la autenticación varia un poco


## 🧩 Fases del proceso PKINIT

### 🔐 1. El cliente genera el AS-REQ con PKINIT

En lugar de enviar un AS-REQ clásico basado en una clave derivada de la contraseña del usuario, el cliente:

1.1. Genera un **nonce (valor aleatorio)** y lo incluye en el mensaje.

1.2. Encripta cierta parte del mensaje con su **clave privada** para demostrar posesión (firma digital). Esto incluye típicamente un valor como el nonce, el nombre del cliente, una marca de tiempo u otro dato para evitar _replay attacks_.

1.3. Adjunta su **certificado digital** en el AS-REQ como parte de una estructura PKAuthenticator (según RFC 4556).

1.4. Especifica en el mensaje que está usando **PKINIT**.

---

### 🏛️ 2. El KDC recibe el AS-REQ con PKINIT

2.1. Verifica la **firma digital del cliente** usando el certificado que recibió.

2.2. Verifica que el certificado del cliente:

- No esté expirado.

- No esté revocado (consulta la CRL o usa OCSP).

- Provenga de una CA de confianza (validación de cadena).


2.3. Si todo es válido, el KDC acepta la autenticación del cliente y genera el **TGT (Ticket Granting Ticket)** como siempre.

---

### 📦 3. El KDC genera el AS-REP (respuesta del KDC)

3.1. El KDC genera una **clave de sesión**.

3.2. Encripta esta clave de sesión con la **clave pública del cliente** (obtenida del certificado que le envió).

3.3. Incluye el TGT y la clave de sesión cifrada en el **AS-REP**, y lo firma con su propia clave privada.

---

### 📥 4. El cliente recibe el AS-REP

4.1. El cliente **descifra la clave de sesión** usando su **clave privada**.

4.2. Ya tiene el **TGT** y la clave de sesión, como en Kerberos tradicional.

4.3. A partir de aquí, continúa el proceso normal de Kerberos (TGS-REQ/TGS-REP para acceder a servicios).
