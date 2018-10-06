<?php
require("connect.php");
$sqlRicercaParola = "select campionati.anno, squadre.nome_societa, campionati.punteggio from campionati,squadre where campionati.id_squadra = squadre.id_squadra group by campionati.anno asc";
$result = mysqli_query($connect, $sqlRicercaParola);
if (mysqli_num_rows($result) > 0) {
	echo "<table>";
	while ($row=mysqli_fetch_assoc($result)) {
		echo "<tr>";
		echo "<td>".$row["anno"]."</td>";
		echo "<td>".$row["nome_societa"]."</td>";
		echo "<td>".$row["punteggio"]."</td>";
		echo "</tr>";
	}
	echo "</table>";
} else {
	echo "Non ci sono risultati";
}
?>
