
Error: \[\-\] Got error while trying to request TGT: Kerberos SessionError: KRB_AP_ERR_SKEW(Clock skew too gre

```shell
timedatectl set-ntp off  
rdate -n <IP_DC>
```