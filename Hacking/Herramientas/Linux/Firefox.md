
# Usar proxy para conexiones a localhost

En ocasiones tendremos que visitar alguna web a un localhost remoto  a travez de chisel usando foxyproxy, el problema es que firefox por default se salta el proxy cuando se hace una llamada al localhost (127.0.0.1), es decir, en vez de hacer la peticion en la maquina remota la hace en nosotros, lo cual es un comportamiento obviamente no esperado, para solucionar esto tenemos que configurar un par de cosas:

Debemos ir a about:config (escribir en la barra de busqueda), allí tendremos que buscar alguna de las siguientes opciones `network.proxy.allow_proxying_localhost` o en versiones mas recientes de firefox `network.proxy.allow_proxying_localhost`, sea cual sea su nombre tiene que estar en ***`true`*** : 

![[Pasted image 20260425213435.png]]

Ahora, en foxyproxy la configuración debe ser la siguiente:

![[Pasted image 20260425213903.png]]

Listo!, ya tenemos una herramienta con la que podemos cmabiar facilmente entre la conexión tunelizada o directa!!

