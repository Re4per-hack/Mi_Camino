Antes de conectar nuestra antena tenemos que matar los procesos conflictivos, para esto vamos a usar:

	sudo wifite --kill

Naturalmente estos procesos conflictivos suelen ocurrir por el NetworkManager, pero por las dudas y evitar quebraderos de cabeza usaremos wifite para que lo haga automaticamente, cuando el comando se haya completado conectamos la antena y podemos la antena en modo monitor usando:

	sudo wifite wlan0

