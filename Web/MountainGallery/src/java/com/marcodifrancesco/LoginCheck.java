package com.marcodifrancesco;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class LoginCheck extends HttpServlet {

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

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        // If user reached this page typing the url, redirect him to login
        response.sendRedirect("login.jsp");
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        HttpSession session = request.getSession();
        boolean credential_correct = false;
        String user_email = request.getParameter("email");
        String user_password = request.getParameter("password");
        Person person = new Person(user_email, user_password);
        try {
            Statement stmt = conn.createStatement();
            String sql = person.getSelectSql();
            ResultSet results = stmt.executeQuery(sql);
            // Check if there is a match
            credential_correct = results.next();
        } catch (SQLException ex) {
            log("Error in executing query");
        }
        if (credential_correct) {
            session.setAttribute("email", person.email);
            response.sendRedirect("gallery.jsp");
        } else {
            response.sendRedirect("login.jsp");
        }
        String message = "You entered the wrong password, try again!";
        session.setAttribute("LoginMessage", message);
    }
}
