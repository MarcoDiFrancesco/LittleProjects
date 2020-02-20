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
