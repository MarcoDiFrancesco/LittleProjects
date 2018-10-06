<?php
require("connect.php");
$sqlRicercaParola = "select calciatori.matricola, max(calciatori_squadre.goal) as maxgoal from calciatori_squadre,squadre,calciatori where calciatori_squadre.matricola = calciatori.matricola and calciatori_squadre.id_squadra = squadre.id_squadra";
$result = mysqli_query($connect, $sqlRicercaParola);
if (mysqli_num_rows($result) > 0) {
	echo "<table>";
	while ($row=mysqli_fetch_assoc($result)) {
		echo "<tr>";
		echo "<td>".$row["matricola"]."</td>";
		echo "<td>".$row["maxgoal"]."</td>";
		echo "</tr>";
	}
	echo "</table>";
} else {
	echo "Non ci sono risultati";
}
?>
