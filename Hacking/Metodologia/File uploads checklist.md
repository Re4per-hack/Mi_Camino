
- [ ]  Are filenames reflected back on the page? HTML Entity encoded? (XSS via file names)

- [ ] Does it accept .zip files? Try a [ZipSlip](https://onsecurity.io/article/file-upload-checklist/#zipslip)

- [ ] If it processes an image, check for [Image Tragick (CVE-2016-3714)](https://onsecurity.io/article/file-upload-checklist/#image-tragick-cve-2016-3714)

- [ ] Can you bypass file type restrictions by changing the content-type value?

- [ ] Can you bypass file type restrictions by [forging valid magic bytes](https://onsecurity.io/article/file-upload-checklist/#magic-byte-forgery)?

- [ ] Can you upload a file with a less-common extension (such as .phtml)?

- [ ] Try playing with the filename in the request, a potential vector for traversal or SQL injection.

- [ ] Check for the acceptance of double extensions on uploaded files.

- [ ]  Test for [null-byte injection](https://onsecurity.io/article/file-upload-checklist/#null-byte-x00-injection). (%00)

- [ ]  Is the server windows? Try adding a [trailing `.` to bypass extension blacklists](https://onsecurity.io/article/file-upload-checklist/#trailing--in-windows), this dot will be removed automatically by the OS.

- [ ] Can you upload an [SVG for XSS](https://onsecurity.io/article/file-upload-checklist/#upload-a-malicious-svg-file-for-xss)?

- [ ] If supported by the webserver, can you [upload .htaccess files](https://onsecurity.io/article/file-upload-checklist/#uploading-a-htaccess-file)?

- [ ] Does the backend process the image with the [PHP GD library](https://onsecurity.io/article/file-upload-checklist/#bypassing-the-php-gd-library)?

- [ ] Is the app vulnerable to the [infamous ffmpeg exploit](https://onsecurity.io/article/file-upload-checklist/#ffmpeg-exploit-and-explanation)?

- [ ] Can custom polyglots be developed to bypass specific filters?

- [ ] Does the app pass the file name to some sort of system function? If so, can you achieve [RCE via code injection within the file name](https://onsecurity.io/article/file-upload-checklist/#rce-via-the-file-name-parameter)?

- [ ] Does the application run the uploaded file through exiftool? If so, can you get [RCE via the djvu exploit](https://onsecurity.io/article/file-upload-checklist/#rce-via-exiftool-exploit)?

- [ ] Can you bypass extension filters by using [varied capitalization](https://onsecurity.io/article/file-upload-checklist/#bypassing-filters-by-case-sensitive-extensions)?

