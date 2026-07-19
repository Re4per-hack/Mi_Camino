Esta función es el equivalente a el grep en linux, un ejemplo de uso puede ser el siguiente:

```ruby
systeminfo | findstr /B /C:"OS Name" /C:"OS Version" /C:"System Type"
```

- `/B:` Solo lo toma si la coincidencia está al inicio de la linea.
- `/C:` Se usa para indicar la coincidencia a buscar.
