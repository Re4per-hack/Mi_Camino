Kubernetes es una tecnologia que permite administrar contenedores (Tipo Docker) orquestandolos, lo que significa que los diferentes contenedores se complementan y funcionan juntos entre si, esto permite que debido a su separacion por nodos, mientras uno esté activo los otros se actualicen o vicerversa, este entre uno de sus muchos usos, Estos son los elementos que nos podemos encontrar en el contexto de kubernetes:

![[Pasted image 20251112132943.png]]

- **Cluster:** Un Cluster es un grupo de diferentes NODOS 

- **NODO:** Los cuales se pueden llamar MASTER o WORKER, dependiendo de que función tenga el determinado nodo.

- **POD**: Está dentro del nodo y suele contener solo un container,  aunque pude contener mas

- **Container:** Esto es literalmente un contedor de tipo Docker, que se va a encargar de correr el proceso que se necesite, como una aplicación web.

![[Pasted image 20251110094416.png]]

# Nodos master

Un nodo master o control plane, contiene el API server, que es basicamente el punto de control, no importa cuantos nodos Masters hayan, se puede usa la API de cualquiera de estos nodos, no va a haber una confusión interna porque todos los datos se sincronizan con lo mismo, el ETCD, la base de datos en kubernetes.

Resumen: Los nodos master administran los nodos Worker

# Nodos Worker

Como dice el nombre, los nodos Worker son aquellos que se encargan de trabajar, o en otras palabras, de almacenar y correr los contenedores que van a tener la app final, se usa el API-SERVER (kubectl) para administrar estos nodos.

En nuestor caso podemos interactuar con el API-SERVER atraves de API REST.




