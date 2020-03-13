# Web

Web architectures notes.

## HTML

HTML does not have personalized tags, the language that support them is XML.

An imporant property of HTML is **graceful degradation of presentation**, if there is some mistakes inside the code, the page needs to be shown anyway

An example is:

``` HTML
<audio src="something">
  <a src="something">Download</a>
</audio>
```

it makes so if a browser does not unsertand audio tag, ignore it and show download tag.

In the old version of HTML (behind 4.01) the code and the aspect of the contents where togeder, in the new versions the CSS is separated. CSS describes how a page needs to be presented.

The HTML page is devided in HEAD and BODY:

- **Head** contatins:
  - Title
  - Metadata
- **Body** contains:
  - Things

HTML is not case sensitive. It also does not count tabs and multiple spaces. You can make the browser indent as it is written with the tag `<pre>`.

It's legal in HTML and XHTML to make:

``` HTML
<i><b>This is bold</b> and this is italic</i>
```

This is legal in HTML, but not XHTML

``` HTML
<i>This is italic, <b>this is bold and italic</i> this is only bold</b>
```

In HTML5 we have not only the `<image>` tag, but also `<figure>`, containing the tag `<figcaption>`

``` HTML
<figure>
  <img src="link" alt="description"/>
  <figcaption>This is read by search engines and blind people</figcaption>
</figure>
```

The links in html can be with href and name:

``` HTML
<a href="/something">
```

goes to root to `something`.

``` HTML
<a href="page#something">
```

goes to `page#something`.

### IFrame

With `iframe` we can create a page with inside another page.  

In links we can put target containing `_blank` in case we want to open it in onther page or `iframe_a` in case we want to open it in a specific iframe.

### Encoding

**ASCII** (pronounced ASKI): 128 characters  
**ISO-8859-1**: 256 characters  
**Ansi**: ISO-8859-1 + 32 characters  
**UTF-8** (Unicode): default in HTML5  

If you want to write in a pagagrapg something like `this is the tag bold <bold>` you need to write the entity name: `this is the tag bold &ltbold&gt`.

Inside head there is the meta data in the `<meta>` tags. These tags can contain charset, descriptions, css and js files, refresh rate, and viewport.  

``` HTML
<meta charset="UTF-8">
<meta name="description" content="Free tutorial">
<meta http-quiv="refresh" content="30"> <!-- Rfresh every 30 secs -->
<meta name="viewport" content="">
```

The viewport makes the browser work in different ways canging the ratio of the screen.

![Viewport](https://i.imgur.com/8IP1Q9r.png)

## Protocol

A protocol is a set of rules and regulations that determine how data is transmitted.  
The protocol contains: format, order and action.

URI, URL and URN:

- URI (Uniform Resource Identifier) identifies an abstract or physical location
- URL (Uniform Resource Location) is a subset of URI and referes to the rappresentation of their primary access mechanism, e.g. their location
- URN (Uniform Resource Name) is a subset of URI and referes to the rappresentation od a globally unique and persistent location, even when the resource does not exist anymore, e.g. the ISBN of a book

## URI vs URL vs URN

![URI vs URL vs URN](https://i.imgur.com/MGHNIxc.png)

From [stack overflow](https://stackoverflow.com/a/4913371/7924557):

``` HTML
Uniform Resource Identifier (URI) is a string of characters used to identify a name or a resource on the Internet

A URI identifies a resource either by location, or a name, or both. A URI has two specializations known as URL and URN.

A Uniform Resource Locator (URL) is a subset of the Uniform Resource Identifier (URI) that specifies where an identified resource is available and the mechanism for retrieving it. A URL defines how the resource can be obtained. It does not have to be HTTP URL (http://), a URL can also be (ftp://) or (smb://).

A Uniform Resource Name (URN) is a Uniform Resource Identifier (URI) that uses the URN scheme, and does not imply availability of the identified resource. Both URNs (names) and URLs (locators) are URIs, and a particular URI may be both a name and a locator at the same time.

The URNs are part of a larger Internet information architecture which is composed of URNs, URCs and URLs.

bar.html is not a URN. A URN is similar to a person's name, while a URL is like a street address. The URN defines something's identity, while the URL provides a location. Essentially, "what" vs. "where". A URN has to be of this form <URN> ::= "urn:" <NID> ":" <NSS> where <NID> is the Namespace Identifier, and <NSS> is the Namespace Specific String.

To put it differently:

A URL is a URI that identifies a resource and also provides the means of locating the resource by describing the way to access it
A URL is a URI
A URI is not necessarily a URL
I'd say the only thing left to make it 100% clear would be to have an example of an URI that is not an URL. We can use the examples in the RFC3986:

URL: ftp://ftp.is.co.za/rfc/rfc1808.txt
URL: http://www.ietf.org/rfc/rfc2396.txt
URL: ldap://[2001:db8::7]/c=GB?objectClass?one
URL: mailto:John.Doe@example.com
URL: news:comp.infosystems.www.servers.unix
URL: telnet://192.0.2.16:80/
URN (not URL): urn:oasis:names:specification:docbook:dtd:xml:4.1.2
URN (not URL): tel:+1-816-555-1212 (?)
```

![URI examples](https://i.imgur.com/DsXi13H.png)

![URI structure](https://i.imgur.com/wOu2lKI.png)

![Phishing](https://i.imgur.com/rMGViHr.png)

## Mime type

![MIME type](https://i.imgur.com/BXg5hOh.png)

## HTTP request

HTTP request are written in ASCII.  
HTTP can specify gzip or deflate compression so the server can respond with compressed information.  
URL max size is 2048 characters.  
[CRLF] stands for Carriage Return (ASCII 13, \r) Line Feed (ASCII 10, \n).  

## Safe vs idempotent

**Safe** does not alter the state of the server.  
**Idempotent** if an identical request can be made once or several times in a row with the same effect while leaving the server in the same state.

![Safe vs idempotent](https://i.imgur.com/3DS4JQ4.png)
A save method in HTTP is a method that does not change the state of the server (read only).  

GET vs PUT.
