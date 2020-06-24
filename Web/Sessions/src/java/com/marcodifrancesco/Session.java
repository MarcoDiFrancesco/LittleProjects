package com.marcodifrancesco;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 *
 * @author marco
 */
@WebServlet(name = "Session", urlPatterns = {"/Session"})
public class Session extends HttpServlet {

    PrintWriter out = null;

    /**
     * Function to print
     *
     * @param s
     */
    private void p(String string) {
        out.println(string);
    }

    private void startHtml() {
        p("<!DOCTYPE html>");
        p("<html>");
        p("<head>");
        p("<title>title</title>");
        p("</head>");
        p("<body>");
    }

    private void endHtml() {
        p("</body>");
        p("</html>");
    }

    protected void processRequest(HttpServletRequest request, HttpServletResponse response, HttpSession session, int accessCounter)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try {
            startHtml();
            p("Session is new? " + session.isNew());
            p("<h2>You accessed this site " + accessCounter + " times in this session.</h2>");
            p("<ul><li>Your session ID is " + session.getId() + "</li>");
            p("<li>Session creation time is " + new Date(session.getCreationTime()) + "</li>");
            p("<li>Session last access time is " + new Date(session.getLastAccessedTime()) + "</li>");
            p("<li>Session max inactive interval is " + session.getMaxInactiveInterval() + " seconds)</li></ul>");
            p("<p><a href='" + request.getRequestURI() + "'>Refresh</a>");
            p("<p><a href='" + response.encodeURL(request.getRequestURI()) + "'>Refresh with  URL rewriting</a>\n");
            p("<form method=\"GET\" action=\"endSession\">\n"
                    + "<input type=\"submit\" value=\"End Session\">\n"
                    + "</form>");
            endHtml();
        } finally {
            out.close();
        }
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        out = response.getWriter();

        // Create (in case there isn't one) or return the current session
        HttpSession session = request.getSession();
        Integer accessCounter;

        // syncronized allows to access this block once at a time
        synchronized (session) {
            accessCounter = (Integer) session.getAttribute("accessCount");
            if (accessCounter == null) {
                accessCounter = 0;
            } else {
                accessCounter = new Integer(accessCounter + 1);
            }
            session.setAttribute("accessCount", accessCounter);
        }

        processRequest(request, response, session, accessCounter);
    }
}
