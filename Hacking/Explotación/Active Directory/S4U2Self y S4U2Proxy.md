

# Explotación

Este ataque se puede explotar dentro de una maquina windows del propio dominio:
### Explotar S4U2Self y S4U2Proxy con Rubeus.exe:

- [[Rubeus#Explotación de S4U2Self y S4U2Proxy]]


O, alternativamente desde Linux:

### Explotar S4U2Self y S4U2Proxy con getST.py (de impacket):

- [[Impacket-getST#Explotar S4U2Self y S4U2Proxy]]

# S4U2Self

El ataque **S4U2Self** (Service-for-User-to-Self) no es un ataque en sí mismo, sino una extensión del protocolo Kerberos que, cuando se abusa, permite a un atacante obtener un TGS (Ticket Granting Service) para un usuario arbitrario hacia un servicio que el atacante controla.

El abuso ocurre porque, mediante S4U2Self, cualquier cuenta que tenga un **Service Principal Name (SPN)** puede solicitar un ticket para **cualquier usuario** (incluyendo Administradores de Dominio) hacia sí misma, siempre que el usuario no esté marcado como "Sensible y no puede ser delegado".

el ticket de S4U2Self se usa para **Escalada de Privilegios Local (LPE)**.

Imagina este escenario:

1. Tienes control de una cuenta de servicio en un servidor (ej. `IIS AppPool`).

2. Esa cuenta no es Administradora local.

3. Usas **S4U2Self** para pedir un ticket a nombre del `Administrator` del dominio hacia tu propio servicio.

4. Una vez que tienes ese ticket en memoria, puedes usarlo para interactuar con procesos locales o servicios del sistema que confían en Kerberos. Al presentarte ante el sistema operativo con un ticket de Administrador, el sistema te asigna un **Access Token** de Administrador, dándote control total sobre la máquina.


# S4U2Proxy

Si **S4U2Self** era el servicio diciendo _"mira KDC, el Administrador está aquí conmigo"_, **S4U2Proxy** es el servicio diciendo _"ahora que sabes que el Administrador está conmigo, déjame entrar a ese otro servidor en su nombre"_.

Es la segunda parte de la extensión **S4U** (Service-for-User) y es la que realmente permite el movimiento lateral.

---

## 1. El Flujo Lógico (Paso a Paso)

Para que esto funcione, el servicio solicitante (llamémoslo **Servicio A**) ya debe tener en su poder un ticket de servicio ($ST$) de un usuario (ej. **Admin**) hacia sí mismo.

1. **La Petición:** El **Servicio A** envía una solicitud `TGS_REQ` al KDC.
    
2. **La "Prueba":** En esa solicitud, incluye el ticket del **Admin** que obtuvo previamente (normalmente vía **S4U2Self**). Este ticket actúa como "evidencia" de autenticación.
    
3. **La Validación:** El KDC verifica dos cosas:
    
    - Que el ticket presentado sea **Forwardable** (reenviable).
        
    - Que el **Servicio A** tenga permisos de delegación hacia el **Servicio B** (el objetivo final).
        
4. **La Entrega:** Si todo es correcto, el KDC responde con un nuevo ticket de servicio ($ST$) que permite al **Servicio A** acceder al **Servicio B** con la identidad y privilegios del **Admin**.
    

---




