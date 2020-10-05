/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.marcodifrancesco;

import java.io.IOException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.StringWriter;
import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;

/**
 *
 * @author marco
 */
public class LoginFilter implements Filter {

    private FilterConfig filterConfig = null;

    private boolean userIsAuthenticated(String email) {
        return true;
    }

    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
        HttpServletRequest hreq = (HttpServletRequest) request;

        String email = request.getParameter("email");
        if (userIsAuthenticated(email)) {
            chain.doFilter(request, response);
        }
        // response.sendError(javax.servlet.http.HttpServletResponse.SC_UNAUTHORIZED);
    }

    public void destroy() {
        this.filterConfig = null;
    }

    public void init(FilterConfig filterConfig) {
        this.filterConfig = filterConfig;
    }
}
