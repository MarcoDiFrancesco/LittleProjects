/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author Marco
 */
@WebServlet(urlPatterns = {"/tabella"})
public class tabella extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>"
                    + "<html>"
                    + "<head>"
                    + "<title>Es 1</title>"
                    + "<style>"
                    + "table{border: 2px solid black;}"
                    + "td,th{font-size: 200%;}"
                    + "</style>"
                    + "</head>"
                    + "<body>"
                    + "<table>"
                    + "<tr>"
                    + "<th colspan='3'>Titolo</th>"
                    + "</tr>"
                    + "<tr>"
                    + "<td>1</td>"
                    + "<td>2</td>"
                    + "<td>3</td>"
                    + "</tr>"
                    + "<tr>"
                    + "<td>4</td>"
                    + "<td>5</td>"
                    + "<td>6</td>"
                    + "</tr>"
                    + "<tr>"
                    + "<td>7</td>"
                    + "<td>8</td>"
                    + "<td>9</td>"
                    + "</tr>"
                    + "</table>"
                    + "</body>"
                    + "</html>");

        }
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
