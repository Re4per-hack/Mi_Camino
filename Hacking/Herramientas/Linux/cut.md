Como dice el nombre, cut es un comando que nos permite cortar texto, para esto se define un delimitador y luego se elige el fragmento o fragmentos que se quieren mostrar, a continuación un ejemplo, digamos que tenemos un conjunto de datos separados por puntos dobles:

```
juan:22:Bogota
maria:30:santander
silvia:15:bucaramanga
pablo:23:medellin
```

Si queremos que solo muestre el nombre y el lugar de procedencia, el comando seria:

```shell
cut -d ':' -f 1,3 nombres.txt
```

```
juan:Bogota
maria:santander
silvia:bucaramanga
pablo:medellin
```

