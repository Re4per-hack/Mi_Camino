
```
FROM python:2.7
RUN sed -i 's/deb.debian.org/archive.debian.org/g; s|security.debian.org|archive.debian.org|g; /buster-updates/d' /etc/apt/sources.list
RUN apt-get update && apt-get install -y nano && rm -rf /var/lib/apt/lists/*
RUN pip install --no-cache-dir "setuptools<45" \
 && pip install --no-cache-dir "cryptography==3.3.2" \
 && pip install --no-cache-dir "impacket==0.9.22"
WORKDIR /work
CMD ["/bin/bash"]
```


