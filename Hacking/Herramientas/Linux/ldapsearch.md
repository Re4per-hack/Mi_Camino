
# Enumeración 


```python
ldapsearch -h {DOMINIO} -x -x base namingcontexts 
```


- **`-h {DOMINIO}`**: Especifica el **Host**.

- **`-x`**: Activa la **Autenticación Simple**. Le dice al servidor que intente una "Simple Bind". 

- **`-s base`**: Define el **Scope** (alcance) como "base".

- **`namingcontexts`**: Este es el atributo específico que le estás pidiendo al servidor.
#### Respuesta:

- `result: 0 Success` == Null Session



