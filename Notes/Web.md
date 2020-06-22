# Web

Web architectures notes.

## Web architecture protocols

A protocol is a set of rules and regulations that determine how data is transmitted.  
The protocol contains: format, order and action.

URI, URL and URN:

- URI (Uniform Resource Identifier) identifies an abstract or physical location
- URL (Uniform Resource Location) is a subset of URI and referes to the rappresentation of their primary access mechanism, e.g. their location
- URN (Uniform Resource Name) is a subset of URI and referes to the rappresentation od a globally unique and persistent location, even when the resource does not exist anymore, e.g. the ISBN of a book

### URI vs URL vs URN

![URI vs URL vs URN](https://i.imgur.com/MGHNIxc.png)

From [stack overflow](https://stackoverflow.com/a/4913371/7924557):

```HTML
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

### Mime type

![MIME type](https://i.imgur.com/BXg5hOh.png)

## HTML

HTML does not have personalized tags, the language that support them is XML.

An imporant property of HTML is **graceful degradation of presentation**, if there is some mistakes inside the code, the page needs to be shown anyway

HTML is not case sensitive: someting like:

```HTML
<h1>Title<H1>
```

is correctly parsed.

An example is:

```HTML
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

```HTML
<i><b>This is bold</b> and this is italic</i>
```

This is legal in HTML, but not XHTML

```HTML
<i>This is italic, <b>this is bold and italic</i> this is only bold</b>
```

In HTML5 we have not only the `<image>` tag, but also `<figure>`, containing the tag `<figcaption>`

```HTML
<figure>
  <img src="link" alt="description"/>
  <figcaption>This is read by search engines and blind people</figcaption>
</figure>
```

The links in html can be with href and name:

```HTML
<a href="/something">
```

goes to root to `something`.

```HTML
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

```HTML
<meta charset="UTF-8">
<meta name="description" content="Free tutorial">
<meta http-quiv="refresh" content="30"> <!-- Refresh every 30 secs -->
<meta name="viewport" content="">
```

The viewport makes the browser work in different ways canging the ratio of the screen.

![Viewport](https://i.imgur.com/8IP1Q9r.png)

### HTTP request

HTTP request are written in ASCII.  
HTTP can specify gzip or deflate compression so the server can respond with compressed information.  
URL max size is 2048 characters.  
[CRLF] stands for Carriage Return (ASCII 13, \r) Line Feed (ASCII 10, \n).

### Safe vs idempotent

**Safe** does not alter the state of the server.  
**Idempotent** if an identical request can be made once or several times in a row with the same effect while leaving the server in the same state.

![Safe vs idempotent](https://i.imgur.com/3DS4JQ4.png)
A save method in HTTP is a method that does not change the state of the server (read only).

GET vs PUT.

## CSS

The lenght of the style can be specified as:

- cm, mm
- in (inch), pt (point), pc (pica)
- em (height of element font) that goes from the bottom of the letter o in font to the top
- ex (extended height of element font) that goes from the bottom of the letter f to the top

![font mesures](https://i.imgur.com/gacu04q.png)

Formatting elements:

![Formatting elements](https://i.imgur.com/NHIf16q.png)

There are colors, given in rgb.  
There are gradients.

Box elements:

![box elements](https://i.imgur.com/bN1lLh3.png)

If I want to specify bottom in border will be `border-bottom-width:`, if not `border-width`.

### Selector

There are different types of selectors:

![css selectors 1](https://i.imgur.com/AflQQCs.png)

![css secectors 2](https://i.imgur.com/oBuxFq3.png)

![css selectors 3](https://i.imgur.com/xEWJdDQ.png)

Select by attribute:

![select by attribute](https://i.imgur.com/sPrr34O.png)

### Cascading and positioning

The sylesheets are cascading because they enherit the parent's style. So if there is a redefinition of a style, it will win over the old definition.

For example:

![cascading example](https://i.imgur.com/bQUnLVU.png)

There is an exception if there is `!important`, because it wins over the redefinitions.

### Positioning

There is the possibility to choose the position of an element in the following ways:

![positioning](https://i.imgur.com/LCyZszM.png)

If two emements overlap, then you can choose which one goes over the other with a **z-index**:

![z-index](https://i.imgur.com/29pAKD5.png)

Or just clipping it, cutting a piece of one element:

![clip](https://i.imgur.com/uGcGB2V.png)

Positioning example:

![positioning example](https://i.imgur.com/AmQekan.png)

In this example the relative positioning (in apotion) is used to say: stay 30px more left than you were supposed to do.

### Fonts

You can specify more than one font:

![more than one font](https://i.imgur.com/h8x2d78.png)

So if verdana is not available, use helvetica.

Browsers have some default fonts, but it's possible to specify external ones.

## Bootstrap

Bootstap is a framework used to write interfaceces in a easier way.

Bootstrap example in exercises.

![Carousel example](https://i.imgur.com/J6Ri3vW.png)

## JavaScript

JavaScript make the browser smart, so the name **smart browser** was invented.

![JavaScript example](https://i.imgur.com/iOg6M32.png)

With JavaScript we can specify to print in different ways:

![JavaScript text](https://i.imgur.com/QjO3Lk0.png)

Operators:

![JavaScript operators](https://i.imgur.com/vJIScgf.png)

In JavaScript if 2 strings are compared: `a < b` then it's considered the alpabetic order.

Rules about + in JavaScript:

![+ opeator in JavaScript](https://i.imgur.com/YiLj49D.png)

Examples:

![example 1](https://i.imgur.com/URhDQJ3.png)

![example 2](https://i.imgur.com/emqBCET.png)

The `+` before a string transform the string to an integer.

So it's possible to do something like `(+x) + (+y)` to transform before x and y in integers and then sum them. If strings are not transformable into numbers, the NaN is returned.

![example 3](https://i.imgur.com/h8RKhY2.png)

How does the + oprator works:

![+ operator](https://i.imgur.com/e7JlaFT.png)

### Function

Calling the function in the wrong way JavaScript:

![call function](https://i.imgur.com/bO2RIoC.png)

Recursive function:

![function](https://i.imgur.com/niu7g3X.png)

### Hoisting

Thanks to hoisting all the functions and variables with VAR (no global) are decleared before everything, this means that in whatever point of the document I'm in, the varaible is already declared, by if a value is assigned below, it won't contain any value. Here is an example where the variable is declared, but the value has not been assigned:

![hoisting example](https://i.imgur.com/bdm27F8.png)

Mapping and filtering in an array is possible using `.map` and `.filter` passing a function.

![mapping and filtering](https://i.imgur.com/yRVnTe6.png)

### JavaScript Scope

Possible errors in JavaScript:

- `x is not defined` if variable is not defined
- `undefined` if variable is defined, but value is not

There are different ways to declare variables:

![variables](https://i.imgur.com/3daAJQ6.png)

Example:

![example 1](https://i.imgur.com/HdzTgq1.png)

In `t0` it's possible to see that hoisting is working:

![example 2](https://i.imgur.com/3nDYnab.png)

Example:

![example 3](https://i.imgur.com/CkGvHcN.png)

Variable redefinition:

![example](https://i.imgur.com/IhQkNxK.png)

### Scope and hoisting examples

Some examples of scope:

```JavaScript
p1 = (n) => document.write("<p>" + n + "</p>");
p2 = (n, s) => document.write("<p>" + n + ": " + s + "</p>");

function example1() {
    p1("<h4>Example 1</h4>");
    try {
        function f() {
            var carName = "Volvo";
            p1(carName);
        }
        f();
        p1(carName); // carName is not defined
    } catch (err) {
        p2("Error", err.message);
    }
}

function example2() {
    p1("<h4>Example 2</h4>");
    try {
        function f() {
            a = 20;
            var b = 100;
        }
        f();
        p1(a);
        p1(b); // b is not defined
    } catch (err) {
        p2("Error", err.message);
    }
}

function example3() {
    p1("<h4>Example 3</h4>");
    try {
        function f() {
            p1(a); // a is not defined
            a = 20;
        }
        f();
    } catch (err) {
        p2("Error", err.message);
    }
}

function example4() {
    p1("<h4>Example 4</h4>");
    try {
        function f() {
            p1(b);
            a = 20;
            var b = 100; // undefined
        }
        f();
    } catch (err) {
        p2("Error", err.message);
    }
}

function example5() {
    p1("<h4>Example 5</h4>");
    try {
        p1(b); // b is not defined
        function f() {
            a = 20;
            var b = 100;
        }
        f();
    } catch (err) {
        p2("Error", err.message);
    }
}

// Example 6 is below

function example7() {
    p1("<h4>Example 7</h4>");
    /*
     * With let and const it's not possible to redeclare a value.
     * The errors are the same also when going in other blocks like in this example.
     * Some example are:
     * x = 1; x = 1;       // No error
     * x = 1; var x = 1;   // No error
     * x = 1; let x = 1;   // Error: can't access lexical declaration `x' before initialization
     * x = 1; const x = 1; // Error: can't access lexical declaration `x' before initialization
     *
     * let x = 1; x = 1;       // No error
     * let x = 1; var x = 1;   // Error: redeclaration of let x
     * let x = 1; let x = 1;   // Error: redeclaration of let x
     * let x = 1; const x = 1; // Error: redeclaration of let x
     *
     * const x = 1; x = 1;       // Error: invalid assignment to const `x'
     * const x = 1; var x = 1;   // Error: redeclaration of let x
     * const x = 1; let x = 1;   // Error: redeclaration of let x
     * const x = 1; const x = 1; // Error: redeclaration of let x
     */
    try {

        function f() {
            x = 1;
            p2(1, x); // 1: A
            {
                p2(2, x); // 2: A
                let x = 1; // Error: can't access lexical declaration `x' before initialization
            }
            p2(3, x); // 3: A
        }
        f();
    } catch (err) {
        p2("Error", err.message);
    }
}

function example8() {
    try {
        function f() {
            const x = 1;
            p2(1, x); // 1: A
            {
                p2(2, x); // 2: A
                x = 1;
            }
            p2(3, x); // 3: A
        }
        f();
    } catch (err) {
        p2("Error", err.message);
    }
}
```

In example 6 there are different possibilities for each combination:

```JavaScript
function example6() {
    p1("<h4>Example 6</h4>");
    x = null; // DEF 1
    function f() {
        var x = "A"; // DEF 2
        p2(2, x);
        {
            x = 1; // DEF 3
            p2(3, x);
        }
        p2(4, x);
    }
    p2(1, x);
    f();
    p2(5, x);
}
```

![example 6 solutions](https://i.imgur.com/NVoCqFK.png)

### Objects

In JavaScript there are objects that can contain values and methods:

![JavaScirpt objects examples](https://i.imgur.com/mZNjxtf.png)

It's possible to access a variable in one of the following ways:

![accessing objects](https://i.imgur.com/Mxs1ZQs.png)

Add and remove variables from objects:

![add and remove variables](https://i.imgur.com/faHBKSc.png)

In JavaScipt objects are not like in Java. The objects here can be changed (in Java it's not possible) and an object is not really an instance of a class, but it's rather a collection of variables.

The declaration of an object is possible in the following ways:

- `var object1 = new Object();`
- `var object1 = {};`

Or with a more elablorated way, specifying also if the object is writable (failing silently in case):

![object declaration](https://i.imgur.com/tvmNUuC.png)

JavaScript function's constructors look like this:

![constructors](https://i.imgur.com/YJIqCRZ.png)

In JavaScript if you edit an object, only that object will have that field edit:

![objects edit](https://i.imgur.com/8x1qzZh.png)

Prototype functions are used in order not to be edited after the function. In objects it's possible to edit the functions inside them, with prototype it's not possible:

![prototypes](https://i.imgur.com/A12BlLD.png)

So something like this:

```JavaScript
function Person(first, last) {
    this.name = {
        'first': first,
        'last': last
    };
    this.fullname = () => this.name.first + " " + this.name.last;
}
```

becomes:

```JavaScript
function Person(first, last) {
    this.firstName = first;
    this.lastName = last;
}
Person.prototype.fullname = function () { // It's not possible to use arrow functions
    return this.firstName + " " + this.lastName;
}
```

### Enheritance

In JavaScript the enheritance works like in Java.  
If `myAthlete.fullName()` is called then the first thing it does is looking inside `Athlete`, then `Person`, then `Athlete prototype`, then `Person prototype`, the `Object`, then `Object prototype`, then `null`:

![Enheritance](https://i.imgur.com/Me1L633.png)

Enheritance example:

![Enheritance example](https://i.imgur.com/1IEwdcR.png)

In this example we do not see the **Object prototypes** because there is an `enumerable: false`, so they don't apper in the loop.

### Class

Classes are just sintactic sugar, they have been added in Ecma 2015 but it was possible to make them also before that JS version.

Classes do not have hoisting, this means that it's possible to used them only after you declare them (not like functions).

In the classes it's not possible to add variables ouside the constructor:

![variables outside the constructor](https://i.imgur.com/A9vQdMY.png)

It's possible to add static methods:

![static](https://i.imgur.com/3TsPgRe.png)

It's possible to call static methods only inside the class. (?)

### Array

In JavaScript it's possible to add whatever type you want inside the array.

Example:

![array example](https://i.imgur.com/3TsPgRe.png)

## jQuery

jQuery is a library written in JavaScript used to simplify the JavaScript code.

jQuery sytax:

![jQuery example](https://i.imgur.com/gibPdvN.png)

jQuery makes the life way easier when using ajax, it adds get and post method to send data, and load method to load data inside a selector:

![ajax in jQuery](https://i.imgur.com/gf74ZUo.png)

## PHP

PHP **is not** case sensitive for functions, but **it is** case sensitive for variables.

PHP can parse string to int:

![String to int](https://i.imgur.com/tlpX4nJ.png)

if you don't want this behaveviour you need to specify it:

![Strict type example](https://i.imgur.com/D1gr9Fp.png)

and this gives error.

### Operators

![Operators](https://i.imgur.com/YbOj2Sq.png)

![Identical](https://i.imgur.com/6Yl9BXA.png)

### Spaceship

Not so important for the course.

![Spaceship](https://i.imgur.com/kfHEotU.png)

### Vardump

`var_dump` prints the variables type and the value.

![var_dump example](https://i.imgur.com/N9vSv8b.png)

### PHP Scope

![Local vs global scope](https://i.imgur.com/IP9mFrE.png)

### Array

![Index and associative array](https://i.imgur.com/as83YHj.png)

![Array operators](https://i.imgur.com/r6d3LVH.png)

### Super global variables

![Super global variables](https://i.imgur.com/MEvtQmB.png)

## Web architecture

![Dynamic pages](https://i.imgur.com/s2iLr1O.png)

### Cgi-bin and PHP

When the **cgi-bin** pages are requested, they are created dynamically, the server creates a process in mulitasking, so it can handle more than one process at a time:

![Cgi-bin request](https://i.imgur.com/6mL2Jn8.png)

Same thing with PHP pages:

![Php request](https://i.imgur.com/b5gs88t.png)

### Java servlet container

Apache **Tomcat** is a **Java servlet container** and it runs on a **Java Virtual Machine**.

Using a **Java servlet container** the server uses instad multi threading, that is way lighter than multi tasking, because it does not start every time a new process.

![Java servlet container request](https://i.imgur.com/MJAZccQ.png)

Java servlet context is a serie of Java servlet containers:

![java servlet context](https://i.imgur.com/jDDzOhN.png)

## MV\*

MV stands for Model View, and there are diffent types of Model View models. Some of them are:

- Model View Controller (MVC)
- Model View Presenter (MVP)
- Model View View Model (MVVP)

### Model View Controller

Model View Controller (MVC) makes the model connecting on the view.

![MVC](https://i.imgur.com/9QObvdn.png)

![MVP](https://i.imgur.com/Q39WuHP.png)

![MVVM](https://i.imgur.com/EJFpyp7.png)

## Servlet

### Servlet lifecycle

![Servlet lifecycle](https://i.imgur.com/q0805UZ.png)

In the **servlet lifecycle** the connection are set the fist time with the method `init()` (watch A), then it's called only the method `service()`. If there isn't enough memory the method destroy() is called and this one delete the content in the older one, so there is space for the new one (Servlet 4 replaces Servlet 1).

The method `service()` understand if request is Get, Post, Head etc. and call the right method.

![service method](https://i.imgur.com/qvs8qF1.png)

## Session

Sessions solve the problem of cookies. Because we don't have a state of the application we need to save all data inside cookies, and because we could have a lot of data to store, we would need a lot of cookeis. Sessions solve this problem, we store just one cookies as identification, while saving all data server-side.

In java this is done using hashtables. With api we can use HttpSessions.

The sessions in java offer also an approch in case the cookies are not enbled in the browser, it will use **URL rewriting**, like in this example:

![esse3 example](https://i.imgur.com/gWNxqxJ.png)

The file `web.xml` contains what's the timeout of a session. It also contains the links of the servlet to the web pages, from Java 5 these are contained in the annotation of the servlet, so it's useless to use web.xml for these.

## Java server pages

JSP-CustomTags allow things like `<reverse>this</reverse>`. Now not used anymore.  
JSP compared to servlets, are useful because they allow to use directly the HTML template, instead of using `out.ptintln("<html>")`.

JSP example:

![JSP](https://i.imgur.com/Ns2p2or.png)

The main difference with PHP is that JSP behind all of this, manages sessions, memory etc. , things that PHP doesn't do by itself.

JSP syntactic elements:

![jsp things](https://i.imgur.com/u2kvMk6.png)

Inside JSP it's possible to use:

- `<%!@ import ... %>` at the beginning of the file
- `<% ... %>` for things inside the DoGet()
- `<%! ... %>` for declarations outside of the DoGet()

Directives:

![JSP directives](https://i.imgur.com/yChtzSC.png)

Functions inside jsp:

![functions](https://i.imgur.com/RO4f1mR.png)

Redirect to another page:

![redirect](https://i.imgur.com/BfSmzyv.png)

## Reactive Web Disign

**Reactive Web Deisign** is a set of techniques that are used to build sites that fells responsive. Reactive programming uses **asynchronous data stream**.

One framework used today is **React**.

**Responsive design** is used to make pages that fit all types of screens, also vertial and horizontal. This is done using CSS.

XMLHttpRequest properities:

![XMLHttpRequest properities](https://i.imgur.com/vHJK6FC.png)

Example:

here the variable `this` equals the obect of the function, in this case it is `xhttp`.

![example](https://i.imgur.com/OPWkZZ7.png)

### Cross-Origin Resource Sharing

Ajax can also request resources from outside the server with Cross-Origin Resource Sharing using XMLHttpRequest:

![Example](https://i.imgur.com/XhJCxaB.png)

The apache server needs to be configured such as it can accept connections from outside:

![Example](https://i.imgur.com/9Je0UxQ.png)

Ajax can use either JSON or XML to tranfer data. In both cases, in the clint sides there needs to be an XML parser or JSON parser.

![xml vs json](https://i.imgur.com/q3of6JY.png)

## JSON

![JSON example](https://i.imgur.com/1WVMli4.png)

### AJAJ

AJAJ is the AJAX version based on JSON.

AJAJ example:

![AJAJ example](https://i.imgur.com/lq1RXek.png)

If we put responseType = "json" we don't need to parse the element from plaintext to json object, so we can do directly something like `hello = my_JSON_object.squadName;` without parsing. If we don't use that line we need to make `JSON.parse(text)` or JSON to string is `JSON.stringify`.

JSON parse example:

![JSON parse example](https://i.imgur.com/ojoOggS.png)

There is also a `reviver` option, that taken a JSON object it decides to parse if as a string or something else. In this example it checks if the key is birthDate, if so it parse that to a date object insted of a string.

![JSON parse with reviver example](https://i.imgur.com/88HzJv5.png)

JSON stringify example:

![JSON stringify example](https://i.imgur.com/LRtpt2Z.png)

## AOP

Aspect-oriented programming (AOP) is a conceptual way of writing code. In AOP we modularize the code like so that we solve problems, more or less like what we do normally in function, calling one function in different part of the program.

AOP are specialized in logging and authorization.

### Filter

Filters are classes that works on AOP. All servlet containers use one filter that is in common and can control:

![filters](https://i.imgur.com/1RXdzWI.png)

The main use of filter is done for authentication, for example for a bunch of servlet that need the user login to acess, a filter is added to check if the user is logged, if not it's redirected to the filter.

The filters are added in the `map.xml`, the first that comes in the mapping is the first that is executed, so in this example Uncompressed is executed before authenticate.

![filters mapping](https://i.imgur.com/aVJxf6D.png)

Parameters in filter can be specified in `map.xml`:

![map](https://i.imgur.com/3kRjekQ.png)

## Database in Java

The JDBC is the driver that connect with the database using it's API.

## Typescript

Typescript is a language that makes JavaScript closer to Java.

JavaScript has the problem that if the version of JavaScript I'm using is not supported by my browser, I won't be able to run it.

There are 2 possible solutions to this: polyfiling and tanspiling. The **polyfiller** understand if the intrpreter is not able to run newer version of the language, and in that case, it sends libraries to the interpreter to understand the newer code. The **transpiler** changes the code syntax, to be accepted by the older version of the language.

Typescript needs to be compiled in JavaScript code before running into a browser. Typescript it's possible to tranpile code in older versions of JavaScript, for example it's possible to compile into ES3 so it's userstood by interet explorer.

One feature of Typescript is the variable definition:

![variable definition](https://i.imgur.com/fvgDhz8.png)

This is really useful when compiling code, because it tells you if you made any mistake (about variables) when compiling the code.

Another example where typescript can help is arguments in functions:

![arguments in function errors](https://i.imgur.com/4WtYhh8.png)

This can be fixed with an optional argument:

![arguments in function fix](https://i.imgur.com/L3Akzaw.png)

Or with a default value:

![arguments in function with default value](https://i.imgur.com/zKEqpMm.png)

Dynamic typing is considered as an error, also if in JavaScript is possible:

![arguments in function with default value](https://i.imgur.com/xbmV9Tf.png)

and this can be fixed with the type: `any`

![any type](https://i.imgur.com/Uv8TZSv.png)

In typescript it's possible to write cast like in Java. This is only considered by TypeScript because in JavaSctipt the cast declaration is not needed:

![cast declaration](https://i.imgur.com/YO0YH9k.png)

In typescript it's possible to have multiple inheritance:

![multiple inheritance](https://i.imgur.com/MEaSb8z.png)

It's possible also to have duck inheritance, that is: if a class has ALL the methods required by the function (in this case the method `run()` is in both classes) and ALL the variables, then it's possible also to call runTask with Vehicle:

![duck inheritance](https://i.imgur.com/y491hDU.png)

And the following will give an error, because x is not declared:

![not respecing duck inheritance](https://i.imgur.com/q69FoLv.png)

Also if `x`and `s` are different, then it's error:

![not respecing duck inheritance 2](https://i.imgur.com/rqbx5uB.png)
