package it.unitn.disi.ronchet.webProg;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
// modified from https://www3.ntu.edu.sg/home/ehchua/programming/java/JavaServlets.html
@WebServlet(urlPatterns = {"/DemoSession"})
public class DemoSession extends HttpServlet {
    PrintWriter out=null;
    private void p(String s) {
       out.println(s);
   }
    @Override
   public void doGet(HttpServletRequest request, HttpServletResponse response)
               throws IOException, ServletException {
      out = response.getWriter();
 
      // Return the existing session if there is one. Create a new session otherwise.
      HttpSession session = request.getSession();
      Integer accessCount;
      synchronized(session) {
         accessCount = (Integer)session.getAttribute("accessCount");
         if (accessCount == null) {
            accessCount = 0;   // autobox int to Integer
         } else {
            accessCount = new Integer(accessCount + 1);
         }
         session.setAttribute("accessCount", accessCount);
      }
      try {
         response.setContentType("text/html;charset=UTF-8");
         p("<!DOCTYPE html>"
            +"<html>"
            +"<head><title>Session Test Servlet</title></head><body>");
         //out.println("<head><meta http-equiv='Content-Type' content='text/html; charset=UTF-8'>");
         p("Session is new? "+session.isNew());
         p("<h2>You accessed this site " + accessCount + " times in this session.</h2>");
         p("<ul><li>Your session ID is " + session.getId() + "</li>");
         p("<li>Session creation time is " +
               new Date(session.getCreationTime()) + "</li>");
         p("<li>Session last access time is " +
               new Date(session.getLastAccessedTime()) + "</li>");
         p("<li>Session max inactive interval  is " +
               session.getMaxInactiveInterval() + " seconds)</li></ul>");
 
         p("<p><a  href='" + request.getRequestURI() +  "'>Refresh</a>");
         p("<p><a  href='" + response.encodeURL(request.getRequestURI())  +
                     "'>Refresh with  URL rewriting</a>\n");
         p("<form method=\"GET\" action=\"endSession\">\n"
            +"<input type=\"submit\" value=\"End Session\">\n"
            +"</form>"); 
         p("</body></html>");
      } finally {
         out.close();  // Always close the output writer
      }
      
   }
}
