# Javascript

JavaScript make the browser smart, so the name **smart browser** was invented.

## Variables

`<nothing>` are global variables
`var` are variables that can be used in all the program  
`let` are used in the scope where you declear that  
`const` variable that can never change

The variables can be:

- `undefined`
- `null`
- `boolean`
- `string`
- `symbol`
- `number`
- `object`

## Hoisting

Thanks to hoisting all the functions and variables with VAR (no global) are decleared at the top of the function they are called in, this means that in whatever point of the document I'm in, the varaible is already declared. But the value is assigned below, so in some part of the code could be undefined. Here is an example where the variable is declared, but the value has not been assigned:

![hoisting example](https://i.imgur.com/bdm27F8.png)

## Scope

Possible errors in JavaScript:

- `x is not defined` if variable is not defined
- `undefined` if variable is defined, but value is not

There are different ways to declare variables:

![https://i.imgur.com/3daAJQ6.png](https://i.imgur.com/3daAJQ6.png)

## Hoisting and Scope examples

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
    *
    * DEF 1         DEF 2         RESULT
    * ------------  ------------  ----------
    * x = 1;        x = 2;        1-1-2 (no error)
    * x = 1;        var x = 2;    1-1-2 (no error)
    * x = 1;        let x = 2;    Error: Cannot access 'x' before initialization
    * x = 1;        const x = 2;  Error: Cannot access 'x' before initialization
    *
    * var x = 1;    x = 2;        1-1-2 (no error)
    * var x = 1;    var x = 2;    1-1-2 (no error)
    * var x = 1;    let x = 2;    Error: Cannot access 'x' before initialization
    * var x = 1;    const x = 2;  Error: Cannot access 'x' before initialization
    *
    * let x = 1;    x = 2;        1-1-2 (no error)
    * let x = 1;    var x = 2;    Error: Identifier 'x' has already been declared
    * let x = 1;    let x = 2;    Error: Cannot access 'x' before initialization
    * let x = 1;    const x = 2;  Error: Cannot access 'x' before initialization
    *
    * const x = 1;  x = 2;        Error: Assignment to constant variable.
    * const x = 1;  var x = 2;    Error: Identifier 'x' has already been declared
    * const x = 1;  let x = 2;    Error: Cannot access 'x' before initialization
    * const x = 1;  const x = 2;  Error: Cannot access 'x' before initialization
    *
    * p.s. "Cannot access 'x' before initialization" and "redeclaration of let x"
    * are the same error, one in console, one in try catch output.
    */
    try {
        function f() {
            x = 1; // DEF 1
            p2(1, x);
            {
                p2(2, x);
                x = 2; // DEF 2
            }
            p2(3, x);
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

## Operators

Rules about + oprator in JavaScript:

![https://i.imgur.com/YiLj49D.png](https://i.imgur.com/YiLj49D.png)

Examples of the + operator rules:

![https://i.imgur.com/URhDQJ3.png](https://i.imgur.com/URhDQJ3.png)

![https://i.imgur.com/emqBCET.png](https://i.imgur.com/emqBCET.png)

The `+` before a string transform the string to an integer.

So it's possible to do something like `(+x) + (+y)` to transform before x and y in integers and then sum them. If strings are not transformable into numbers, the NaN is returned.

![example 3](https://i.imgur.com/h8RKhY2.png)

## Objects

In JavaScript there are objects that can contain values and methods:

![https://i.imgur.com/mZNjxtf.png](https://i.imgur.com/mZNjxtf.png)

It's possible to access a variable in one of the following ways:

![https://i.imgur.com/Mxs1ZQs.png](https://i.imgur.com/Mxs1ZQs.png)

Add and remove variables from objects:

![https://i.imgur.com/faHBKSc.png](https://i.imgur.com/faHBKSc.png)

In JavaScipt objects are not like in Java. The objects here can be changed (in Java it's not possible) and an object is not really an instance of a class, but it's rather a collection of variables.

The declaration of an object is possible in the following ways:

- `var object1 = new Object();`
- `var object1 = {};`

Or with a more elablorated way, specifying also if the object is writable (failing silently in case):

![https://i.imgur.com/tvmNUuC.png](https://i.imgur.com/tvmNUuC.png)

JavaScript function's constructors look like this:

![https://i.imgur.com/YJIqCRZ.png](https://i.imgur.com/YJIqCRZ.png)

In JavaScript if you edit an object, only that object will have that field edit:

![https://i.imgur.com/8x1qzZh.png](https://i.imgur.com/8x1qzZh.png)

Prototype functions are used in order not to be edited after the function. In objects it's possible to edit the functions inside them, with prototype it's not possible:

![https://i.imgur.com/A12BlLD.png](https://i.imgur.com/A12BlLD.png)

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

## Enheritance

In JavaScript the enheritance works like in Java.  
If `myAthlete.fullName()` is called then the first thing it does is looking inside `Athlete`, then `Person`, then `Athlete prototype`, then `Person prototype`, the `Object`, then `Object prototype`, then `null`:

![Enheritance](https://i.imgur.com/Me1L633.png)

Enheritance example:

![Enheritance example](https://i.imgur.com/1IEwdcR.png)

In this example we do not see the **Object prototypes** because there is an `enumerable: false`, so they don't apper in the loop.

## Class

Classes are just sintactic sugar, they have been added in Ecma 2015 but it was possible to make them also before that JS version. They have just the pro of extending other classes.

Classes do not have hoisting, this means that it's possible to used them only after you declare them (not like functions).

In the classes it's not possible to add variables ouside the constructor.

Classes for ES2015:

``` JS
function Classe() {}
Classe.prototype.metodo = function() {
    console.log('ciao');
};
varistanza =newClasse();
```

Classes after ES2015:

``` JS
lassClasse {
    metodo() {
        console.log('è colpa di mattia');
    }
}
let istanza =newClasse();
```

It's possible to add static methods:

![static](https://i.imgur.com/3TsPgRe.png)

It's possible to call static methods only inside the class. (?)

## Node import libraries

Here running `node file.js README.md` prints all the readme.

``` JS
// Loading the file system library
var fs = require("fs");

// File name from the common line params
var fileName = process.argv[2];

// Accessing the content of the file synchnously (blocking call)
var data = fs.readFileSync(fileName, "utf8");
console.log(data);
```

## Non-blocking calls

``` JS
// Loading the file system library
var fs = require("fs");

// File name from the common line params
var fileName = process.argv[2];

// Accessing the content of the file asynchnously (non-blocking call)
fs.readFile(fileName, "utf8", function(error, data) {
  console.log(data);
});
```

Promises are a more elegant ways to make non-blocking calls.

## Strings

Quasi tutti gli sviluppatori JavaScript utilizzano gli apici singoli anziché quelli doppi, a differenza di Java. Ciò significa che anche se entrambe queste forme sono corrette: `let a = "testo"; letb ='testo';`. Quella preferita è quasi sempre la seconda.

## Loop on items

Two ways of looping over a list:

``` JS
for(letitemofarr) {
    console.log(item);
}

OR

arr.forEach((item) => {
    console.log(item);
});
```

## Export and import functions

![https://i.imgur.com/M6cTdrd.png](https://i.imgur.com/M6cTdrd.png)
