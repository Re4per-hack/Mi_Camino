

```python

```


- **`ldapsearch`**: Es la herramienta estándar para consultar servidores que utilizan el protocolo LDAP (como los Controladores de Dominio de Windows).

- **`-h {DOMINIO}`**: Especifica el **Host**. Aquí pones la dirección IP o el nombre de dominio de la máquina objetivo (ej. `10.129.39.222`).

- **`-x`**: Activa la **Autenticación Simple**. En este contexto, le dice al servidor que intente una "Simple Bind". Si el servidor permite consultas anónimas (muy común en máquinas _Easy_ de HTB), te dará información sin pedirte usuario ni contraseña.

- **`-s base`**: Define el **Scope** (alcance) como "base". Esto significa que solo quieres consultar el objeto raíz del servidor, no todas las subcarpetas o usuarios (lo cual ahorra tiempo y evita ruido).

- **`namingcontexts`**: Este es el atributo específico que le estás pidiendo al servidor.