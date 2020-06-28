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
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author marco
 */
public class GetPicture extends HttpServlet {

    String dbURL = "jdbc:derby://localhost:1527/RandomPictures";
    String username = "marco";
    String password = "2212";
    Connection conn = null;

    @Override
    public void init() {
        try {
            Class.forName("org.apache.derby.jdbc.ClientDriver");
            conn = DriverManager.getConnection(dbURL, username, password);
        } catch (ClassNotFoundException | SQLException ex) {
            Logger.getLogger(GetPicture.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String picture = request.getParameter("q");
        List<String> list = new ArrayList<>();
        try {
            Statement stm = conn.createStatement();
            String sql = "SELECT * FROM PICTURE WHERE CAST(SHORTDESCRIPTION AS VARCHAR(128)) = '" + picture + "'";
            ResultSet results = stm.executeQuery(sql);
            while (results.next()) {
                list.add(results.getString(1));
                list.add(results.getString(2));
                list.add(results.getString(3));
            }
        } catch (SQLException ex) {
            log("error");
        }

        String json = new Gson().toJson(list);

        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        response.getWriter().write(json);
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
