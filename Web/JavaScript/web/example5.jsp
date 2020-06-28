<%--
    Document   : example5
    Created on : Jun 19, 2020, 10:29:11 AM
    Author     : marco
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Example 4</title>
        <script>
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

            function example6() {
                p1("<h4>Example 6</h4>");
                x = null; // DEF 1
                function f() {
                    x = "A"; // DEF 2
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
                 *     In diffent blocks does not give error
                 * x = 1;        let x = 2;    Error: Cannot access 'x' before initialization
                 *     In diffent blocks does not give error
                 * x = 1;        const x = 2;  Error: Cannot access 'x' before initialization
                 *
                 * var x = 1;    x = 2;        1-1-2 (no error)
                 * var x = 1;    var x = 2;    1-1-2 (no error)
                 * var x = 1;    let x = 2;    Error: Cannot access 'x' before initialization
                 *     In diffent blocks does not give error
                 * var x = 1;    const x = 2;  Error: Cannot access 'x' before initialization
                 *     In diffent blocks does not give error
                 *
                 * let x = 1;    x = 2;        1-1-2 (no error)
                 * let x = 1;    var x = 2;    Error: Identifier 'x' has already been declared
                 * let x = 1;    let x = 2;    Error: Cannot access 'x' before initialization
                 *     In diffent blocks does not give error
                 * let x = 1;    const x = 2;  Error: Cannot access 'x' before initialization
                 *     In diffent blocks does not give error
                 *
                 * const x = 1;  x = 2;        Error: Assignment to constant variable.
                 * const x = 1;  var x = 2;    Error: Identifier 'x' has already been declared
                 * const x = 1;  let x = 2;    Error: Cannot access 'x' before initialization
                 *     In diffent blocks does not give error
                 * const x = 1;  const x = 2;  Error: Cannot access 'x' before initialization
                 *     In diffent blocks does not give error
                 *
                 * p.s. "Cannot access 'x' before initialization" and "redeclaration of let x"
                 * are the same error, one in console, one in try catch output.
                 */
                try {
                    function f() {
                        const x = 1; // DEF 1
                        p2(1, x);
                        {
                            p2(2, x);
                            const x = 2; // DEF 2
                        }
                        p2(3, x);
                    }
                    f();
                } catch (err) {
                    p2("Error", err.message);
                }
            }
        </script>
    </head>
    <body>
        <h1>Example 4!</h1>
        <jsp:include page="menu.html" />
        <p>Here are some hoisting tests:</p>
        <button onclick="example1()">Example1</button>
        <button onclick="example2()">Example2</button>
        <button onclick="example3()">Example3</button>
        <button onclick="example4()">Example4</button>
        <button onclick="example5()">Example5</button>
        <button onclick="example6()">Example6</button>
        <button onclick="example7()">Example7</button>
    </body>
</html>
