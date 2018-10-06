<?php
// creazione della tabella in cui si andranno a inserire i record in caso questa non esista 
$sqlCreateTable = "CREATE DATABASE IF NOT EXISTS CarCompany;
CREATE TABLE IF NOT EXISTS `CarCompany`.`officine` (
  `ID` INT(8) NOT NULL AUTO_INCREMENT , PRIMARY KEY (`ID`),
  `nome` VARCHAR(255) NOT NULL,
  `dettagli` VARCHAR(255) NOT NULL
);
CREATE TABLE IF NOT EXISTS `CarCompany`.`affiliati` (
  `ID` INT(8) NOT NULL AUTO_INCREMENT , PRIMARY KEY (`ID`),
  `cognome` VARCHAR(255) NOT NULL,
  `nome` VARCHAR(255) NOT NULL,
  `telefono` VARCHAR(255) NOT NULL
);
CREATE TABLE IF NOT EXISTS `CarCompany`.`pezziRicambio` (
  `ID` INT(8) NOT NULL AUTO_INCREMENT , PRIMARY KEY (`ID`),
  `descrizione` VARCHAR(255) NOT NULL,
  `costoUnitario` VARCHAR(255) NOT NULL,
  `quantita` VARCHAR(255) NOT NULL,
  `IDOfficina` INT(8) NOT NULL,
  FOREIGN KEY (`IDOfficina`) REFERENCES `CarCompany`.`affiliati`(`ID`)
);
CREATE TABLE IF NOT EXISTS `CarCompany`.`serviziOfferti` (
  `ID` INT(8) NOT NULL AUTO_INCREMENT , PRIMARY KEY (`ID`),
  `descrizione` VARCHAR(255) NOT NULL,
  `costoUnitario` VARCHAR(255) NOT NULL,
  `IDOfficina` INT(8) NOT NULL,
  FOREIGN KEY (`IDOfficina`) REFERENCES `CarCompany`.`affiliati`(`ID`)
);
CREATE TABLE IF NOT EXISTS `CarCompany`.`accessoriInVendita` (
  `ID` INT(8) NOT NULL AUTO_INCREMENT , PRIMARY KEY (`ID`),
  `descrizione` VARCHAR(255) NOT NULL,
  `costoUnitario` VARCHAR(255) NOT NULL,
  `IDOfficina` INT(8) NOT NULL,
  FOREIGN KEY (`IDOfficina`) REFERENCES `CarCompany`.`affiliati`(`ID`)
)ENGINE=MEMORY";-
$connect->query($sqlCreateTable);

// creazione di alcuni record inseriti all'interno del database
$sqlAddRecords = "";

?>