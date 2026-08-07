OS: Linux


## Listar servidores http/https activos apache y nginx

Hay veces que encontramos archivos que dan señales de estar hosteando un servidor http, pero no sabemos en que dominio, subdominio o puerto se estan hosteando, en esos casos lo ideal es buscar en la siguiente carpeta en la cual suele haber un archivo por servidor, ademas ver que usuario esta administrando ese servicio:

```python
### En apache
ls /etc/apache2/sites-enabled
ls /etc/apache2/sites-available

## En nginx
ls /etc/nginx/sites-enabled
ls /etc/nginx/sites-available
```


## Mejor entendimiento de sudo -l

Si en sudo -l aparece algo como /bin/nano /path/to/file

Eso significa que solo peudes ejecutar con sudo  un nano hacia ese archivo en concreto.

(explotable con GTFOBins)

