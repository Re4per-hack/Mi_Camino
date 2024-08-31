
# Encriptación

Los hashes salted no son mas que coger una contraseña y concatenarle antes o despues alguna otra palabra, hash, numeros o lo que sea haciendo a este hash mas "robusto", aqui un gran ejemplo, aun asi intentare ser mas especifico, para simplificar todo esto usare MD5:

- A continuación hare una encriptación normal:

```bash
echo "supercontraseña" | md5sum
Resultado: bbd9501c57aab081e5ad6f31be039259
```

¿Simple verdad?

- Bueno, ahora les mostrare el proceso de hacer un "hash salted", para esto vamos a definir que la contraseña va a ser "supercontraseña" y el salt va a ser "asn224hjv2cx34", y listo, eso es todo lo que necesitamos

```bash
echo "asn224hjv2cx34supercontraseña" | md5sum
Resultado: 19bbc58c45ef8edd758cfe5210cf24e7
```

¡¡Es exactamente lo mismo!!, pero tu te preguntaras, entonces ¿para que existe el concepto de "salted" si es el mismo proceso de encriptación?, bueno, pues porque algunas paginas/empresas almacenan sus contraseñas de la siguiente manera:

- Creas una cuenta y le pones de contraseña "pepitopassword"

- La pagina en el Back-End crea un salt único para ti (o usa el mismo para todos, lo cual es muy poco probable por ser inseguro)

- En el Back-End se junta el salt con la contraseña, puede ser al inicio o al final, el punto es que los junta

- El Back-End lo encripta con el respectivo método ( En este caso MD5) 

- El servidor solo se queda con tu usuario, el salt y la contraseña

- Ahora la proxima vez que accedas a la pagina donde registraste estas credenciales, la pagina cogerá la contraseña que pongas, la juntara con el salt que definió para ti, lo encriptara, y lo va a comprar con el hash de tu respectivo usuario

Esto tiene varias razones, pero mencionare las mas importantes:

- Mayor seguridad: si tu como atacante no tienes acceso al salt básicamente estas jo\*\*do a no ser que el salt sea alguna palabra comun, y aun asi tardarías mucho en crackearlo 

- Evita conflictos de contraseñas: la verdad esto es para casos mas puntuales, porque total, tienes que definir un usuario, pero quien sabe, puede ser util para que solo accedas con una contraseña



# Desencriptación

En el caso de la Desencriptación, se recomienda altamente saber el salt del hash, puedes hacer fácilmente con un codigo en python, pero no me pondré muy técnico aquí ya que no es nada complicado y lo explico en la seccion  [Desencriptado en python](/Lenguajes/Python/Desencriptado%20en%20python), pero en resumen solo basta con sumar el salt, antes o después de una palabra de un wordlist, encriptarlo y compararlo, si no funciona pues se repite el proceso pero con la siguiente linea del wordlist. 

## HashCat

Por alguna razón cuando intente desencriptar un hash salted en MD5 tuve que hacerlo al revés, es decir, hashcat tiene dos modos de desencriptacion cuando se trata de MD5 salted:

- Modo 10: Que es para hashes que hayan sido encriptados en MD5 asi Hash/Salt

Y

- Modo 20: Para hashes que hayan sido encriptados en MD5 asi Salt/Hash

Bueno pues en mi caso mi hash habia sido encriptado de la primera forma (Modo 10), pero por alguna razón no funcionaba, ni aunque lo invirtiera, pero cuando hice el (Modo 20) si funcionó, todo muy raro, por eso prefiero hacer todo manual, incluso cosas asi de simples, para evitar problemas :/, aun asi es muy util HashCat, yo te recomendaria que cuando crackees una contraseña utilices HashCat y si no funciona puedes intentar con john the reapper y si tampoco funciona pues usa tu propio script en python

- Guia: [[HashCat]]
- Guia: [[John The Ripper]]



