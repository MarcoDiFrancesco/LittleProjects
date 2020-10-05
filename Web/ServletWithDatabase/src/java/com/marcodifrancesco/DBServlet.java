package com.marcodifrancesco;

import java.io.IOException;
import java.io.PrintWriter;
import java.io.StringWriter;
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

    String dbURL = "jdbc:derby://localhost:1527/example";
    String username = "marco";
    String password = "marco";
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
        StringBuilder dbOutput = new StringBuilder();
        try {
            Statement stm = conn.createStatement();
            String sql = "SELECT * FROM PEOPLE FETCH FIRST 100 ROWS ONLY";
            ResultSet results = stm.executeQuery(sql);
            while (results.next()) {
                dbOutput.append("<p>");
                dbOutput.append(results.getString(1));
                dbOutput.append(" - ");
                dbOutput.append(results.getString(2));
                dbOutput.append(" - ");
                dbOutput.append(results.getString(3));
                dbOutput.append("</p>");
            }
        } catch (SQLException ex) {
            dbOutput.append("<p>");
            dbOutput.append(ex.toString());
            dbOutput.append("</p>");
        }

        try (PrintWriter out = response.getWriter()) {
            out.println("<h1>Servlet connection with database</h1>");
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
}
