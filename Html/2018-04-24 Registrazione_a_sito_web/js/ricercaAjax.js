function searchInput(str){
    if (str.length == 0){ // se stringa letta vuota viene inviata risposta blank
        document.getElementById("searchOutput").innerHTML = "";
        return;
    }
    if (window.XMLHttpRequest){ // browser IE7+, Firefox, Chrome, Opera, Safari
        xmlhttp = new XMLHttpRequest();     
    } else { // browser IE6, IE5
        xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
    }
    xmlhttp.onreadystatechange = function(){
        if (xmlhttp.readyState == 4 && xmlhttp.status == 200){ // 4 La richiesta è completa e se status=200 OK
            document.getElementById("searchOutput").innerHTML = xmlhttp.responseText;
        }
    }
    xmlhttp.open("GET", "ajax.php?stringa=" + str, true);
    xmlhttp.send();
}