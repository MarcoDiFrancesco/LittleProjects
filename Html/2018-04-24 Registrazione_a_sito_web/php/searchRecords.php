<?php
require "connect.php";

$nomeDaRicercare = $_POST['nomeDaRicercare'];
$typeSearch = $_POST['typeSearch'];

$query = "SELECT ruolo,nome,cognome,datanascita,sesso,indirizzo,email,username,password FROM phptest.utenti WHERE utenti.".$typeSearch." LIKE '".$nomeDaRicercare."%'";
$result = mysqli_query($connect, $query);

if (mysqli_num_rows($result) > 0) {
	echo $style;
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
		" <td> Username: " . $row["username"] . "</td>";
		echo "</tr>";
	}
	echo "</table>";	
} else { // in caso non ci siano records mostra il messaggio
    echo "Non ci sono persone con questo cognome all'interno della tabella";
}

mysqli_close($connect);
?>
