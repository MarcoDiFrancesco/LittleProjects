package com.marcodifrancesco;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class GalleryGet extends HttpServlet {

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
        response.setContentType("application/json");
        String mountain_id = request.getParameter("id");
        String mountain_details = "";
        try {
            Statement stmt = conn.createStatement();
            String sql = "SELECT * FROM NAME.MOUNTAIN WHERE ID=" + mountain_id;
            ResultSet results = stmt.executeQuery(sql);
            results.next(); // Get the first element
            Mountain mountain = new Mountain(results.getString(1), results.getString(2), results.getString(3), results.getString(4));
            mountain_details = mountain.getJson();
            // Add mountain to session last_visited
            HttpSession session = request.getSession();
            ArrayList<Mountain> last_visited = (ArrayList<Mountain>) session.getAttribute("last_visited");
            if (last_visited == null) { // If it didn't exist create it
                last_visited = new ArrayList<>();
            }
            last_visited.add(0, mountain); // Add as first element
            session.setAttribute("last_visited", last_visited);
        } catch (SQLException ex) {
            log("Error in executing query");
        }
        try (PrintWriter out = response.getWriter()) {
            out.println(mountain_details);
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
        processRequest(request, response);
    }
}
