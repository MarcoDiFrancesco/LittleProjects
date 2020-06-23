<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.util.Date"%>
<%@page language="java"  session="true" %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Session Test JSP</title>
    </head>
    <body>
        <%
            Integer accessCount;
            String cookieName = "accessCount";
            accessCount = (Integer) session.getAttribute(cookieName);
            if (accessCount == null) {
                accessCount = 0;
            } else {
                accessCount = new Integer(accessCount + 1);
            }
            session.setAttribute(cookieName, accessCount);
        %>
        <p>Is session new? <%= session.isNew()%></p>
        <h2>You accessed this site <%= accessCount%> times in this session.</h2>
        <ul>
            <li>Your session ID is <%= session.getId()%></li>
            <li>Session creation time is <%= new Date(session.getCreationTime())%> </li>
            <li>Session last access time is <%= new Date(session.getLastAccessedTime())%> </li>
            <li>Session max inactive interval is <%= session.getMaxInactiveInterval()%> seconds</li>
        </ul>
        <p><a href="<%= request.getRequestURI()%>">Refresh</a></p>
        <p><a href="<%= response.encodeURL(request.getRequestURI())%>">Refresh with  URL rewriting</a></p>
        <form method="GET" action="deleteSession.jsp">
            <input type="submit" value="End Session">
        </form>
    </body>
</html>