package com.marcodifrancesco;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author marco
 */
@WebServlet(name = "Welcome", urlPatterns = {"/Welcome"})
public class Welcome extends HttpServlet {

    String message;
    boolean isInitialIteration;

    private void invalidCookie() {
        message = "This is not a valid cookies";
        isInitialIteration = true;
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        isInitialIteration = false;
        String person_name = request.getParameter("person_name");
        if (person_name != null && !person_name.equals("")) {
            log("Person name is not null");
            Cookie person_name_cookie = new Cookie("person_name", person_name);
            response.addCookie(person_name_cookie);
            message = "Nice to meet you " + person_name;
            Cookie counter_cookie = new Cookie("counter", "0");
            response.addCookie(counter_cookie);
        } else {
            Cookie cookies[] = request.getCookies();
            // Check if cookie is valid
            if (cookies == null || cookies.length == 0) {
                invalidCookie();
            } else {
                Cookie person_name_cookie = null;
                Cookie counter_cookie = null;
                for (Cookie c : cookies) {
                    String cookie_name = c.getName();
                    if (cookie_name.equals("person_name")) {
                        person_name_cookie = c;
                    } else if (cookie_name.equals("counter")) {
                        counter_cookie = c;
                    }
                }
                if (counter_cookie == null) {
                    invalidCookie();
                } else {
                    person_name = person_name_cookie.getValue();
                    String counter_string = counter_cookie.getValue();
                    int counter = Integer.valueOf(counter_string) + 1;
                    counter_cookie.setValue("" + counter);
                    response.addCookie(counter_cookie);
                    message = "Hello " + person_name + " counter: " + counter;
                }
            }
        }

        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>title</title>");
            out.println("</head>");
            out.println("<body>");
            out.println(message);
            if (isInitialIteration) {
                request.getRequestDispatcher("Welcome.html").include(request, response);
            } else {
                request.getRequestDispatcher("DeleteCookies.html").include(request, response);
            }
            out.println("</body>");
            out.println("</html>");
        }
    }

}
