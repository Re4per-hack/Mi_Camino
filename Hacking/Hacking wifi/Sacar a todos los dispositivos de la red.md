Para mi sorpresa cuando me adentre en el mundo de el Hacking Wifi pensaba que solo se podia sacar a un usuario a la vez de una red wifi, como maximo a todos los de una red, eso hasta que me entere que es posible sacar a todos los dispositivos de todas las redes al rededor, claro, si el adaptador de red y los componentes del computador lo permiten, ¡Pero es posible!

(Solo hablare de herramientas "automatizadas" ya que realmente hay varias cosas que se tienen que hacer y no están tan automatizadas, igualmente me propondré como tarea crear un script que haga estas cosas)

Para sacar a un dispositivo de una red:

	sudo aireplay --deauth 0 -e {MAC_DEL_DISPOSITIVO} -a {BSSID_DE_LA_RED} {INTERFAZ_DE_RED_A_USAR}

