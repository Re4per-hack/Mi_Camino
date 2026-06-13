# Partes de un JWT 

## Raw 

```ruby
eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VySWQiOjIxNCwiZW1haWwiOiJpNG1yZTRwZXJAZ21haWwuY29tIiwicm9sZSI6ImN1c3RvbWVyIiwiaWF0IjoxNzgxMzcyMzMxLCJleHAiOjE3ODM5NjQzMzF9._zFSikk5u2NOR-gEoUWz0PBlRTy-RCvaPdWlCGw0vZA
```

## Desencodeado

```ruby
eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9 -> {"alg":"HS256","typ":"JWT"}

eyJ1c2VySWQiOjIxNCwiZW1haWwiOiJpNG1yZTRwZXJAZ21haWwuY29tIiwicm9sZSI6ImN1c3RvbWVyIiwiaWF0IjoxNzgxMzcyMzMxLCJleHAiOjE3ODM5NjQzMzF9 -> {"userId":214,"email":"i4mre4per@gmail.com","role":"customer","iat":1781372331,"exp":1783964331}

_zFSikk5u2NOR-gEoUWz0PBlRTy-RCvaPdWlCGw0vZA -> ## ENCRIPTADO ##
```

```ruby
HEADERS.PAYLOAD.SIGNING
```

# Crackeo JWT

Para esto podemos usar la herramienta 
