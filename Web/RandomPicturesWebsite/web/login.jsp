<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Login Page</title>
    </head>
    <body>
        <h1>Login page</h1>
        <form action="Login" method="GET">
            <label for="email">email</label>
            <input type="text" name="email" pattern="[a-z0-9._%+-]+@[a-z0-9.-]+\.[a-z]{2,4}$" required />
            <br />
            <br />
            <label for="password">password</label>
            <input type="password" name="password" pattern="^.{4,8}$" required />
            <input type="submit" value="Submit">
        </form>
        <%
            if (request.getAttribute("valid") == "false"){
        %>
        <p>The password is incorrect, type again the password</p>
        <%
            } else {
                response.sendRedirect("GetPicture.jsp");
            }
        %>
        <p>If you don't have an account <a href="subscribe.jsp">subscribe</a>!</p>
    </body>
</html>