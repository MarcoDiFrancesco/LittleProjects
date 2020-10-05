<%--
    Document   : example6
    Created on : Jun 22, 2020, 10:28:54 AM
    Author     : marco
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Example 6</title>
    </head>
    <body>
        <h1>Example 4!</h1>
        <jsp:include page="menu.html" />
        <p>Here is an object in JavaScript with prototype.</p>
        <script>
            function Person(first, last) {
                this.firstName = first;
                this.lastName = last;
            }
            Person.prototype.fullName = function () {
                return this.firstName + " " + this.lastName;
            };
            let myPerson = new Person('Mario', 'Rossi');
            console.log(myPerson.fullName());
        </script>
    </body>
</html>
