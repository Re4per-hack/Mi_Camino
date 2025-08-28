

## AD CS (Active Directory Certificate Service)

Active Directory Certificate Service es un **rol de servidor de Windows** así como el AD DS (Active Directory Domain Service), podemos ver estos roles como servicios o "trabajos" designados a diferentes servidores, IMPORTANTE: un mismo servidor puede tener varios de estos roles, por ejemplo un mismo servidor puede ser el DNS (Domain  Name Service) un DHCP (Dynamic Host Configuration Protocol Server)

Este rol de servidor permite hacer una estructura adecuada para la administracion de certificados.


## AD CA (Active Directory Certificate Authority)


Es la entidad entro de AD CS que se encarga de emitir, revocar y validar  certificados, a continuacion un ejemplo 


|Concepto|¿Qué es?|¿Qué función cumple?|¿Ejemplo?|
|---|---|---|---|
|**AD CS** (Active Directory Certificate Services)|Es el **rol de servidor** en Windows.|Proporciona la infraestructura para emitir, administrar y validar certificados digitales.|Es como instalar "la fábrica" de certificados.|
|**CA** (Certificate Authority)|Es una **entidad dentro del rol AD CS**.|Es la encargada de **emitir, revocar y validar** certificados.|Es como la "máquina" dentro de la fábrica que firma los certificados.|
