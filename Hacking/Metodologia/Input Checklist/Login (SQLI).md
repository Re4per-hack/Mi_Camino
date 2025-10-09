Usualmente cuando estamos frente a un login, podemos intentar probar un SQL Injection, pero primero debemos confirmar la vulnerabilidad, para ello podemos injectar una comilla simple: `'` que deberia causar un error en el servidor, posteriormente ya podremos probar diferentes injecciones como: 

```sql
'-- -
```


