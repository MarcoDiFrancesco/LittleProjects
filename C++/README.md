# Programmazione 1

Un **algoritmo** è una sequenza precisa di operazione comprensibili ad un esecutore che definisce una sequenza finita di passi che comportano alla realizzazione di un task (compito). Un algorito codificato viene chiamato programma. Le proprietà fondamentali di un algortimo sono correttezza ed efficienza.

Organizzazione software di un calcolatore:

- Software applicativo: software di produttività individuale (fogli elettronici, mail reader)
- Software di sistema: ambienti di programmazione (compilatore, debugger)
- Sistema operativo (Windows, Linux)
- Hardware

Macchina di Von Neumann (architettura hardware):

- CPU: carica istruzioni da far eseguire dalla memoria centra, interpreta le istruzioni, esegue le istruzioni e il trasferimento di informazioni. Il lavoro della CPU è scandito da clock e la frequenza del clock si misura in Hertz (1 Hz = 1 ciclo/s).
- Bus di sistema: eseguono i trasferimenti di dati attraverso il bus di sistema.
- Orologio di sistema (clock): permette di sincronizzare in modo sincrono le fasi di elaborazione.

## Rappresenzazioni delle informazioni

La rappresentazione di caratteri avviene riservando un byte (8 bit) per ogni carattere e controllando su una tabella (extended ASCII) la corrispondenza del carattere.

| Nome     | Sigla | Valore | Approssimazione |
| -------- | ----- | ------ | --------------- |
| Kilobyte | KB    | 2^10   | 10^3 byte       |
| Megabyte | MB    | 2^20   | 10^6 byte       |
| Gigabyte | GB    | 2^30   | 10^9 byte       |
| Terabyte | TB    | 2^40   | 10^12 byte      |

**RAM** (Random Access Memory) è una memoria il cui tempo di accesso è indipendente dall'indirizzo della parola alla quale si vuole accedere. Si tratta di una memoria volatrile, cioè il contenuto viene perso quando cessa l'alimentazione del sistema.
**DRAM** (Dynam RAM) conosciuta anche come RAM, il contenuto deve essere rinfresacato periodicamente, questo però semplifica la realizzazione della cella di memoria consentendo maggiori densità rispetto dalle **SRAM** (Static RAM).
**ROM** (Read-only memory) hanno accesso molto veloce, sono memorie permanenti, e vengono utilizzate per imagazzinare dati e preogrammi utilizzati al momento dell'accensione dell'elaboratore, prima del caricamento dell'S.O.

**Gerarchia di memoria** è divisa in:

- **Registri** utilizzati per contenere dati temporanei per le operazioni per le operazioni della CPU. 1 registro = 8 byte = 64 bit
- **Memoria cache (SRAM)** contiene dati acceduti frequentemente.
- **Memoria principale (DRAM)** meno veloce della cache ma contiene più dati.
- **Memoria di massa** molto più lenta e contiene molto più dati.

**Tipologia di istruzioni** eseguite dal processore sono suddivise in: istruzioni aritmetiche in cui avvengono somme, sottrazioni, shift ecc.; istruzioni di controllo in cui avvengono chiamate a sottoprogrammi ecc.; istruzioni di trasferimento dei dati da un registro all'altro o da uno dei registri alla memoria (o viceversa). Esempi di assegnazione sono `c←a+b` in cui: si leggono i valori di a,b; si sommano; si scrivono i risultati in c.

Nella **gestione delle periferiche** la sincronizzazione tra processore e periferiche viene con due approcci:

- a **polling** (controllo di programma) in cui il processore continua a verificare se il dato è arrivato dalla periferica, oppure mediante interrupt in cui il processore viene notificato dall'arrivo del dato, la notifica interrompe ciò che il processore stava facendo.

---

# Switch vs If-Else

L'istruzione switch ha delle differenze dall'if-else, infatti può essere usata solo in alcuni casi dove:

- Viene valutata solamente una variabile, tutte le scelte dipenderanno, infatti, da questa variabile. La variabile deve essere un tipo integral ( int ma anche altri tipi che vedremo )
- Ogni singolo valore della variabile può controllare solo una scelta. Una scelta finale, chiamata default “cattura” tutti i valori dei casi non specificati

Continue

- continue all’interno di while, for, do salta le istruzioni rimanenti nel corpo di quell’istruzione di controllo e fa eseguire la successiva iterazione del ciclo.
- continue non si applica a switch

Array
Note Terminologiche e Semantiche

- Array in C non è un tipo ma un costruttore di tipo.
- “variabile X è di tipo array” è tecnicamente errato in C
- Una volta dichiarato, non è possibile variare la dimensione di un array

## Operazioni tra basi

Tipi di basi:

- binaria (0 e 1)
- ottale (da 0 a 7)
- decimale
- esadecimale (da 0 a F)

Typedef: Creazione di un alias di tipo (iniziale maiuscola)
Sintassi: typedef tipo NomeNuovoTipo;

Esempio:
typedef int Lunghezza;
typedef char Stringa[30];

Tipi di dati
I tipi di dato che il calcolatore può manipolare direttamente (detti tipi di dato elementari) sono pochi e semplici:
valori di verità (o booleani), del tipo vero/falso
numeri interi (positivi o negativi)
numeri frazionari
caratteri

In un calcolatore i dati si trovano nella memoria, mentre la rappresentazione dei dati è nota all’hw o al sw che li interpreta.

Alcune esempi di rappresentazioni a livello sw sono:

- un numero complesso
- un testo scritto
- un lista di nomi
- un video
- un suono
- un disegno

### Codifica a complemento

Esempio di codifica di complemento a 2.
Con N bit si codificano valori da 2N-1+2N-1-1
Il bit più significativo rappresenta il segno: se è 0 è positivo, se è 1 è negativo.

Codifica a virgola fissa: viene stabilita una posizione fissa destinata alla parte intera e una posizione fissa destinata alla parte frazionaria.

Codifica a virgola mobile:
La maggior parte dei bit vengono utilizzati per rappresentare le cifre significative del numero e alcuni bit vengono destinati per la rappresentazione della posizione della virgola.
La rappresentazione dei numeri frazionari in virgola mobile in 32 bit (4 byte) utilizzano:
primo bit (MSB) codifica del segno
successivi 8 per l’esponente e
23 per la mantissa m

Tipi:
Carattere char viene rappresentato solitamente da un byte.
Sono ordinati in modo che possano essere eseguite le operazioni tra come < e >

`\n` new line
`\b` backspace (cancella un carattere)
`\t` tab
`\r` carriage return (cancella tutto ciò che segue questo carattere fino alla nuova riga)

`long int` 32 bit
`short int` 16 bit
`int` 16 - 32 bit

signed int MSB usato per il segno
unsigned int usato per valori interi senza segno

float 4 byte, 6 cifre di precisione
double 8 byte, 15 cifre di precisione
long double 8 byte, uguale o più grande di double

Tipi integral: char, int
Tipi floating: float, double, long double

## Conversione

Il parsing in c porta a una perdita di dati
int a=2;
float b=10.4;
a=b;
printf("%d",a);
Questo programma fa risultare 10 al posto di 10.6

Conversione implicita: ogni variabile di tipo char o short (incluse le rispettive versioni signed o unsigned) viene convertita in variabile di tipo int
Se dopo l’esecuzione del passo 1 l’espressione risulta ancora eterogenea rispetto al tipo degli operandi coinvolti, rispetto alla gerarchia:
int < long < unsigned < unsigned long < float < double < long double

Codice che non funziona:
float average;
int num1=5, num2=2;
average=(num1+num2)/2;

Codice corretto:
float average;
int num1=5, num2=2;
average=(float)(num1+num2)/2;

## User-Defined types

struct strutture che raggruppano insiemi di variabili di tipo diverso
bit-field variazione delle strutture che permette di accedere ai singoli bit di una particolare memoria
union permette di definire la stessa porzione di memoria con tipi diversi
enumeration definisce una vista di simboli
typedef definizione di nuovi nomi per tipi esistenti

`struct`
Dichiarazione delle variabili può essere effettuata direttamente sotto la struttura o in una riga a parte:

Ogni variabile si chiama campo (field)

Possono essere create anche strutture di strutture:

`typedef`
Vanno a creare dei tipi di variabili:
`typedef double PioggeMensili[12];`

Possono essere creati strutture di typedef:

```C++
typedef struct {
int giorno;
int mese;
int anno;
} Data;
Data D1, D2;
if(D1.anno < D2.anno) {
  printf(“data D1< data D2”);
}
```

`enum`
Crea un nuovo tipo che può contenere solo un numero finito e predeterminato di valori.
enum giorno {lun, mar, mer, gio, ven, sab, dom};
enum giorno birth;
`if(birth == mar)`
Questi dati sono rappresentati come interi, di conseguenza possono essere eseguite gli operatori di confronto.
Può essere utilizzata come una struttura:
`typedef enum {lun, mar, mer, gio, ven, sab, dom} GiornoSettimana;`
`GiornoSettimana giorno;`

Si possono incrementare le variabili senza dichiarare l’incremento.
`enum months {Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};`
In questo caso , avendo inizializzato ad 1 il primo elemento ( Jan), gli altri valori sono calcolati a seguire incrementati di uno. Quindi Feb=2, Mar=3,..

## Puntatori

Dichiarazione di un puntatore: `TipoDato *Puntatore`.
TipoDato definisce quale tipo di variabile può essere referenziata
Puntatore è identificatore della variabile puntatore
“\*” Operatore unario di de-referenziazione (dereference).

# Algoritmi di ordinamento (sort)

## Insertion Sort

- Utile per archivi di piccole dimensioni
- Caso medio: `Θ(N^2)`
- Caso peggiore: `Θ(N^2)`

## Merge sort

- Caso medio `O(N*logN)`
- Caso peggiore `O(N*logN)`

I metodi basati su **confronti e scambio** sul posto ordinano una sequenza di N numeri in `O(N^2)`.  
Si può dimostrare che tutti i metodi di **ordinamento per confronti** hanno un comportamento ottimale `O(N*logN)`.

# Alberi binari di ricerca

Un **albero binario di ricerca** è un albero binario in cui il valore di ogni nodo è maggiore o uguale dei valori dei nodi del suo sottoalbero sinistro e minore o uguale dei valori dei nodi del suo sottoalbero destro.  
**Altezza di un albero**: lunghezza massima tra radice (nodo senza padre) e foglia di un albero.

![Altezza alberi](https://i.imgur.com/H8V8ukx.png)

Stampa simmetrica (o in ordine): si parte analizzando da sinistra le foglie, poi i nodi e poi sinistra.  
Stampa in preordine: si stampano prima i nodi in cui si passa, si va a sinistra poi a destra.
Stampa in post ordine: si stampa prima a sinistra, poi a destra, poi in nodo.

```c++
struct treeB
{
  char key;
  struct treeB *p;     //Link Padre
  struct treeB *left;  //Link albero Sinistro
  struct treeB *right; //Link albero Destro
};
void PrintInOrdine(TreeBPtr ptr)
{
  if (ptr != NULL)
  {
    PrintInOrdine(ptr->left);
    printf("%c ", ptr->key);
    PrintInOrdine(ptr->right);
  }
}

void PrintPreOrdine(TreeBPtr ptr)
{
  if (ptr != NULL)
  {
    printf("%c ", ptr->key);
    PrintPreOrdine(ptr->left);
    PrintPreOrdine(ptr->right);
  }
}

void PrintPostOrdine(TreeBPtr ptr)
{
  if (ptr != NULL)
  {
    PrintPostOrdine(ptr->left);
    PrintPostOrdine(ptr->right);
    printf("%c ", ptr->key);
  }
}

void InsertNode(TreeBPtr *root, char info)
{
  if (*root == NULL)
  { //Albero vuoto
    *root = (TreeBPtr)malloc(sizeof(TreeB));
    if (!(*root))
    {
      printf("Memoria non allocata - InsertNode\n");
      exit(0);
    }
    (*root)->left = NULL;
    (*root)->right = NULL;
    (*root)->p = NULL;
    (*root)->key = info;
  }
  else
    InsertNodeRic(root, info);
}

void InsertNodeRic(TreeBPtr *ptr, char info)
{

  /*Procede alla ricerca nei sottoalberi */

  if (info < (*ptr)->key)
  {
    printf("Attach to left child call\n");
    fflush(stdout);
    if ((*ptr)->left == NULL)
    {
      TreeBPtr punt = (TreeBPtr)malloc(sizeof(TreeB));
      if (!punt)
      {
        printf("Memoria non allocata - InsertNode\n");
        exit(0);
      }
      else
      {
        punt->key = info;
        punt->left = NULL;
        punt->right = NULL;
        (*ptr)->left = punt; //Aggancia sottoalbero sinistro
        punt->p = *ptr;      //Aggancia Padre-Figlio
      }
    }
    else
      InsertNodeRic(&((*ptr)->left), info);
  }
  else if (info > (*ptr)->key)
  {
    printf("Attach to right child call\n");
    fflush(stdout);
    if ((*ptr)->right == NULL)
    {
      TreeBPtr punt = (TreeBPtr)malloc(sizeof(TreeB));
      if (!punt)
      {
        printf("Memoria non allocata - InsertNode\n");
        exit(0);
      }
      else
      {
        punt->key = info;
        punt->left = NULL;
        punt->right = NULL;
        (*ptr)->right = punt; //Aggancia sottoalbero destro
        punt->p = *ptr;       //Aggancia Padre-Figlio
      }
    }
    else
      InsertNodeRic(&((*ptr)->right), info);
  }
  else
    printf("Duplicato non inserito\n");
}

```
## B-tree
Altri tipi di alberi sono i `B-tree`, una tipologia di alberi utilizzata per memorizzare grandi quantità di dati. 
![B-tree](https://i.imgur.com/TtQFp5T.png)

## ABR vs B-tree
Ricerca di una chiave
- La ricerca di un nodo in un albero binario di ricerca bilanciato richiede log2 (n) confronti.
- In contrasto per un B-tree la ricerca richiede il passo di ricerca del nodo all’interno del quale svolgeremo una ricerca tra le chiavi.
- Si puo’ dimostrare che i livelli del B-tree sono dati da log m (n) (m il numero di chiavi per nodo ) e quindi la ricerca di una chiave all’interno del B-tree richiede:
log 2 (m) * log m (n)=log 2 (n)

# Hashing
