<?php
require("connect.php");
$sqlRicercaParola = "select calciatori.nominativo, calciatori_squadre.ruolo, calciatori.data_nascita from calciatori_squadre, calciatori, squadre where calciatori_squadre.matricola = calciatori.matricola and calciatori_squadre.id_squadra = squadre.id_squadra and squadre.nome_societa = 'spotted hyena' and calciatori_squadre.stagione = '2006'";
$result = mysqli_query($connect, $sqlRicercaParola);
if (mysqli_num_rows($result) > 0) {
	echo "<table>";
	while ($row=mysqli_fetch_assoc($result)) {
		echo "<tr>";
		echo "<td>".$row["nominativo"]."</td>";
		echo "<td>".$row["ruolo"]."</td>";
		echo "<td>".$row["data_nascita"]."</td>";
		echo "</tr>";
	}
	echo "</table>";
} else {
	echo "Non ci sono risultati";
}
?>
