package com.marcodifrancesco;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class GetLastVisited extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        // Send JSON containing the list with all the visted elements
        response.setContentType("application/json");
        String last_visited_str = "{ \"list\": [";
        HttpSession session = request.getSession();
        List<Mountain> last_visited = (List<Mountain>) session.getAttribute("last_visited");
        if (last_visited != null) { // If it doesn't exist return only one empty element
            for (Mountain m : last_visited) {
                last_visited_str += String.format("\"%s\",", m.id);
            }
            // Add empty element to compensate the comma added before
            last_visited_str += "\"\"";
        }
        last_visited_str += "]}";
        try (PrintWriter out = response.getWriter()) {
            out.println(last_visited_str);
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
