## Bypass de validación de subida — COMPLETO

### 1. Validación solo en cliente (JavaScript)

- [ ] ¿Es validacion por Front-End? Intercepta con Burp y sube el archivo real tras pasar la validación — [HackTricks: File Upload](https://hacktricks.wiki/en/pentesting-web/file-upload/index.html)

### 2. Validación por Content-Type / MIME

- [ ] Cambia el header `Content-Type` a uno permitido (`image/jpeg`, `image/png`, `image/gif`) manteniendo el contenido malicioso — [HackTricks: File Upload](https://hacktricks.wiki/en/pentesting-web/file-upload/index.html)
- [ ] Prueba con doble header `Content-Type` o `Content-Type` con charset raro
- [ ] Si valida por `getimagesize()` / magic bytes, falsifica la cabecera (`GIF89a;`, `%PDF-`, magic PNG) al inicio del archivo — [Lista de firmas de archivo](https://en.wikipedia.org/wiki/List_of_file_signatures)
- [ ] Inyecta el código en el comentario de un GIF con `gifsicle` para pasar `getimagesize()` — [The Hacker Recipes: Unrestricted file upload](https://www.thehacker.recipes/web/inputs/unrestricted-file-upload)

### 3. Blacklist de extensiones (prohíbe .php, .asp…)

- [ ] Extensiones alternativas del mismo lenguaje: `.phtml`, `.php3/4/5/7`, `.pht`, `.phar`, `.inc`, `.phps` (PHP); `.aspx`, `.ashx`, `.asmx`, `.cer` (ASP); `.jsp`, `.jspx` (Java) — [PayloadsAllTheThings](https://github.com/swisskyrepo/PayloadsAllTheThings/blob/master/Upload%20Insecure%20Files/README.md)
- [ ] Mayúsculas/minúsculas variadas: `.pHp`, `.PhAr`, `.AsPx`
- [ ] Dobles extensiones: `shell.php.jpg` / `shell.jpg.php`
- [ ] Extensión ejecutable ANTES de la válida en Apache mal configurado (`shell.php.png` ejecuta si `AddHandler` asigna handler por cualquier extensión — el caso de **Networked**) — [HackTricks: File Upload](https://hacktricks.wiki/en/pentesting-web/file-upload/index.html)
- [ ] Caracteres finales que se recortan al guardar: punto final `shell.php.`, espacio final `shell.php `, `shell.php%20`, `shell.php%0a`, `shell.php%0d`, `shell.php%09`, `shell.php/` — [OWASP: Unrestricted File Upload](https://owasp.org/www-community/vulnerabilities/Unrestricted_File_Upload)
- [ ] Null byte entre extensiones: `shell.php%00.jpg` (PHP/sistemas antiguos) — [OWASP: Embedding Null Code](https://owasp.org/www-community/attacks/Embedding_Null_Code)
- [ ] **IIS ≤6**: punto y coma `shell.asp;.jpg` (se ejecuta como .asp) — [Bypass File Upload Restrictions (ref)](https://github.com/swisskyrepo/PayloadsAllTheThings/blob/master/Upload%20Insecure%20Files/README.md)
- [ ] **Windows/NTFS**: Alternate Data Streams `shell.php::$DATA`, `shell.aspx::$DATA`, o `file.asax:.jpg` — [OWASP: Unrestricted File Upload](https://owasp.org/www-community/vulnerabilities/Unrestricted_File_Upload)
- [ ] Caracteres Unicode/homoglifos que parecen puntos o letras válidas: punto Unicode (U+2024), middle dot (U+00B7), o RTLO (U+202E) para invertir visualmente la extensión — [Hackviser: File Upload](https://hackviser.com/tactics/pentesting/web/file-upload)
- [ ] Truncamiento por longitud de nombre: rellena con `A`*N hasta el límite del sistema para que la extensión válida se corte (`AAAA…AAA.php.png` → se guarda como `.php`) — [VeryLazyTech: File Upload](https://www.verylazytech.com/file-upload-vulnerabilities)

### 4. Whitelist de extensiones (solo permite .jpg, .png…)

- [ ] Combina whitelist + Apache misconfig: `shell.php.png` (permitido por sufijo, ejecutado por handler)

- [ ] Null byte `%00` / caracteres de control para que la parte válida engañe al validador pero se guarde la ejecutable

### 5. Reprocesamiento / recompresión de imagen
- [ ] ¿El backend recomprime con PHP-GD? Embebe la shell en el chunk IDAT para que sobreviva a `imagecopyresized`/`imagecopyresampled` — [Bypass PHP-GD to RCE (RickGray)](https://github.com/RickGray/Bypass-PHP-GD-Process-To-RCE)
- [ ] Polyglots: archivo que es válido como imagen Y como script/PHAR a la vez — [Polyglot Files: A Hacker's Best Friend](https://medium.com/swlh/polyglot-files-a-hackers-best-friend-850bf812dd8a)

### 6. Reconfigurar el servidor vía la propia subida
- [ ] Subir `.htaccess` (Apache) con `AddType application/x-httpd-php .png` para registrar extensiones ejecutables — requiere `AllowOverride` — [PayloadsAllTheThings](https://github.com/swisskyrepo/PayloadsAllTheThings/blob/master/Upload%20Insecure%20Files/README.md)
- [ ] Subir `web.config` (IIS) para habilitar ejecución — [Soroush Dalili: web.config upload](https://soroush.secproject.com/blog/2014/07/upload-a-web-config-file-for-fun-profit/)

### 7. Lógica de guardado / condiciones de carrera

- [ ] Path traversal en el nombre (`../../var/www/html/shell.php`) para escribir fuera del directorio previsto — [HackTricks: File Upload](https://hacktricks.wiki/en/pentesting-web/file-upload/index.html)
- [ ] Sobrescribir archivos existentes subiendo con nombre en conflicto (config, `.htaccess`, otra shell)
- [ ] **Race condition (TOCTOU)**: sube y ejecuta el archivo en la ventana entre que se guarda y se valida/borra — [HackTricks: File Upload](https://hacktricks.wiki/en/pentesting-web/file-upload/index.html)
- [ ] **Nginx + `cgi.fix_pathinfo=1`**: `shell.jpg/x.php` o `shell.jpg/.php` fuerza a PHP a ejecutar la imagen — [HackTricks: File Upload](https://hacktricks.wiki/en/pentesting-web/file-upload/index.html)
