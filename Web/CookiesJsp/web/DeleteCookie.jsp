<%--
    Document   : DeleteCookie
    Created on : Jun 26, 2020, 11:52:45 AM
    Author     : marco
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%
    Cookie cookies[] = request.getCookies();
    for (Cookie cookie : cookies) {
        cookie.setMaxAge(0);
        response.addCookie(cookie);
    }
    response.sendRedirect("Welcome.html");
%>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <h1>Hello World!</h1>
    </body>
</html>
