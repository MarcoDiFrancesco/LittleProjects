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
@WebServlet(name="DeleteCookies", urlPatterns={"/DeleteCookies"})
public class DeleteCookies extends HttpServlet {

    
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        Cookie cookies[] = request.getCookies();
        for (Cookie c:cookies) {
            c.setMaxAge(0);
            response.addCookie(c);
        }
        
        response.setContentType("text/html;charset=UTF-8");
        request.getRequestDispatcher("CookiesDeleted.html").include(request, response);
    } 


}
