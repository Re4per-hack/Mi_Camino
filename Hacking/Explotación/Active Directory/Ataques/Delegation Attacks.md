
La Delegación es una función que permite que un servicio (como un servidor web) **suplante** a un usuario para acceder a otro servicio (como una base de datos) en su nombre.

Estos ataques basicamente se basan en una funcionalidad de windows llamada delegation, la cual permite que un SPN haga peticiones a otro SPN haciendose pasar por cualquier usuario.

Se sabe que es vulnerable cuando tenemos acceso a una cuenta con permisos de delegacion a un SPN, pudiendo hacer movimiento lateral.

# Constrained Delegation Attack

La razón por la que este ataque se tiene en el nombre "constrained" (restringido), es porque el SPN del que tenemos control solo puede autenticarse como x usuario hacia el SPN especificado en el parametro msDS-AllowedToDelegateTo de la cuenta que va a hacer la delegacion (El SPN que se hace pasar por otro usuario).


Aqui es cuando entran las extensiones [[S4U2Self y S4U2Proxy]], en las que terminamos obteniendo un TGS para un servicio especifico (tiene que estar en el parametro msDS-AllowedToDelegate)

## Explotación

-------------
# Unconstrained Delegation Attack





-------------
# Resource-Based Constrained Delegation Attacks 

En este caso el ataque es alreves, el servidor al que se va a hacer la peticion final (es decir, el objetivo) contiene una lista de las cuentas de servicio autorizadas para delegar en este recurso, esta lista se especifica en el atributo del objeto: ***`msDS-AllowedToActOnBehalfOfOtherIdentity`***.

El caso mas común para usar esta función en ataque es cuando tenemos acceso Administrativo, como GenericAll o GenericWrite  sobre el servidor en el que queremos subir nuestros privilegios.

## Explotación

En este caso tengo permisos GenericAll sobre el servidor DC, esto significa que puedo cambiar el atributo ***`msDS-AllowedToActOnBehalfOfOtherIdentity`*** permitiendo que haga un ataque de delegacion desde cualquier cuenta que pueda hacer un S4U2Proxy, recordemos que **Solo las cuentas con SPN pueden hacer un S$U2Proxy**, esto aqui es importante porque en mi caso no tengo privilegios sobre ninguna cuenta como para crearle un SPN, por lo que haré lo que se hace siempre y es incluso mas simple que asignar un SPN, y es basicamente crear una cuenta de maquina, las cuentas de maquina vienen con varios SPNs asignados por defecto, es importante que el parametro **``msDS-MachineAccountQuota``** no sea 0, porque en ese caso no podriamos crear cuentas de maquina:

### Revisar MachineAccountQuota (Dentro del DC)

```ruby
Get-ADObject -Identity ((Get-ADDomain).distinguishedname) -Properties ms-DSMachineAccountQuota
```


![[Pasted image 20260510143020.png]]

Hay un cupo de 10 maquinas, por lo que ahora podemos pasar al sigueinte paso

### Revisar el parametro msDS-AllowedAoActABehalfOfOtherIdentity 

Tenemos que ver si esta vacio este atributo, porque dependiendo de eso cambia la forma del ataque:

**Si está vacío:** Puedes escribir directamente sin problema. Es el escenario ideal para el ataque.

**Si ya tiene un valor:** Puedes sobreescribirlo si tienes permisos de escritura sobre el objeto. El atributo acepta ser modificado si tienes los permisos necesarios.


Para esto vamos a usar [[PowerView]] un Modulo de Powershell usado para enumerar información del dominio:

```ruby
. ./PowerView.ps1
```

Ahora con  `Get-DomainComputer DC` 

```ruby
Get-DomainComputer DC | select name, msds-allowedtoactonbehalfofotheridentity
```

Crearemos la cuenta de maquina usando [[PowerMad]]:

```ruby
New-MachineAccount -MachineAccount FAKE-COMP01 -Password $(ConvertTo-SecureString 'Password123' -AsPlainText -Force)
```

Vamos a comprobar que si se haya creado la cuenta de maquina (Machine Account):

```ruby
Get-ADComputer -identity FAKE-COMP01
```

Vamos a setear esta cuenta de maquina en el parametro **`msDS-AllowedAoActABehalfOfOtherIdentity`** para que confie en esa maquina falsa, para eso usamos el parametro **``PrincipalsAllowedToDelegateToAccount``** que basicamente traduce la cuenta de maquina en el Security Descriptor, que es lo que finalmente se guarda en **`msDS-AllowedAoActABehalfOfOtherIdentity`**: 

```python
Set-ADComputer -Identity DC -PrincipalsAllowedToDelegateToAccount FAKE-COMP01$
```

Ahora comprobemos que efectivamente el parametro **`msDS-AllowedAoActABehalfOfOtherIdentity`** tenga este valor:

```r
Get-ADComputer -Identity DC -Properties PrincipalsAllowedToDelegateToAccount
```

Vemos que aparece con el nombre de **``PrincipalsAllowedToDelegateToAccount``**, no es que sea un parametro diferente, es que es la traduccion del security descriptor que hay en **`msDS-AllowedToActABehalfOfOtherIdentity`**:

![[Pasted image 20260510172521.png]]

Ahora podemos hacer un ataque S4U2Self y S4U2Proxy para obtener el  TGS del usuario administrator para el SPN que nos interesa vulnerar, en este caso *`cifs/dc.support.htb`*:

[[S4U2Self y S4U2Proxy]]











