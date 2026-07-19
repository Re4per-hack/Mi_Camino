Kerberos se constituye de un KDC (Key Distribution Center) el cual a su vez contiene dos servidores AS (Authentication Server)  y  TGS (Ticket Granting Server), aparte de esto tenemos un SPN (Service Principal Name) esto es un nombre identificativo para una maquina, la cual será usada como un servicio, es fundamental para que se use el proceso Kerberos para autenticarse a cierta maquina, la estructura se vería algo así:

![[Pasted image 20250424065810.png]]

Ahora hablemos de como funciona paso a paso la autenticación, dejaré una imagen y la explicaré a continuación:

![[Pasted image 20250426191205.png]]

Este es el AS-REQ (La peticion del TGT, es decir, el primer paso)

```json

AS_REQ = {
  pvno:5, msg-type:KRB_AS_REQ,
  padata: [PA-ENC-TIMESTAMP],  // preautenticación opcional
  req-body: {
    kdc-options: { forwardable, proxiable, … },
    cname: usuario@EJEMPLO.COM,
    realm: EJEMPLO.COM,
    sname: krbtgt/EJEMPLO.COM@EJEMPLO.COM,
    till: 2037-09-13T02:48:05Z,
    nonce: 12345678,
    etype: [AES256-CTS-HMAC-SHA1-96, AES128-CTS-HMAC-SHA1-96],
    addresses: [192.0.2.100]
  }
}
```

Según la especificación RFC 4120, este mensaje **no viaja cifrado** en la red. Es posible incluir datos de _pre-autenticación_ (padata), como un timestamp cifrado con la clave del usuario (PA-ENC-TIMESTAMP), para demostrar la posesión de la contraseña sin enviarla directamente. En resumen, el AS-REQ informa al KDC _quién_ pide autenticarse y qué ticket desea, sin revelar la contraseña del usuario

Este es el AS-REP


`AS-REP (KRB_AS_REP): Contiene:`

- `crealm, cname: reino y nombre del cliente autenticado.`
    
- `ticket: el TGT cifrado con la clave del TGS.`
    
- `enc-part (EncASRepPart): cifrado con la clave del usuario; incluye:`
    
    - `key: la clave de sesión K<sub>C,TGS</sub>.`
        
    - `authtime: hora de emisión.`
        
    - `endtime / renew-till: tiempos de validez del TGT.`
        
    - `flags: banderas del ticket.`
        
    - `sname, srealm: servicio del ticket (krbtgt/REALM).`
        
    - `caddr: direcciones IP validadas.`


https://www.kerberos.org/software/tutorial.html