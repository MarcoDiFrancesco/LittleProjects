<%@page import="java.util.ArrayList"%>
<%@page import="com.marcodifrancesco.Mountain"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Statement"%>
<%@page import="java.sql.SQLException"%>
<%@page import="java.sql.DriverManager"%>
<%@page import="java.sql.Connection"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%
    String dbURL = "jdbc:derby://localhost:1527/gallery";
    String username = "name";
    String password = "name";
    Connection conn = null;

    try {
        Class.forName("org.apache.derby.jdbc.ClientDriver");
        conn = DriverManager.getConnection(dbURL, username, password);
    } catch (ClassNotFoundException | SQLException ex) {
        out.println("Error in connecting to DB");
    }
    Statement stm = conn.createStatement();
    ArrayList<Mountain> mountains = new ArrayList<Mountain>();
    try {
        String sql = "SELECT * FROM NAME.MOUNTAIN FETCH FIRST 100 ROWS ONLY";
        ResultSet results = stm.executeQuery(sql);
        while (results.next()) {
            mountains.add(new Mountain(results.getString(1), results.getString(2), results.getString(3), results.getString(4)));
        }
    } catch (SQLException ex) {
        log("Error in executing query in gallery JSP");
    }
%>
<html>
    <head>
        <title>Gallery</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css">
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.16.0/umd/popper.min.js"></script>
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/js/bootstrap.min.js"></script>
        <script src="scripts.js"></script>
    </head>
    <body onload="getLastVisited();">
        <%@include file="navbar.html" %>
        <div class="container-fluid my-3">
            <h1>Gallery</h1>
            <p>Welcome to the gallery.</p>
            <p>Here are the last 5 things you visited:</p>
            <div class="row">
                <div class="col">
                    <table class="table table-striped" id="tableMountains">
                        <thead>
                            <tr>
                                <th>ID</th>
                                <th>Mountain name</th>
                                <th>Height</th>
                                <th>Details</th>
                            </tr>
                        </thead>
                        <tbody>
                            <%
                                for (Mountain mountain : mountains) {
                            %>
                            <tr>
                                <td><%= mountain.getId()%></td>
                                <td><%= mountain.getName()%></td>
                                <td><%= mountain.getHeight()%></td>
                                <td><a href="#" class="btn btn-secondary" role="button" onclick="getDetails(<%= mountain.getId()%>);">Watch details</a></td>
                            </tr>
                            <%
                                }
                            %>
                        </tbody>
                    </table>
                    <div class="m-3">
                        <h3>Add new element</h3>
                        <input type="text" class="form-control my-3" id="mountain_id_input" placeholder="ID">
                        <input type="text" class="form-control my-3" id="mountain_name_input" placeholder="Mountain name">
                        <input type="text" class="form-control my-3" id="mountain_heigh_input" placeholder="Height">
                        <input type="text" class="form-control my-3" id="mountain_description_input" placeholder="Description">
                        <p id="adding_error" style="color: red;"></p>
                        <button onclick="addObject();" type="button" class="btn btn-primary btn-block">Upload new Mountain</button>
                    </div>
                </div>
                <div class="col">
                    <h1 id="mountain_name_details"></h1>
                    <h3 id="mountain_id_details">Choose a mountain to see details</h3>
                    <h3 id="mountain_height_details"></h3>
                    <p id="mountain_description_details"></p>
                    <div id="last_visited_div"></div>
                </div>
            </div>
        </div>
    </body>
</html>
