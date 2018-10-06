<?php
$dbserver = "localhost";
$dbnickname = "root";
$dbpassword = "";

$connect = new mysqli($dbserver,$dbnickname,$dbpassword);
if($connect->connect_error){
  die("Il database non esiste, tornare nella registrazione e creare almeno un utente per visualizzare i risultati");   
}
?>