<?php
require "connect.php";

$queryAllData = "SELECT id,descrizione,costounitario,quantita,IDOfficina FROM carcompany.pezziricambio";
$result = mysqli_query($connect, $queryAllData);

if (mysqli_num_rows($result) > 0) {
	echo "<table>";
  while($row = mysqli_fetch_assoc($result)) {
		echo "<tr>";
		echo "<td>ID: " . $row["id"]. "</td>".
		" <td> Descrizione: " . $row["descrizione"]. "</td>".
		" <td> Costo Unitario: " . $row["costounitario"]. "</td>".
		" <td> Quantità: " . $row["quantita"]. "</td>".
		" <td> ID Officina in cui è presente l'oggetto: " . $row["IDOfficina"]. "</td>".
		"</tr>";
	}
	echo "</table>";	
} else { // in caso non ci siano records mostra il messaggio
  echo "Non ci sono oggetti all'interno della tabella";
}

mysqli_close($connect);
?>
