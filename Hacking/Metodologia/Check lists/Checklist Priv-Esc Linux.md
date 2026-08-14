
- [x] Checkear si es un docker
- [x] Miramos los servicios que están corriendo internamente  (netstat [[2. Enumeracion de red]]) `netstat -tl` o `netstat -tulnp`
- [x] Buscamos servidores activos 
- [x] Instalamos Chisel e iniciamos la configuración
- [x] Vemos los grupos a los que pertenecemos (id)
### Si pertenecemos a algun grupo

```ruby
# Qué archivos pertenecen a ese grupo
find / -group internal 2>/dev/null | grep -v proc | grep -v sys

# De esos, cuáles son writables
find / -group adm -writable 2>/dev/null | grep -v proc | grep -v sys
```

- [x] Buscamos los archivos que podemos ejecutar como root (sudo -l)
- [x] Miramos la versión del kernel
- [x] Buscamos SUIDs (find [[3. Enumeracion del usuario#==Archivos SUID==]])
- [x] Usar pspy
- [x] Ver variables de entorno (`env`)
- [x] Carpetas sensibles editables  (find /opt /var /tmp -writable -type d 2>/dev/null)
- [x] buscar tareas cronologicas (/etc/cronjob o /etc/cron.d)

 ***Si se encuentra python 2.7  [[Checklist Priv-Esc con Python]]
















