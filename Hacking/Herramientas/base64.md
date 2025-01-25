base64 es un método de codificación el cual fácilmente puede ser usado con la herramienta que contiene su mismo nombre en linux, su funcionamiento es simple, si tenemos el siguiente texto:

```
Este es mi texto
```
## Codificación 

Si queremos codificar esto en base64 lo podemos hacer de las siguientes maneras: 

```shell
echo "Este texto va a ser codificado" | base64
cat archivo.txt | base64
```

## Decodificación

Si queremos decodificar esto en base64 lo podemos hacer de las siguientes maneras

```shell
echo "RXN0ZSB0ZXh0byBlc3RhYmEgY29kaWZpY2Fkbw==" | base64 -d
cat archivo_texto_codificado.txt | base64 -d 
```

