```python
#!/usr/bin/env python3
import hashlib
from multiprocessing import Pool, cpu_count

def check_password(password):
    try:
        computed = hashlib.pbkdf2_hmac(
            'sha256',
            password,
            SALT.encode(),
            ITERATIONS
        )
        if computed.hex() == TARGET_HASH:
            return password.decode(errors="ignore")
    except:
        pass
    return None


# ---- Hash components ----
SALT = "AMtzteQIG7yAbZIa"
ITERATIONS = 600000
TARGET_HASH = "0673ad90a0b4afb19d662336f0fce3a9edd0b7b19193717be28ce4d66c887133"

# ---- Your wordlist path ----
WORDLIST = "/usr/share/wordlists/rockyou.txt"


def main():
    print(f"[+] Using wordlist: {WORDLIST}")
    print("[+] Starting PBKDF2-SHA256 cracking...")

    with open(WORDLIST, "rb") as f:
        passwords = (line.strip() for line in f)

        with Pool(cpu_count()) as pool:
            for result in pool.imap_unordered(check_password, passwords, chunksize=500):
                if result:
                    print(f"[+] PASSWORD FOUND: {result}")
                    pool.terminate()
                    return

    print("[-] No match found.")


if __name__ == "__main__":
    main()

```

### 1. El Bloque de Control: `if __name__ == "__main__":`

Para entender `main()`, primero debes entender esta línea. En Python, cada archivo tiene una variable invisible llamada `__name__`.

- **Si ejecutas el archivo directamente** (ej. `python script.py`), Python asigna el valor `"__main__"` a esa variable.
    
- **Si importas el archivo desde otro script**, la variable toma el nombre del archivo (ej. `"script"`).
    

**El propósito:** Evita que el código se ejecute automáticamente cuando solo quieres importar una función de ese archivo en otro proyecto.




