<%-- 
    Document   : example2
    Created on : Jun 18, 2020, 10:02:53 AM
    Author     : marco
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Example 3</title>
        <script>
            function button1() {
                text = document.getElementById("printText").innerHTML;
                alert(text);
            }
            function button2() {
                text = document.getElementById("printText").innerText;
                alert(text);
            }
            function button3() {
                text = document.getElementById("printText").textContent;
                alert(text);
            }
        </script>
    </head>
    <body>
        <h1>Example 3!</h1>
        <jsp:include page="menu.html" />
        <p>Here are 3 ways to print code in popups.</p>
        <p id="printText">This is the text that should be output, code: <code>code</code>, hidden: <span style="visibility: hidden;">hidden</span>, strong: <strong>strong</strong>.</p>
        <button onclick="button1()">innerHTML (print code)</button>
        <button onclick="button2()">innerText (print text + css)</button>
        <button onclick="button3()">textContent (print text - css)</button>
    </body>
</html>
