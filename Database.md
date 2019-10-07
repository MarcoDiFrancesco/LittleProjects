# Database
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

### Levels of abstraction

![Levels of abstraction](https://i.imgur.com/2qj9ayV.png)

**Views** describe how users see data, or example `Course_info(cid:string,enrollment:integer)`.  
**Conceptual schema** defines logical stucture, for example `sid:string`, `name:sting`, `login:sting`, `age:integer`.  
**Physical schema** describes the files and indexes used, for example index on the first column of `Students`.  

### Transaction
A **transaction** is an execution of a database program (reads/writes). Each transaction must leave a database in a consistent state. Before reading and writing the transaction requests a lock on the pbjectm and waits till the dbms gives it the lick.  
A dbms ensures **atomicity**, so if the system crashes in the middle of a transaction, thanks to a log the bdms is abto to restore the transaction.  

### ER models
An **entity** is an object distinguishable from other objects, in a database describes an entity using **attributes**.
An **entity set** is a collection of similar entities (e.g. employees). An entity set has a key.

![ER model example](https://i.imgur.com/uOBQ6sT.png)

### Relationships
**Relationships** are rappresented as a diamond. Relationships connect two or more entity sets.

![Relationships](https://i.imgur.com/Sor5JZ2.png)

The **multiplicity od relationships** is the way how entity sets are rappresented.

![Multiplicity of relationships](https://i.imgur.com/Iy5XnDK.png)

The multi-way relationships is not gerally sufficient to express any possibility. So there can be more ways to write a correct schema.
