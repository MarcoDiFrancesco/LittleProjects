<?php

require "connect.php";

// ricerca degli utenti con un certo cognome
$sql = "SELECT cognome FROM phptest.utenti";
$result = mysqli_query($connect, $sql);

// mostra in tabella tutti i risultati 
if (mysqli_num_rows($result) > 0) {
  $a = array();
  $nElements = 0;
  while($row = mysqli_fetch_assoc($result)) {
    $a[$nElements] = $row["cognome"];
    $nElements++;
  }
}

mysqli_close($connect);

$q = $_GET["stringa"];
// verifica se campo esiste
if (strlen($q) > 0){
  $risposta = "";
  // ciclo di ricerca nell'array
  for($i = 0; $i < count($a); $i++){
    // controllo se nome trasformato in minuscolo è stato trovato
    if (strtolower($q) == strtolower(substr($a[$i], 0, strlen($q)))){
      // viene aggiunto il nome alla stringa separandolo dal tag di invio a capo
      $risposta .= $a[$i] . "<BR>";
    }
  }
}

echo $risposta;
?>

