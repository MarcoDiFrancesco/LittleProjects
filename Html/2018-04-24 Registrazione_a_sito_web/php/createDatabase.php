<?php
// creazione del database in caso non esista
$sqlCreateDatabase = "CREATE DATABASE IF NOT EXISTS phptest";
$connect->query($sqlCreateDatabase);

// creazione della tabella in cui si andranno a inserire i record in caso questa non esista 
$sqlCreateTable = "CREATE TABLE IF NOT EXISTS `phptest`.`utenti` (
	`ID` INT(8) NOT NULL AUTO_INCREMENT , PRIMARY KEY (`ID`),
	`ruolo` VARCHAR(255) NOT NULL,
  `nome` VARCHAR(255) NOT NULL,
  `cognome` VARCHAR(255) NOT NULL,
  `datanascita` DATE NOT NULL,
  `sesso` VARCHAR(255) NOT NULL,
  `indirizzo` VARCHAR(255) NOT NULL,
  `email` VARCHAR(255) NOT NULL,
  `username` VARCHAR(255) NOT NULL,
  `password` VARCHAR(255) NOT NULL
) ENGINE=MEMORY";
$connect->query($sqlCreateTable);

// creazione di alcuni record inseriti all'interno del database
$sqlAddRecords = "";

?>