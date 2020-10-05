package com.marcodifrancesco;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class GalleryAdd extends HttpServlet {

    String dbURL = "jdbc:derby://localhost:1527/gallery";
    String username = "name";
    String password = "name";
    Connection conn = null;

    @Override
    public void init() {
        try {
            Class.forName("org.apache.derby.jdbc.ClientDriver");
            conn = DriverManager.getConnection(dbURL, username, password);
        } catch (ClassNotFoundException | SQLException ex) {
            log("Failed connection to database");
        }
    }

    @Override
    public void destroy() {
        try {
            conn.close();
        } catch (SQLException ex) {
            log("Failed disconnection from database");
        }
    }

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        Boolean executed = true;
        String id = request.getParameter("id");
        String name = request.getParameter("name");
        String height = request.getParameter("height");
        String description = request.getParameter("description");
        Mountain mountain = new Mountain(id, name, height, description);
        try {
            Statement stmt = conn.createStatement();
            String sql = mountain.getInsertSql(); // Get sql query
            stmt.execute(sql);
        } catch (SQLException ex) {
            log("Error in executing query");
            executed = false;
        }
        log("End of exec");
        try (PrintWriter out = response.getWriter()) {
            out.println(executed);
        }
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        log("Post received");
        processRequest(request, response);
    }
}
