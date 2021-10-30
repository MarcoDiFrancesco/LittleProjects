//TO DO

<%-- 
    Document   : example8
    Created on : Oct 30, 2021, 16:22:53 AM
    Author     : me
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Example 8</title>
    </head>
    <body>
        <h1>Example 1!</h1>
        <jsp:include page="menu.html" />
        <div onmouseover="
                this.innerText = 'My text can change';
                this.style.color = 'green';"
             onmouseout="
                 this.innerText = 'Hover over me to change color';
                 this.style.color = 'red'"
             >Hover over me to change color</div>
    </body>
</html>
