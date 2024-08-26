Para buscar las redes debemos activar previamente el [[Modo monitor de la antena]] para realizar este escaneo de redes, el cual se hace de la siguiente manera

	sudo airodump-ng {INTERFAZ_DE_RED}

Ahora con el canal (ch) y el BSSID debemos iniciar un escaneo de la red para saber que dispositivos están conectados a ella

	sudo airodump-ng --bssid {BSSID_DE_LA_RED} --channel {EL_CANAL_EN_EL_QUE_ESTÁ_LA_RED}

A este punto solo necesitamos buscar cuales son los dispositivos conectados a esta red