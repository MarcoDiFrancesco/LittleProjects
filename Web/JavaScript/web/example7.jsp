<%--
    Document   : example7
    Created on : Jun 22, 2020, 11:31:47 AM
    Author     : marco
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Example 7</title>
    </head>
    <body>
        <h1>Example 7!</h1>
        <jsp:include page="menu.html" />
        <p>Here is inheritance in JavaScript.</p>
        <script>
            function Person(first, last) {
                this.firstName = first;
                this.lastName = last;
            }
            Person.prototype.fullName = function () {
                return this.firstName + " " + this.lastName;
            };

            function Athlete(first, last, sport) {
                Person.call(this, first, last); // Instantiate the object
                this.sport = sport;
            }
            Athlete.prototype = Object.create(Person.prototype);
            Object.defineProperty(Athlete.prototype, 'constructor', {
                value: Athlete,
                enumerable: false, // Not possible to loop with for
                writable: true // It can be changed
            });
            let athlete1 = new Athlete('Mario', 'Rossi', 'Football');
            // fistName and lastName are enherited without needing to specify it
            console.log(athlete1.firstName + " " + athlete1.lastName);
            console.log(athlete1.fullName() + " " + athlete1.sport);
        </script>
    </body>
</html>
