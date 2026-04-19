# Database "Bloodhound" does not exist


![[Pasted image 20260417081521.png]]

Ese error de **"collation version mismatch"** es un clásico cuando se actualiza el sistema (Kali Linux) y la base de datos de PostgreSQL se queda con una versión de librerías vieja (en este caso, espera la 2.41 y tienes la 2.42). Esto impide que `bloodhound-setup` cree la base de datos necesaria.

```sql
sudo -u postgres psql -c "ALTER DATABASE postgres REFRESH COLLATION VERSION;"
```

```sql
sudo -u postgres psql -c "ALTER DATABASE postgres REFRESH COLLATION VERSION;"
```


