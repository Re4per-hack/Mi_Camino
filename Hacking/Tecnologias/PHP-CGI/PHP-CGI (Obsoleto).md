Cuando estamos hablando de ejecutar codigo php en una pagina web, tenemos que entender tanto que es PHP-FPM (Actual) vs PHP-CGI (Anticuado) ambos de estos conceptos estan relacionados a como es que PHP se integra en servidores apache o nginx:

# PHP-FPM

Este es el caso mas común, ya que es la versión actual de como ejecutar codigo php en servidores web, para llevar a cabo esta tarea, hay un proceso que sería el propio php-FPM corriendo como un daemon (Tarea en segundo plano), cuando el cliente que consulta la pagina pide acceder a **index.php**,  el servidor (Nginx o Apache2) envia una petición a FastCGI el cual por ultimo envia el php a php-FPM  para ser ejecutado, y va a devolver su representativo en html.

# PHP-CGI

Esto es basicamente un simple binario al que se le pasan los php para ser ejecutados, y se ejecutan directamente, es decir, no hay un daemon, solo el puro binario al que se le hace una petición junto con el php a verificar, esta tecnologia ademas de estar obsoleto, hay una vulnerabilidad muy común que podemos explotar de la siguiente forma: [[PHP-CGI Explotacion]] 

