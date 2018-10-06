<?php
$grandezzaTabella = $_POST['tabella'];
echo "<table>";
for ($w = 1; $w <= $grandezzaTabella; $w++) {
    echo("<tr>");
    for ($i = 1; $i <= $grandezzaTabella; $i++) {
        echo("<td>" . $i*$w . "</td>");
    }
    echo("</tr>");
}
echo "</table>";
?>