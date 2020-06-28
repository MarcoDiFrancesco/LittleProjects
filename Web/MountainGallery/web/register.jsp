<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <title>Register</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css">
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.16.0/umd/popper.min.js"></script>
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/js/bootstrap.min.js"></script>
    </head>
    <body>
        <%@include file="navbar.html" %>
        <div class="container m-3">
            <h2>Register</h2>
            <form action="RegisterCheck" method="POST" oninput='password2.setCustomValidity(password2.value != password1.value ? "Passwords do not match." : "")'>
                <div class="form-group">
                    <label for="email">Email:</label>
                    <input type="email" class="form-control" id="email" placeholder="Enter email" name="email">
                </div>
                <div class="form-group">
                    <label for="password1">Password:</label>
                    <input type="password" class="form-control" id="password1" placeholder="Enter password" name="password1">
                </div>
                <div class="form-group">
                    <label for="password2">Confirm password:</label>
                    <input type="password" class="form-control" id="password2" placeholder="Enter password" name="password2">
                </div>
                <button type="submit" class="btn btn-primary">Submit</button>
            </form>
            <h2>Are you already restered? Login <a href="login.jsp">here</a></h2>
        </div>
    </body>
</html>
