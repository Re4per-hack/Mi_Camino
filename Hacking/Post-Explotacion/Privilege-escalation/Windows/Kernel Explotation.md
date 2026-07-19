```ruby
# Paso 1: descargar/actualizar la base de datos (el .xls)

python windows-exploit-suggester.py --update

# Esto genera un archivo tipo: 2020-xx-xx-mssb.xls




# Paso 2: pasarle TU systeminfo + el .xls descargado
python windows-exploit-suggester.py  --database 2020-xx-xx-mssb.xls --systeminfo systeminfo.txt
```


