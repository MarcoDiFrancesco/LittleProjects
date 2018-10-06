
$(document).ready(function(){
	$('#button1').click(function() {
		$.ajax({
			url:"sql1.php",
			success:function(result){document.getElementById("risultatoRicerca1").innerHTML=result;}, 
			error:function(){document.getElementById("risultatoRicerca1").innerHTML="C'è stato un errore nella ricerca";}
		})
	});
});

$(document).ready(function(){
	$('#button2').click(function() {
		$.ajax({
			url:"sql2.php",
			success:function(result){document.getElementById("risultatoRicerca2").innerHTML=result;}, 
			error:function(){document.getElementById("risultatoRicerca2").innerHTML="C'è stato un errore nella ricerca";}
		})
	});
});

$(document).ready(function(){
	$('#button3').click(function() {
		$.ajax({
			url:"sql3.php",
			success:function(result){document.getElementById("risultatoRicerca3").innerHTML=result;}, 
			error:function(){document.getElementById("risultatoRicerca3").innerHTML="C'è stato un errore nella ricerca";}
		})
	});
});

$(document).ready(function(){
	$('#button4').click(function() {
		$.ajax({
			url:"sql4.php",
			success:function(result){document.getElementById("risultatoRicerca4").innerHTML=result;}, 
			error:function(){document.getElementById("risultatoRicerca4").innerHTML="C'è stato un errore nella ricerca";}
		})
	});
});

$(document).ready(function(){
	$('#button5').click(function() {
		$.ajax({
			url:"sql5.php",
			success:function(result){document.getElementById("risultatoRicerca5").innerHTML=result;}, 
			error:function(){document.getElementById("risultatoRicerca5").innerHTML="C'è stato un errore nella ricerca";}
		})
	});
});
