
Es una característica de Windows que te permite **correr Linux directamente dentro de Windows**, sin necesidad de una máquina virtual separada ni de hacer dual boot.
#### WSL2

```
┌─────────────────────────────────┐
│         Windows (host)          │
│  ┌───────────────────────────┐  │
│  │   Hyper-V (hipervisor     │  │
│  │   integrado en Windows)   │  │
│  │  ┌─────────────────────┐  │  │
│  │  │  Kernel de Linux    │  │  │
│  │  │  (solo el núcleo,   │  │  │
│  │  │  sin escritorio)    │  │  │
│  │  └─────────────────────┘  │  │
│  └───────────────────────────┘  │
└─────────────────────────────────┘
```

- Solo virtualiza el **kernel** de Linux, nada más
- No hay escritorio, no hay GUI, no emula hardware
- Arranca en segundos, consume muy poca RAM


