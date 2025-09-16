Cuantos estamos atacando un servidor cuyo nucleo de app web es potenciado por NextJS es fundamental tener en cuenta la estructura de este para hacernos a la idea de como obtener archivos si conseguimos un LFI.

## Encontrar raíz del proyecto

Al ser la raiz, con estar en cualquier parte del proyecto deberíamos poder leerlo haciendo path traversal (../../../) o directamente probar archivos de esta raíz

 Podemos intentar ver el archivo package.json, el cual está en la raíz del proyecto, acompañado de otros archivos como: 

![[Pasted image 20250916061518.png]]

Si podemos leer este archivo es porque efectivamente estamos en la raiz del proyecto, y no solo eso, también nos dice las versiones de los packetes que se están usando, por lo que podemos llegar a encontrar vulnerabilidades, pero en caso de no encontrar nada lo que mas nos importa es ==***la carpeta .next== 

## Enrutamiento en Next

### Raíz del proyecto

```ruby
my-next-app/
├── app/
│   ├── layout.js        // Root Layout
│   ├── page.js          // Home Page
│   ├── about/
│   │   ├── layout.js    // /about About page
│   │   └── page.js      // /about 
│   ├── blog/
│   │   ├── layout.js    // /blog Layout
│   │   ├── page.js      // /blog List Page
│   │   └── [slug]/
│   │       └── page.js  // /blog/:slug Details Page
│   └── dashboard/
│       ├── layout.js    // /dashboard Loyout
│       └── page.js      // /dashboard Page
├── public/
│   ├── logo.png         // Static Resources
│   └── favicon.ico      // Web Site Icon
├── node_modules/        // Project Dependences
├── package.json         // Project configuration file
├── next.config.js       // Next.js Configuration file
└── .next/               // Build the output directory (!!IMPORTANTE)
```


### Directorio .next

```ruby
/app/.next
├── build-manifest.json      # Packing file list
├── prerender-manifest.json  # Pre-render page list
├── server/
│   ├── pages/               # Server-Side rendering Code (SSR)
│   │   └── api/             # Back-end implementation of API routing 
│   └── app/                 # Back-end implementation of App router (Next.js 13+)
├── static/
│   └── chunks/              #  Packaged JS code
├── cache/                   # Copilation Cache
└── routes-manifest.json     # Routing Configuration (!!IMPORTANTE!!)

```


