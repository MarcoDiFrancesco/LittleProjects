# Calolatori
Il primo computer venne creato dall'università della Pennsylvania chiamato ENIAC (Electronic Numerical Integrator And Computer). Nel 1969 venne creato l'Apollo Guidance Computer che consisteva di 2800 circuiti integrati, il processore aveva una frequenza di 0.042 MHz, aveva 152 KByte tra ROM e RAM e aveva un'interfaccia DSKY (Display&Keyboard).

## Programmazione assembly
Il linguaggio Assembly è stato creato per andare a tradurre sequenze di bit in semplici istruzioni, per esempio `add A,B` viene l'assembler lo traduce in `00000000000010001000100001000000`.

L'elaborazione dei dati viene effettuta dal processore, diviso in due parti: parte operativa e parte di controllo. I dati vengono memorizzati nelle unità di memoria. I dispositivi di input e di outpurt permettono di scambiare informazioni con l'esterno.

## Basi di numerazione
Un numero in base n ha n cifre che partono da 0 a n-1.
Il byte è composto da 8 bit, con 28 valori, da 0 (=00000000) a 255 (=11111111).
Si utilizza la base 16 per la compattezza e la facilità di conversione:
Ex: (0011 1110 1000) base2 = 3E816 base16.
Conversione base 10 → k di n: si fa n/k=ris e si tiene conto del resto. Il risultato sarà l’unione di tutti i resti.
Conversione da base k → 10 di n: si moltiplicano i numeri la potenza della propria base.   Esempio: nella numerazione in base 10 si moltiplica ogni cifra per ogni potenza di 10: 501 = 5\*102 + 0\*101 + 1\*100  
In base 2 si fa la stessa cosa: 10110 = 1\*24 + 0\*23 + 1\*22 + 1\*21 + 0\*20  
Idem per la base 16: E24 = E\*162 + 2\*161 + 4\*160  
La **somma di numeri binari** si mettono i numeri in colonna e si sommano tenendo conto del resto. Esempio: 1 1 1 0 1 0 1 + 1 1 0 0 0 0 1 = 1 1 0 1 0 1 1 0  
Nella **sottrazione di numeri binari** eseguiamo il prestito al posto di utilizzare il resto.  Esempio 1 1 0 1 0 1 1 0 - 1 1 1 0 1 0 1 = 1 1 0 0 0 0 1  
Nulla moltiplicazione di numeri binari: quando devo moltiplicare un numero binario per 2 basta che faccio lo shift di una cifra verso sinistra.
Ex: 10012*2 = 100102
Quando devo fare la moltiplicazione tra un numero più grande di 2 basta che replico questa operazione per tutti i numeri del moltiplicando, quando ho un un 1 scrivo il numero, quindi nel numero 10001 scriverò il numero 1101 solamente la prima volta e la quinta volta.
![moltiplication with binary numbers](https://i.imgur.com/aWS70UB.png)

Nella codifica con modulo e segno ho il primo bit assegnato al segno, 0 per il segno positivo e 1 per il segno negativo.
Complemento a 1: 
Complemento a 2:

---
28/02/2019
Somma e sottrazione si applicano facilmente anche con 