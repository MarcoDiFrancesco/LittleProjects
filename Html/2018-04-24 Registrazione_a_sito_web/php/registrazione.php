<?php
// richiesta in POST dei dati dalla pagina di registrazione
$ruolo = $_POST['ruolo'];
$nome = $_POST['nome'];
$cognome = $_POST['cognome'];
$datanascita = $_POST['datanascita'];
$sesso = $_POST['sesso'];
$indirizzo = $_POST['indirizzo'];
$mail = $_POST['email'];
$username = $_POST['regUsername'];
$password = $_POST['regPassword'];

// stampa a video dei dati di iscrizione
echo '<h1>Registrazione completata</h1>';
echo '<p>'."In ruolo di: ".$ruolo.'</p>';
echo '<p>'.$nome.'</p>';
echo '<p>'.$cognome.'</p>';
echo '<p>'.$datanascita.'</p>';
echo '<p>'.$sesso.'</p>';
echo '<p>'.$indirizzo.'</p>';
echo '<p>'.$mail.'</p>';
echo '<p>'.$username.'</p>';

// connessione al database
require "connect.php";

// creazione del database se non esiste, delle tabelle e di alcuni record
require "createDatabase.php";

// inserimento del record nel database
$insertRecord = "INSERT INTO phptest.utenti (ruolo,nome,cognome,datanascita,sesso,indirizzo,email,username,password)
VALUES ('".$ruolo."','".$nome."','".$cognome."','".$datanascita."','".$sesso."','".$indirizzo."','".$mail."','".$username."','".$password."')";
$connect->query($insertRecord);

?>
