Para empezar vamos a iniciar el neo4j con el siguiente comando:

```python
sudo neo4j start
```

Ahora haremos lo siguiente para eliminar la salida de bloodhound hacer que el proceso no dependa de la terminal en la que es ejecutado:

```python
bloodhound &>/dev/null &
```

- **bloodhound**: Ejecuta la herrmaienta

- **&>/dev/null**: Reenvia el stdin y el stdout hacia /dev/null (lo elimina)

- **&**: hace que el proceso corra en segundo plano

Aun sigue dependiendo de la terminal, así que vamos a hacer que esto se convierta en un proceso padre (en vez de un proceso hijo de la consola):

```python
disown
```



