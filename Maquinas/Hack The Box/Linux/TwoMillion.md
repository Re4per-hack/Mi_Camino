
IP: 10.10.11.221
OS: Linux
Puertos: 80, 22 

# Escaneo

```shell
sudo nmap -p- 10.10.11.221 --min-rate 5000 -Pn -n -sS --open 
```

![[Pasted image 20260103124230.png]]

```shell
sudo nmap -p22,80  10.10.11.221 -T5 -sCV -vvv 
```

![[Pasted image 20260103125603.png]]

Agregamos el dominio 2million.htb a **`/etc/hosts`**: 

![[Pasted image 20260103144119.png]]



![[Pasted image 20260103144453.png]]