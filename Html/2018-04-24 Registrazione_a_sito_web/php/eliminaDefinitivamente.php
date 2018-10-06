<?php
require "connect.php";

$numberToDelete = $_POST['numberToDelete'];

$sqlDelete = "DELETE FROM phptest.utenti WHERE utenti.id='".$numberToDelete."'";
$resultDelete = mysqli_query($connect, $sqlDelete);
header("Location: index.php");
// ADESSO SELEZIONARE L'ID DEL RECORD DA ELIMINARE E PASSARLO A QUESTA PAGINA, METTERE WHERE NELLA QUERY 
?>