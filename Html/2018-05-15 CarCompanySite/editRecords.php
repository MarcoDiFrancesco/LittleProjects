<?php
require "connect.php";
$descrizioneEdit = $_POST['descrizione'];
$IDEdit = $_POST['id'];

$queryEdit = "UPDATE carcompany.pezziricambio SET descrizione='".$descrizioneEdit."' WHERE id='".$IDEdit."'";

$result = mysqli_query($connect, $queryEdit);

mysqli_close($connect);
?>
