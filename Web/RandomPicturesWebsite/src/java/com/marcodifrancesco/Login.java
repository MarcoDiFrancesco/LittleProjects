package com.marcodifrancesco;

import com.google.gson.Gson;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author marco
 */
public class Login extends HttpServlet {

    String dbURL = "jdbc:derby://localhost:1527/RandomPictures";
    String username = "marco";
    String password = "2212";
    Connection conn = null;

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String res = "false";
        String user_email = request.getParameter("email");
        String user_password = request.getParameter("password");
        try {
            Class.forName("org.apache.derby.jdbc.ClientDriver");
            conn = DriverManager.getConnection(dbURL, username, password);
        } catch (ClassNotFoundException | SQLException ex) {
        }

        try {
            Statement stm = conn.createStatement();
            String sql = "SELECT * FROM USERS WHERE EMAIL='" + user_email + "' AND PASSWORD='" + user_password + "'";
            System.out.println("sql:" + sql);
            ResultSet results = stm.executeQuery(sql);
            while (results.next()) {
                res = "true";
            }
        } catch (SQLException ex) {
            log("error");
        }

        if (res == "true") {
            Cookie person_name_cookie = new Cookie("person_name", user_email);
            response.addCookie(person_name_cookie);
        }
        request.setAttribute("valid", res);
        request.getRequestDispatcher("/login.jsp").forward(request, response);
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
