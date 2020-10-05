<%-- 
    Document   : example2
    Created on : Jun 18, 2020, 10:02:53 AM
    Author     : marco
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Example 2</title>
    </head>
    <body>
        <h1>Example 2!</h1>
        <jsp:include page="menu.html" />
        <script>
            // 3 is the default value
            n = window.prompt("Give me the value for n", 3);
            for (i = 1; i < n; i++) {
                document.write(i);
                document.write("<br>");
            }
        </script>
        <p>End of the document</p>
    </body>
</html>
