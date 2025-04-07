La SameSite cookie, como dice el nombre, es una cookie que define el comportamiento que va a tener nuestro navegador respecto a cuando enviar las otras cooies y cuando no (por ejemplo la session cookie), esto puede ayudar a evitar CSRF attacks, ejemplo:

Estamos en una pagina que vamos a llamar pagina1.com, y esta pagina tiene una función que nos redirige automáticamente hacia pagina2.net, ahora, nosotros tenemos una session cookie en pagina2.com, vamos a ver que pasa segun el valorq ue tenga la SameSite Cookie:

- SameSite=None: En este caso, sea una peticion GET o POST la que se haga desde pagina1.com, se va a enviar la session cookie

- SameSite=Lax: En este caso, solo se enviará la session cookie siempre y cuando sea una petición GET de Top Level, (como darle click a un link), de caso contrario no se enviará la session cookie

- SameSite=Strict: En este caso, no se enviará la session cookie ya que la petición proviene de un sitio que es pagina2.com, es decir, no es SameSite (del mismo sitio)

## Navegadores cuando la SameSite cookie no es definida por el servidor

Con esto me refiero a que muchas veces los servidores no definen explícitamente que valor desean que tenga la SameSite cookie, en este caso pasa lo siguiente:

- La SameSite Cookie estará con valor None

- 2 minutos despues de que el servidor haya definido una cookie sin definir la SameSite cookie (como una session cookie) el navegador automáticamente la convertirá de None a Lax
