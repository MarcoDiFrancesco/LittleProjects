<?php
require "connect.php";
$id = $_POST['id'];
$queryAllData = "SELECT id,nome,dettagli FROM carcompany.officine WHERE officine.id='".$id."'";
$result = mysqli_query($connect, $queryAllData);

if (mysqli_num_rows($result) > 0) {
	
	echo $row["dettagli"];

} else { // in caso non ci siano records mostra il messaggio
  echo "Non esiste l'officina selezionata";
}

mysqli_close($connect);
?>
