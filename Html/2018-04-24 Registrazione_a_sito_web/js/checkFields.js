function checkSubmit(){
  var nome = document.getElementById("nome").value;
  var cognome = document.getElementById("cognome").value;
  
  submitOk = "true";
  if(cognome.length<2 || cognome.length>20){
	  alert("Il cognome deve essere più corto/lungo");
    submitOk = "false";
  }
  if(nome.length<2 || nome.length>20){
    alert("Il nome deve essere più corto/lungo");
    submitOk = "false";
  }
return true;
}