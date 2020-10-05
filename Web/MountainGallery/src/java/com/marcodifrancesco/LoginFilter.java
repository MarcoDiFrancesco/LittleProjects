package com.marcodifrancesco;

import java.io.IOException;
import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class LoginFilter implements Filter {

    private HttpServletRequest httpRequest;
    private HttpServletResponse httpResponse;

    private FilterConfig filterConfig = null;

    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain)
            throws IOException, ServletException {
        httpRequest = (HttpServletRequest) request;
        httpResponse = (HttpServletResponse) response;

        // Create session if doesn't exist
        HttpSession session = httpRequest.getSession();

        boolean is_logged = false;
        // Check if user is logged in
        if (session.getAttribute("email") != null) {
            is_logged = true;
        }

        boolean isHome = (httpRequest.getRequestURI().equals(httpRequest.getContextPath() + "/")
                || httpRequest.getRequestURI().equals(httpRequest.getContextPath() + "/index.jsp"));
        boolean isLoginJsp = (httpRequest.getRequestURI().equals(httpRequest.getContextPath() + "/login.jsp"));
        boolean isLoginServlet = (httpRequest.getRequestURI().equals(httpRequest.getContextPath() + "/LoginCheck"));
        boolean isRegisterJsp = (httpRequest.getRequestURI().equals(httpRequest.getContextPath() + "/register.jsp"));
        boolean isRegisterServlet = (httpRequest.getRequestURI().equals(httpRequest.getContextPath() + "/RegisterCheck"));

        if (is_logged) {
            // If user is logged in, do not allow him to enter login or register page
            if (isLoginJsp || isRegisterJsp) {
                httpResponse.sendRedirect("gallery.jsp");
            }
        } else {
            // If user is not logged in, and is not in one of these pages, redirect him to the login page
            if (!isHome && !isLoginJsp && !isLoginServlet && !isRegisterJsp && !isRegisterServlet) {
                httpResponse.sendRedirect("login.jsp");
            }
        }
        chain.doFilter(request, response);
    }

    public void destroy() {
        this.filterConfig = null;
    }

    public void init(FilterConfig filterConfig) {
        this.filterConfig = filterConfig;
    }

    public void log(String msg) {
        filterConfig.getServletContext().log(msg);
    }
}
