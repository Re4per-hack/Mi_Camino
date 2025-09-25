Hay varias formas de conseguir un RCE a partir de un LFI, especialmente con php:

- Log poisoning 
- Bases de datos
- A partir de [[PHP_Wrappers]]
- O a partir de plugins, que puedan agregar nuevos wrappers utiles

Entre estos tenemos:

- ssh2.shell://user:pass@example.com:22/xterm

- ssh2.exec://user:pass@example.com:22/bash -c "..."

- ssh2.tunnel://user:pass@example.com:22/192.168.0.1:14

- ssh2.sftp://user:pass@example.com:22/path/to/filename

Recordemos que con el simple uso de estos wrappers por parte del servidor ya se van a ejecutar, la tarea en la que se usan no tiene porque ser exitosa, solo basta con su uso.






