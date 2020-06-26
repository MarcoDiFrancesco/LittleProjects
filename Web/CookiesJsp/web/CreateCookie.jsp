<%--
    Document   : CreateCookie
    Created on : Jun 25, 2020, 12:43:48 PM
    Author     : marco
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%
    Cookie cookies[] = request.getCookies();
    String counter = "";
    int counter_int = 0;
    String fname = "";
    for (Cookie cookie : cookies) {
        String cookieLeft = cookie.getName(); // Left value
        String cookieRight = cookie.getValue(); // Right value
        if (cookieLeft.equals("counter")) {
            counter = cookieRight;
        }
        if (cookieLeft.equals("fname")) {
            fname = cookieRight;
        }
    }

    // If there is no name set in the cookie try to get it from the parameters
    if (fname.isEmpty()) {
        fname = request.getParameter("fname");
        if (fname == null) {
            response.sendRedirect("Welcome.html"); // No cookie nor param set
        } else {
            Cookie fname_cookie = new Cookie("fname", fname);
            response.addCookie(fname_cookie);
        }
    }

    // In case there is a value in the cookie
    if (!counter.isEmpty()) {
        counter_int = Integer.parseInt(counter);
    }
    counter_int++;
    Cookie counter_cookie = new Cookie("counter", Integer.toString(counter_int));
    response.addCookie(counter_cookie);
%>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Create cookie</title>
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css">
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.16.0/umd/popper.min.js"></script>
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/js/bootstrap.min.js"></script>
    </head>
    <body>
        <div class="container m-3">
            <h1>Create a cookie</h1>
            <p>Hello <%= fname%></p>
            <p>Your access count is <%= counter_int%>.</p>
            <a href="DeleteCookie.jsp" class="btn btn-info" role="button">Delete my cookie</a>
        </div>
    </body>
</html>
