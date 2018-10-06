<?php
require "connect.php";

$nomeDaEliminare = $_POST['nomeDaEliminare'];

// ricerca degli utenti con un certo cognome
$sql = "SELECT id,ruolo,nome,cognome,datanascita,sesso,indirizzo,email,username,password FROM phptest.utenti WHERE utenti.cognome LIKE '".$nomeDaEliminare."%'";
$result = mysqli_query($connect, $sql);

// mostra in tabella tutti i risultati 
if (mysqli_num_rows($result) > 0) {
	echo "<style>
	table,tr,td{
		border:1px solid black;
		border-collapse:collapse
	}
	</style>
	
	<form method='post' action='eliminaDefinitivamente.php'>
	<table>";
  while($row = mysqli_fetch_assoc($result)) {
		echo "<tr>".
		" <td><input type='radio' name='numberToDelete' id='numberToDelete' value='".$row["id"]."'></td>".
		" <td> Ruolo: " . $row["ruolo"]. "</td>".
		" <td> Nome: " . $row["nome"]. "</td>".
		" <td> Cognome: " . $row["cognome"]. "</td>".
		" <td> Data di nascita: " . $row["datanascita"]. "</td>".
		" <td> Sesso: " . $row["sesso"]. "</td>".
		" <td> Indirizzo: " . $row["indirizzo"]. "</td>".
		" <td> Email: " . $row["email"]. "</td>".
		" <td> Username: " . $row["username"] . "</td>";
		echo "</tr>";
	}
	echo "</table>";
	echo "<input type='submit' id='submit' value='Elimina definitivamente'>";	
	echo "</form>";
} else { // in caso non ci siano records mostra il messaggio
  echo "Non ci sono persone con questo cognome all'interno della tabella";
}

mysqli_close($connect);
?>
