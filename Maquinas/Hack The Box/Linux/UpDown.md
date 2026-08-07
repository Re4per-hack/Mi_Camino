
Nivel: Media
Os: Linux

## Dotgit explotation / Explotación de dotgit expuesto

Cuando vemos un .git expuesto debemos usar la herramienta  git-dumper

```python
pip install git-dumper
git-dumper http://updown.htb/dev/.git/ ./updown-repo

## En caso de error

git status
```

## Wrapper `phar://` / Bypass extension (.php) agregada por backend en LFI

Cuando un LFI tiene una medida de seguridad que agrega `.php` al final de lo que pongamos y ademas no podemos subir archivos php podemos hacer uso del wrapper phar:// o tambien de filter chain php.

## Para probar RCE con LFI subir phpinfo(); en vez de system

Como system puede ser una función deshabilitada, lo ideal para probar un LFI es usar un phpinfo(); 

```python
<?php phpinfo(); ?>
```

## Determinar que funciones podemos usar para ejecutar comandos

Muchas veces algunas funciones fundamentales para ejecutar comandos están deshabilitadas como por ejemplo `system()`: 

```python
### Descargar el codigo fuente con phpinfo
curl -s http://dev.siteisup.htb/?page=phar://uploads/5e31601b65f0062e32966f2f8e94fbb0/info.0xdf/info -O phpinfo

### Extraer funciones disponibles con dfunc-bypasser 
python2 dfunc-bypasser.py --file phpinfo
```

##  Ejecutar comandos usando la función proc_open

![[Captura de pantalla 2026-07-24 a las 7.20.17 p. m..png]]

## Vulnerabilidad critica en python2

En python2 todo lo que entra por una función input se pasa a un eval(), por lo que se peude lograr ejecutar codigo python:

## 

# Errores:

- No vi el .htaccess cuando descargue el .git, porque crei que no se habia descargado 
- No busqué easy_install en gtfoBins o lo escribí mal cuando busqué
- No vi los permisos del binario siteisup (SUID)

