function hideCheckbox(){
// onclick del checkbox per la registrazione
// solo se è inserito ci si può registrare
  var submitButton = document.getElementById("submitReg");
  if(submitButton.disabled == true){
    submitButton.disabled = false;
  } else {
    submitButton.disabled = true;
  }
}