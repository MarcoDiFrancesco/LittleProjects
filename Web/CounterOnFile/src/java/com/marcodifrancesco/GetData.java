/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.marcodifrancesco;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author marco
 */
@WebServlet(name = "GetData", urlPatterns = {"/GetData"})
public class GetData extends HttpServlet {
    Counter counter;
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
            request.getRequestDispatcher("/first_part.html").include(request, response);
            counter.increase();
            out.println(counter);
            request.getRequestDispatcher("/last_part.html").include(request, response);
        }
        log("processRequest executed");
    }

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
         log("doGet executed");
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
         log("doPost executed");
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
    
    @Override
    public void init() {
        String context_path = getServletContext().getRealPath("/");
        String file_path = context_path + "/counter_data.txt";
        File my_file = new File(file_path);
        if (my_file.exists()) {
            try {
                ObjectInputStream ois = new ObjectInputStream(
                    new FileInputStream(my_file)
                );
                counter = (Counter) ois.readObject();
            } catch (Exception e) {
                log("Getting data from file went wrong");
            }
        } else {
            counter = new Counter();
        }
        
        log("init executed");
    }
    
    @Override
    public void destroy() {
        String context_path = getServletContext().getRealPath("/");
        String file_path = context_path + "/counter_data.txt";
                File my_file = new File(file_path);
        if (!my_file.exists()) {
            try {
                my_file.createNewFile();
            } catch (Exception e) {
                log("File creation went wrong");
            }
        }
        
        try {
            ObjectOutputStream oos = new ObjectOutputStream(
                new FileOutputStream(my_file)
            );
            oos.writeObject(counter);
        } catch (Exception e) {
            log("Writing data to file went wrong");
        }
        
        log("destroy executed");
    }

}
