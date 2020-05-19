package com.marcodifrancesco;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author marco
 */
@WebServlet(name = "DBServlet", urlPatterns = {"/DBServlet"})
public class DBServlet extends HttpServlet {

    String dbURL = "jdbc:derby://localhost:1527/mydb";
    String username = "mydb";
    String password = "mydb";
    Connection conn = null;

    @Override
    public void init() {
        try {
            Class.forName("org.apache.derby.jdbc.ClientDriver");
            conn = DriverManager.getConnection(dbURL, username, password);
        } catch (ClassNotFoundException | SQLException ex) {
            Logger.getLogger(DBServlet.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        StringBuilder dbOutput = new StringBuilder("<h1>");
        try {
            Statement stm = conn.createStatement();
            String sql = "SELECT * FROM PICTURE FETCH FIRST 100 ROWS ONLY;";
            ResultSet results = stm.executeQuery(sql);
            while (results.next()) {
                dbOutput.append(results.getString(1)).append(" - ");
                dbOutput.append(results.getString(2)).append(" - ");
                dbOutput.append(results.getString(3)).append("</h1>");
            }
        } catch (SQLException ex) {
            dbOutput.append(ex.toString()).append("</h1>");
        }
        try (PrintWriter out = response.getWriter()) {
            out.println("<h1>Servlet DBServlet at " + request.getContextPath() + "</h1>");
            out.println(dbOutput.toString());
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

    @Override
    public String getServletInfo() {
        return "Short description";
    }

}
