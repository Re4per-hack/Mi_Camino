FROM python:2.7

```
RUN pip install --no-cache-dir "setuptools<45" \
 && pip install --no-cache-dir "cryptography==3.3.2" \
 && pip install --no-cache-dir "impacket==0.9.22"

WORKDIR /work
CMD ["/bin/bash"]
```


