# Database notes

## Database management system

A **database** is a large and einterated collection of data.  
It's formed by **entities** (e.g. students, courses) and **relationships** (e.g. Madonna is taking the course of Databases).  
A **database management system** (also known as DBMS) is a software designed to store and manage databases.  

A dbms diffentiates a file becuase it:

- can separate main memory and secondary memory (a problem for huge files)
- can make queries
- can protect data from inconsistency
- has crash recovery
- has security and access control
- is more efficient in accessing data

## Levels of abstraction

![Levels of abstraction](https://i.imgur.com/2qj9ayV.png)

**Views** describe how users see data, or example `Course_info(cid:string,enrollment:integer)`.  
**Conceptual schema** defines logical stucture, for example `sid:string`, `name:sting`, `login:sting`, `age:integer`.  
**Physical schema** describes the files and indexes used, for example index on the first column of `Students`.  

## Transaction

A **transaction** is an execution of a database program (reads/writes). Each transaction must leave a database in a consistent state. Before reading and writing the transaction requests a lock on the pbjectm and waits till the dbms gives it the lick.  
A dbms ensures **atomicity**, so if the system crashes in the middle of a transaction, thanks to a log the bdms is abto to restore the transaction.  

![Trasactions](https://i.imgur.com/myAZJh8.png)

![Trasactions 2](https://i.imgur.com/yHT60Qg.png)

![Trasactions 3](https://i.imgur.com/7uX6twt.png)

## ER models

An **entity** is an object distinguishable from other objects, in a database describes an entity using **attributes**.
An **entity set** is a collection of similar entities (e.g. employees). An entity set has a key.

![ER model example](https://i.imgur.com/uOBQ6sT.png)

## Relationships

**Relationships** are rappresented as a diamond. Relationships connect two or more entity sets.

![Relationships](https://i.imgur.com/Sor5JZ2.png)

The **multiplicity od relationships** is the way how entity sets are rappresented.

![Multiplicity of relationships](https://i.imgur.com/Iy5XnDK.png)

The multi-way relationships is not gerally sufficient to express any possibility. So there can be more ways to write a correct schema.

## Normalizzazione relazionale

La normalizzazione conclude un database.
La chiave candidata é un insieme di uno o più attributi che possono diventare chiave primaria, ogni chiave candidata individua in maniera univoca ogni record della mia tabella, e determinano ogni attributo. La chiave primaria è la più piccola tra le chiave candidate. La dipendenza funzionale quando il valore di un insieme degli attributi A determina un singolo valore degli attributi di B. Dipendenza transitiva quando A determina B e B determina C, quindi A determina transitivamente C.

---

## Reletional algebra

![Operators relational algebra](https://i.imgur.com/h8yn9M0.png)

![Projection](https://i.imgur.com/iSYWFNY.png)

![Selection](https://i.imgur.com/uT7MIbz.png)

![Union](https://i.imgur.com/EETC0W5.png)

![Cross-product](https://i.imgur.com/1WEw3Wr.png)

![Joins](https://i.imgur.com/tl1D0GF.png)

![Joins2](https://i.imgur.com/xxWxNHp.png)

![Division](https://i.imgur.com/s3V5qO6.png)

![Division example](https://i.imgur.com/4KFPGhB.png)

![Division 2](https://i.imgur.com/42OYwJ6.png)

---

## SQL

### Comandi SQL

Seleziona la tabella nomi con almeno 6 lettere

``` SQL
SELECT nome AS Nomi
FROM automobilista
WHERE nome LIKE '_%_____'
```

Seleziona i nomi che abitano a Venezia o Trivignano

``` SQL
SELECT nome AS Nomi
FROM automobilista
WHERE Citta IN ('Venezia','Trivignano')
```

### SQL JOIN

``` SQL
SELECT Orders.OrderID, Customers.CustomerName, Orders.OrderDate
FROM Orders
INNER JOIN Customers ON Orders.CustomerID=Customers.CustomerID;
```

### SQL LEFT JOIN e SQL RIGHT JOIN

``` SQL
non molto utile
```

JOIN con WHERE

``` SQL
SELECT automobilista.Nome, automobilista.Codice_Fiscale, auto.Targa, infrazioni.Data
FROM auto, automobilista, infrazioni
WHERE automobilista.Codice_Fiscale = auto.FK_Codice_Fiscale AND
infrazioni.FK_Targa = auto.Targa
```

JOIN di 4 tabelle

``` SQL
SELECT automobilista.Nome, automobilista.Codice_Fiscale, auto.Targa, infrazioni.Data, agenti.Matricola
FROM auto, automobilista, infrazioni, agenti
WHERE automobilista.Codice_Fiscale = auto.FK_Codice_Fiscale AND
infrazioni.FK_Targa = auto.Targa AND
infrazioni.FK_Matricola = agenti.Matricola
```

SELECT UNION

GROUP BY

Mostra il numero di multe che ogni agente ha fatto con alias Numero

``` SQL
SELECT agenti.Nome, COUNT(infrazioni.ID_Infrazione) AS Numero_Di_Infrazioni
FROM infrazioni
JOIN agenti ON infrazioni.FK_Matricola = agenti.Matricola
GROUP BY agenti.Matricola
ORDER BY Numero_Di_Infrazioni
```

Seleziona nome, matricola e somma del numero di infrazioni e dell’importo di infrazioni e le ordina in modo decrescente per somma dell’importo delle infrazioni

``` SQL
SELECT agenti.Matricola, agenti.Nome, SUM(infrazioni.Importo) AS Importo_totale_infrazioni, COUNT(*) AS Numero_di_infrazioni
FROM infrazioni, agenti
WHERE infrazioni.FK_Matricola = agenti.Matricola
GROUP BY agenti.Matricola
ORDER BY Importo_totale_infrazioni DESC
```

Numero di macchine che ogni automobilista possiede

``` SQL
SELECT automobilista.Codice_Fiscale, automobilista.Nome, COUNT(*) AS Somma_delle_macchine
FROM automobilista, auto
WHERE automobilista.Codice_Fiscale = auto.FK_Codice_Fiscale
GROUP BY automobilista.Codice_Fiscale
ORDER BY automobilista.Codice_Fiscale DESC
```

Numero di tipi di infrazioni che hanno commesso solo le macchine Fiat

``` SQL
SELECT infrazioni.Tipo_Di_Infrazione, COUNT(*) AS Numero_di_infrazioni
FROM auto, infrazioni
WHERE infrazioni.FK_Targa = auto.Targa AND auto.Marca = 'Fiat'
GROUP BY infrazioni.Tipo_Di_Infrazione
```

SQL HAVING Si usa per mettere una condizione, mentre GROUP BY li seleziona tutti:

Nome e indirizzo di automobilisti cui sono contestate almeno 1 infrazione per “Divieto di sosta”

``` SQL
SELECT automobilista.Nome, infrazioni.Tipo_Di_Infrazione, COUNT(*) AS Numero_di_infrazioni
FROM infrazioni, automobilista, auto
WHERE infrazioni.FK_Targa = auto.Targa AND automobilista.Codice_Fiscale = auto.FK_Codice_Fiscale AND infrazioni.Tipo_Di_Infrazione = 'Parcheggio in divieto di sosta'
GROUP BY automobilista.Nome HAVING COUNT(*) >= 1
```

Per ogni prestito il valore del prestito e i dati identificativi dei clienti che lo hanno stipulato

``` SQL
SELECT prestito.importo, clienti.nome
FROM prestito, clienti, cliente_prestito
WHERE cliente_prestito.FK_ID_cliente=clienti.ID_cliente AND prestito.ID_prestito = cliente_prestito.FK_ID_prestito
```

Elenco di tutti i clienti che hanno almeno un deposito e almeno un prestito

``` SQL
SELECT DISTINCT clienti.nome
FROM clienti, prestito, conto, clienti_cc, cliente_prestito, filiale
WHERE prestito.ID_prestito = cliente_prestito.FK_ID_prestito AND clienti.ID_cliente = clienti_cc.FK_ID_cliente AND clienti.ID_cliente = cliente_prestito.FK_ID_cliente
```

Elenco di tutti i clienti titolari di almeno un deposito ma non di un prestito

``` SQL
SELECT DISTINCT clienti.nome
FROM clienti WHERE clienti.nome NOT IN (SELECT clienti.nome FROM clienti, prestito, cliente_prestito
WHERE prestito.ID_prestito = cliente_prestito.FK_ID_prestito AND clienti.ID_cliente = cliente_prestito.FK_ID_cliente)
```

Per ogni filiale il numero dei titolari di conti correnti (controllare ogni cliente una sola volta)

``` SQL
SELECT filiale.ID_filiale, filiale.citta, COUNT(*) AS Numero_di_conti
FROM filiale, conto
WHERE filiale.ID_filiale = conto.FK_ID_filiale
GROUP BY filiale.ID_filiale
```

Elenco di tutte le filiali che hanno un patrimonio maggiore del più piccolo capitale delle filiali di Venezia

``` SQL
SELECT filiale.indirizzo_filiare, filiale.patrimonio, filiale.ID_filiale
FROM filiale
WHERE filiale.patrimonio > (SELECT MIN(filiale.patrimonio) FROM filiale WHERE filiale.citta = 'venezia')
```

Nome della filiale o delle filiali con il saldo medio più alto - da sistemare

``` SQL
SELECT filiale.ID_filiale, MAX(media)
FROM filiale, (SELECT filiale.ID_filiale AVG(saldo) AS 'media'
FROM conto, filiale
WHERE conto.FK_ID_filiale = filiale.ID_filiale
GROUP BY conto.FK_ID_filiale) as T
```

Elenco di clienti che hanno un deposito presso tutte le filiali di Venezia

``` SQL
SELECT clienti.nome, filiale.citta, filiale.indirizzo_filiare
FROM clienti_cc, conto, filiale, clienti
WHERE clienti_cc.FK_ID_cliente=clienti.ID_cliente AND clienti_cc.FK_ID_conto=conto.ID_conto AND conto.FK_ID_filiale=filiale.ID_filiale AND filiale.citta='venezia'
```

Patrimonio medio delle filiali

``` SQL
SELECT filiale.indirizzo_filiare, AVG(filiale.patrimonio) AS media, SUM(conto.saldo) AS somma
FROM filiale, conto
WHERE filiale.ID_filiale=conto.FK_ID_filiale
GROUP BY filiale.indirizzo_filiare HAVING AVG(conto.saldo)>10000
```

Nome degli attori che hanno recitato almeno due volte un film di genere horror

``` SQL
SELECT genere.Descrizione, attori.Nominativo
FROM genere, film, attori, recita_in
WHERE genere.Id_Genere=film.Id_Genere AND attori.Id_Attore=recita_in.Id_Attore AND film.Id_Film=recita_in.Id_Film AND genere.Descrizione='Horror'
GROUP BY attori.Nominativo HAVING COUNT(genere.Descrizione)>=1
```

Quenti film ci sono per genere

``` SQL
SELECT COUNT(film.Titolo),genere.Descrizione
FROM genere,film
WHERE genere.Id_Genere=film.Id_Genere
GROUP BY genere.Id_Genere
```

Quenti film per genere sono maggiori di 2

``` SQL
SELECT COUNT(film.Titolo),genere.Descrizione
FROM genere,film
WHERE genere.Id_Genere=film.Id_Genere
GROUP BY genere.Id_Genere HAVING COUNT(film.Titolo)>=2
```

Titolo e numero di premi vinti da ogni film premiato nell’anno 2003

``` SQL
SELECT film.Titolo, COUNT(*) AS Numero_Premi
FROM film, premi, ha_vinto
WHERE film.Id_Film=ha_vinto.Id_Film AND premi.Id_Premio=ha_vinto.Id_Premio AND ha_vinto.Anno='2001'
GROUP BY film.Titolo
```

Film di genere Animazione, quello (solo 1) che ha minor durata

``` SQL
SELECT film.Titolo, genere.Descrizione, MIN(film.Durata)
FROM film, genere
WHERE genere.Descrizione='Animazione' AND genere.Id_Genere=film.Id_Genere
```

Film di genere Animazione, quelli (anche più di uno) che hanno minor durata

``` SQL
SELECT film.Titolo, genere.Descrizione
FROM film, genere
WHERE genere.Descrizione='Animazione'
AND genere.Id_Genere=film.Id_Genere
AND film.Durata=(SELECT MIN(film.Durata)
FROM film, genere
WHERE genere.Id_Genere=film.Id_Genere
AND genere.Descrizione='Animazione')
```

Film di un attore tutti i film ordinati per anno

``` SQL
SELECT attori.Nominativo, film.Titolo, film.Anno
FROM film,recita_in,attori
WHERE attori.Id_Attore=recita_in.Id_Attore AND film.Id_Film=recita_in.Id_Film AND attori.Id_Attore='6'
GROUP BY film.Anno
```
