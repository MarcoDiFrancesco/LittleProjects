<%-- 
    Document   : example4
    Created on : Jun 18, 2020, 10:02:53 AM
    Author     : marco
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Example 4</title>
        <script>
            function fact(n) {
                if (n === 1)
                    return n;
                return n * fact(n - 1);
            }
        </script>
    </head>
    <body>
        <h1>Example 4!</h1>
        <jsp:include page="menu.html" />
        <p>Here is a recursive function.</p>
        <script>
            for (i = 1; i < 10; i++) {
                document.write(i + " -> " + fact(i));
                document.write("<br>");
            }
        </script>
    </body>
</html>
