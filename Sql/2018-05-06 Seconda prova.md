Schema logico:
```
CREATE TABLE `materie` ( 
	`idmateria` INT(255) NOT NULL AUTO_INCREMENT , 
	`materia` INT(255) NOT NULL ,
	PRIMARY KEY (`idmateria`)
);
```

```
CREATE TABLE `indirizi` ( 
	`idindirizzo` INT(255) NOT NULL AUTO_INCREMENT , 
	`indirizzo` VARCHAR(255) NOT NULL ,
	PRIMARY KEY (`idindirizzo`)
);
```

```
CREATE TABLE `classi` ( 
	`idclasse` INT(255) NOT NULL AUTO_INCREMENT , 
	`num` INT(255) NOT NULL , 
	`sezione` VARCHAR(255) NOT NULL , 
	`indirizzoFK` INT(255) NOT NULL , 
	`aula` VARCHAR(255) NOT NULL , 
	PRIMARY KEY (`idclasse`),
  FOREIGN KEY (indirizzoFK) REFERENCES indirizi(idindirizzo)
);
```

```
CREATE TABLE `studenti` ( 
	`idstudente` INT(255) NOT NULL AUTO_INCREMENT , 
	`cognome` INT(255) NOT NULL , 
	`nome` VARCHAR(255) NOT NULL , 
	`datanascita` DATE NOT NULL , 
	`indirizzo` VARCHAR(255) NOT NULL , 
	`classeFK` INT(255) NOT NULL , 
	PRIMARY KEY (`idstudente`),
  FOREIGN KEY (classeFK) REFERENCES classi(idclasse)
);
```

```
CREATE TABLE `voti` ( 
	`idvoto` INT(255) NOT NULL AUTO_INCREMENT , 
	`studenteFK` INT(255) NOT NULL , 
	`materiaFK` INT(255) NOT NULL , 
	`voto` VARCHAR(255) NOT NULL , 
	`tipo` VARCHAR(255) NOT NULL , 
	`data` DATE NOT NULL , 
	PRIMARY KEY (`idvoto`),
  FOREIGN KEY (studenteFK) REFERENCES studenti(idstudente),
  FOREIGN KEY (materiaFK) REFERENCES materie(idmateria)
);
```