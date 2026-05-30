
- [ ] Checkear si es un docker
- [ ] Instalamos Chisel e iniciamos la configuración
- [ ] Vemos los grupos a los que pertenecemos (id)
### Si pertenecemos a algun grupo

```ruby
# Qué archivos pertenecen a ese grupo
find / -group users 2>/dev/null | grep -v proc | grep -v sys

# De esos, cuáles son writables
find / -group users -writable 2>/dev/null | grep -v proc | grep -v sys
```

- [ ] Buscamos los archivos que podemos ejecutar como root (sudo -l)
- [ ] Miramos la versión del kernel
- [ ] Miramos los servicios que están corriendo internamente  (netstat [[2. Enumeracion de red]])
- [ ] Buscamos SUIDs (find [[3. Enumeracion del usuario]])
- [ ] Usar pspy
- [ ] Ver variables de entorno (`env`)
- [ ] Carpetas sensibles editables  (find /opt /var /tmp -writable -type d 2>/dev/null)
- [ ] buscar tareas cronologicas (/etc/cronjob o /etc/cron.d)






