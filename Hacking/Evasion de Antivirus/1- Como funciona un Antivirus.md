Para entender como burlar un antivirus, primero es necesario entender como estos funcionan y las diferentes metodologías que estos tienen para evitar que un atacante entre a una maquina, una lista de estas metodologías es la siguiente: 

1. **Signature-Based Detection**: Digital Signatures-Based, también conocido en español como firmas digitales es cuando un antivirus compara partes de un archivo, comando, etc... en una base de datos de posibles amenazas 

2.  **Heuristic Analysis**: En este caso el Antivirus analiza la estructura del código antes de ejecutarlo en busca de partes que tengan comportamientos sospechosos, un ejemplo de esto es una instrucción de dumpear la SAM

3. **Runtime Analysis (Behavioral)**: Este método de análisis es cuando se han pasado las medidas ya mencionadas, el antivirus va a estar pendiente de las acciones que tiene el programa en cuestión, y si hay alguna accion sospechosa (Leer archivos delicados, ) se enviará el programa a cuarentena para evaluar mejor el comportamiento

4. **Memory Analysis**: En este caso, el antivirus busca en la memoria patrones de shellcode mal intencionado

Para cada una de estas metodologías de análisis hay diferentes técnicas que nos pueden ayudar a evadir antivirus como el Windows Defender, empecemos a hablar de ciertos procesos de los que tendremos que hacernos cargo.




