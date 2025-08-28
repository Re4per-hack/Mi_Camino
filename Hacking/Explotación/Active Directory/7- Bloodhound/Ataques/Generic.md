


### 🔑 **1. GenericAll**

- 🔥 **El más poderoso.**

- El usuario puede **hacer cualquier cosa** sobre el objeto: cambiar contraseñas, modificar miembros, borrar objetos, delegar, etc.

- Es como tener **control total (Full Control)**.


---

### 📝 **2. GenericWrite**

- Permite **escribir/modificar varios atributos** del objeto, pero **no todos**.

- Por ejemplo:

- Cambiar la contraseña.

- Agregar usuarios a grupos.

- Modificar rutas de inicio de sesión.

- Delegar logon scripts.


---

### 📎 **3. WriteOwner**

- Permite cambiar el **propietario** del objeto.

- Esto es poderoso porque quien es "owner" puede luego darse permisos totales (`GenericAll`).


---

### 🔒 **4. WriteDacl**

- Permite modificar la **lista de control de acceso (DACL)** del objeto.

- Así puedes darte a ti mismo o a otro usuario `GenericAll` o cualquier permiso.


---

### 🔄 **5. AllExtendedRights**

- Este es un conjunto de permisos extendidos como:

- **ResetPassword**

- **ForceChangePassword**

- **User-Force-Change-Password**

- **Add/Remove members** (en grupos)

- No significa acceso total, pero sí **acceso crítico** sobre funciones específicas.


---

### 🔁 **6. ReadProperty / WriteProperty**

- Más bajos que los anteriores.

- Se refieren a leer o escribir propiedades específicas del objeto (como `homeDirectory`, `description`, etc.).


---

### 📂 **7. Owns (Owner)**

- Un usuario puede ser **dueño del objeto**, aunque no tenga `GenericAll`.

- El dueño puede cambiar la DACL para darse más permisos.


---

### 📚 Resumen visual:

| Permiso            | Descripción breve                         | Nivel de control    |
| ------------------ | ----------------------------------------- | ------------------- |
| GenericAll         | Control total                             | 🔥 Máximo           |
| GenericWrite       | Escribir varias propiedades               | 🔶 Alto             |
| WriteOwner         | Cambiar propietario                       | 🔸 Alto             |
| WriteDacl          | Cambiar ACLs                              | 🔸 Alto             |
| AllExtendedRights  | Acciones sensibles (reset pass, etc.)     | 🟡 Medio-alto       |
| Read/WriteProperty | Acceder o cambiar propiedades específicas | 🟢 Medio            |
| Owns (Owner)       | Dueño del objeto, puede autoasignarse más | 🔶 Alto (indirecto) |
|                    |                                           |                     |