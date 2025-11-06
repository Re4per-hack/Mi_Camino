Esto se cumple la mayoria de las veces, plugins vulnerables
# Detección

Podemos ver la mayoria de los plugins que se estén usando en una pagina wordpress en las etiquetas Link, igualmente podemos usar el siguiente comando para ver los plugins disponibles, y la mayoria de las veces tambien podemos ver su respectiva version:

```ruby
curl -s http://{servidor}/{WP_directory} | grep "plugin"
```

Deberiamos ver algo como esto:

![[Pasted image 20251106145050.png]]

Aquí podemos ver un plugin llamado give y que está en la version 3.14.0.


