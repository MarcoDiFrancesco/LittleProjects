<%@page import="java.util.logging.Logger"%>
<%@page import="java.sql.DriverManager"%>
<%@page import="java.sql.SQLException"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Statement"%>
<%@page import="java.sql.Connection"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page language="java" session="true"%>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link rel="stylesheet" type="text/css" href="sidebar.css">
        <title>Get pictures</title>
        <script src="http://code.jquery.com/jquery-latest.min.js"></script>
        <script>
            $(document).on("click", "#link", function () {
                var servletLink = "GetPicture?q=" + $(this).text();
                $.get(servletLink, function (responseJson) {
                    $("#pic").attr('src', responseJson[0]);
                    $("#pic_description").text(responseJson[1]);
                    $("#pic").attr('alt', responseJson[2]);
                });
            });
        </script>
    </head>
    <%
        String dbURL = "jdbc:derby://localhost:1527/RandomPictures";
        String username = "marco";
        String password = "2212";
        Connection conn = null;

        try {
            Class.forName("org.apache.derby.jdbc.ClientDriver");
            conn = DriverManager.getConnection(dbURL, username, password);
        } catch (ClassNotFoundException | SQLException ex) {
            out.println("Error in connecting to DB");
        }
        StringBuilder dbOutput = new StringBuilder("<h1>");
        Statement stm = conn.createStatement();
    %>
    <body>
        <div class="sidenav">
            <%
                try {
                    String sql = "SELECT * FROM PICTURE FETCH FIRST 100 ROWS ONLY";
                    ResultSet results = stm.executeQuery(sql);
                    while (results.next()) {
            %>
            <a href="#">
                <div id="link"><%= results.getString(3)%></div>
            </a>
            <%
                    }
                } catch (SQLException ex) {
                    dbOutput.append(ex.toString()).append("</h1>");
                }
            %>
        </div>
        <div class="main">
            <h1>Watch beautiful pictures</h1>
            <p id="pic_description">Click one of the links in the left, a picture will appear here!</p>
            <img id="pic" />
        </div>
    </body>
</html>
