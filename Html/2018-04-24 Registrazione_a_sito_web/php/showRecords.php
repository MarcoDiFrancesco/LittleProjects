<?php
require "connect.php";

$queryAllData = "SELECT ruolo,nome,cognome,datanascita,sesso,indirizzo,email,username,password FROM phptest.utenti";
$result = mysqli_query($connect, $queryAllData);

if (mysqli_num_rows($result) > 0) {
	
	echo "<table>";
  while($row = mysqli_fetch_assoc($result)) {
		echo "<tr>";
		echo "<td>Ruolo: " . $row["ruolo"]. "</td>".
		" <td> Nome: " . $row["nome"]. "</td>".
		" <td> Cognome: " . $row["cognome"]. "</td>".
		" <td> Data di nascita: " . $row["datanascita"]. "</td>".
		" <td> Sesso: " . $row["sesso"]. "</td>".
		" <td> Indirizzo: " . $row["indirizzo"]. "</td>".
		" <td> Email: " . $row["email"]. "</td>".
		" <td> Username: " . $row["username"] . "</td>".
		"</tr>";
	}
	echo "</table>";	
} else { // in caso non ci siano records mostra il messaggio
  echo "Non ci sono persone all'interno della tabella";
}

mysqli_close($connect);
?>
