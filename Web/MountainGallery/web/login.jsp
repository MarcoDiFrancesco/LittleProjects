<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%
    // Get messages from session and write them inside the paragraph
    String LoginMessage = (String) session.getAttribute("LoginMessage");
    String RegisterMessage = (String) session.getAttribute("RegisterMessage");
    // If messages are null make them empty strings
    if (LoginMessage == null) {
        LoginMessage = "";
    }
    if (RegisterMessage == null) {
        RegisterMessage = "";
    }
    // Remove them from the session
    session.removeAttribute("LoginMessage");
    session.removeAttribute("RegisterMessage");
%>
<html>
    <head>
        <title>Login</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css">
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.16.0/umd/popper.min.js"></script>
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/js/bootstrap.min.js"></script>
    </head>
    <body>
        <%@include file="navbar.html"%>
        <div class="container m-3">
            <h2>Login</h2>
            <p style="color: red;"><%= LoginMessage%></p>
            <p style="color: green;"><%= RegisterMessage%></p>
            <form action="LoginCheck" method="POST">
                <div class="form-group">
                    <label for="email">Email:</label>
                    <input type="email" class="form-control" id="email" placeholder="Enter email" name="email">
                </div>
                <div class="form-group">
                    <label for="password">Password:</label>
                    <input type="password" class="form-control" id="password" placeholder="Enter password" name="password">
                </div>
                <button type="submit" class="btn btn-primary">Submit</button>
            </form>
            <h2>Aren't you restered? Resiter <a href="register.jsp">here</a></h2>
        </div>
    </body>
</html>
