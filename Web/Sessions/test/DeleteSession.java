package it.unitn.disi.ronchet.webProg;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebServlet(name = "endSession", urlPatterns = {"/endSession"})
public class DeleteSession extends HttpServlet {

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        HttpSession s= request.getSession();
        s.invalidate();
        response.setContentType("text/html;charset=UTF-8");
        request.getRequestDispatcher("SessionHasBeenDeleted.html")
                .include(request, response);

    }
}