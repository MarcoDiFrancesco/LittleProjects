<%--
    Document   : deleteSession
    Created on : Jun 23, 2020, 6:54:01 PM
    Author     : marco
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%
    session.invalidate();
%>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <h1>Delete session page</h1>
        <p>You deleted your session!</p>
        <p>Go back to <a href="session.jsp">sessions</a> to create one.</p>
    </body>
</html>
