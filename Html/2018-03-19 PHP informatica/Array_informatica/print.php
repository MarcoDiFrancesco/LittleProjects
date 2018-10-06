<?php
$positionArray = $_POST["position"]; // Passo in post la posizione
$insert = $_POST["carattere"]; 
$array = array("zero","uno","due");

echo "<br>Old array: ";
foreach ($array as $x){ echo "$x "; }
print_r(array_splice($array, $positionArray, 0, $insert));
echo "<br>New array: ";
foreach ($array as $x){ echo "$x "; }
?>