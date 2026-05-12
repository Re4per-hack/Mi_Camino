PowerView es una herramienta de reconocimiento para entornos Active Directory.

---

### Qué es

Es un módulo de PowerShell que forma parte de PowerSploit y actualmente de PowerShell Empire. Se usa en pentesting y red team para enumerar información de un dominio de Windows sin necesidad de herramientas externas.

---

### Para qué sirve

- Enumerar usuarios, grupos y computadoras del dominio
- Identificar relaciones de confianza entre dominios
- Encontrar ACLs mal configuradas
- Buscar delegaciones vulnerables para ataques como RBCD
- Identificar usuarios con privilegios elevados
- Encontrar sesiones activas y dónde están logueados los administradores

# Instalación

```ruby
. ./PowerView.ps1
```

# Explotación

#### Buscar parametros  especificos

```ruby
Get-DomainComputer DC | select {Parametro1},{PArametro2}
```