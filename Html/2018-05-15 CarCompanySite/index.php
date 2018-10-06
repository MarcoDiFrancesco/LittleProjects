<!DOCTYPE html>
<html>
<style>div{background: lightgreen;padding: 30px;margin: 30px;    display: inline-block;}</style>
<body>
	<?php
		// creazione del database in caso non esista
		require 'connect.php';
		require 'createDatabase.php';
	?>
  <div>
      <h1>Informazioni officina</h1>
      <p>Mostra le informazioni dell'officina selezionata</p>
	<form method="post" action="showCarCompany.php">
		ID:<input type="text" name="id">
		<input type="submit" id="submit" value="Mostra">
	</form>
	<br>
  </div>
  <div>
      <h1>Mostra Oggetti</h1>
      <p>Mostra tutti gli oggetti</p>
	<form method="post" action="showRecords.php">
		<input type="submit" id="submit" value="Mostra">
	</form>
	<br>
  </div>
  <div>
      <h1>Modifica pezzi di ricambio</h1>
      <p>Modifica i pizzi di ricambio fornendo ID e descrizione da modificare</p>
	<form method="post" action="editRecords.php">
		ID:<input type="text" name="id">
		Descrizione:<input type="text" name="descrizione">
		<input type="submit" id="submit" value="Modifica Dati">
	</form>
	<br>
  </div>


</body>
</html>