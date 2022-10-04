<%@page import="java.sql.Statement"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.DriverManager"%>
<%@page import="java.sql.Connection"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%
    // Stringhe di connessione
    String url = "jdbc:derby://localhost:1527/ExamDerbyDB";
    String username = "WEBENGINE";
    String password = "WEBENGINE";
    
    // Risultati null se errore
    ResultSet results = null;
    
    //Connessione al DB
    try{
        Class.forName("org.apache.derby.jdbc.ClientDriver");
        Connection conn = DriverManager.getConnection(url, username, password);
        String sqlQuery = "SELECT * FROM DATA";
        Statement stmt = conn.createStatement();
        results = stmt.executeQuery(sqlQuery);
    } catch (Exception e) {
        e.printStackTrace();
    }
%> 
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
        <script src="https://latemar.science.unitn.it/EsameWeb/Libraries/bootstrap.min.4.5.0.js"></script>
        <link rel="stylesheet" href="css/style.css"/>
    </head>
    <body>
        <div class="container m-5 mx-auto">
            <h1 class="text-center mt-5">Welcome to Sudoku by Dalpiaz Alessandro</h1>
            <div class="text-center mt-5">
                <img class="text-center" width="50%" src="images/image.jpg" alt="Sudoku"/>
            </div>
            <br/>
            <ul>
                <%
                    try{
                        while (results.next()) {
                            %>
                            <li>
                                <a href="game.jsp?index=<%=results.getInt(1)%>">Sudoku n. <%= results.getInt(1) %></a>
                            </li>
                            <%
                        }
                    }catch(Exception e){
                        %>
                        <p>Errore di connessione al DB</p>
                    <%
                    }
                %>
            </ul>
        </div>
    </body>
</html>
