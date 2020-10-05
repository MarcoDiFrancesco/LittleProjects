<%-- 
    Document   : index
    Created on : Jun 18, 2020, 10:04:47 AM
    Author     : marco
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Example 1</title>
    </head>
    <body>
        <h1>Example 1!</h1>
        <jsp:include page="menu.html" />
        <div onmouseover="
                this.innerText = 'My text can change';
                this.style.color = 'red';"
             onmouseout="
                 this.innerText = 'Hover over me to change color';
                 this.style.color = 'green'"
             >Hover over me to change color</div>
    </body>
</html>
