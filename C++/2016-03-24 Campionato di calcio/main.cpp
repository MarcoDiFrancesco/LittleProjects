
#include <iostream>
using namespace std;
struct Risultato {
  int gol1;
  int gol2;
};
const int NUMERO_SQUADRE = 5;
void stampaNomiSquadre(char squadre[NUMERO_SQUADRE][10]);
void generaRisultatiRandom(Risultato partite[NUMERO_SQUADRE][NUMERO_SQUADRE]);
void stampaRisultatiPartite(char squadre[NUMERO_SQUADRE][10], Risultato partite[NUMERO_SQUADRE][NUMERO_SQUADRE]);
void calcolaPunteggioFinale(Risultato partite[NUMERO_SQUADRE][NUMERO_SQUADRE], int punteggi[NUMERO_SQUADRE]); //non in ordine di classifica
void stampaPunteggi(char squadre[NUMERO_SQUADRE][10], int punteggi[NUMERO_SQUADRE]);
void stampaSquadraVincitrice(char squadre[NUMERO_SQUADRE][10], int punteggi[NUMERO_SQUADRE]);
//void stampaSquadraCheHaFattoPiùGol(char squadre[NUMERO_SQUADRE][10], Risultato partite[NUMERO_SQUADRE][NUMERO_SQUADRE]);
//void stampaSquadraCheHaSubitoPiùGol(char squadre[NUMERO_SQUADRE][10], Risultato partite[NUMERO_SQUADRE][NUMERO_SQUADRE]);

int main(int argc, char **argv) {
  //10 è la lunghezza massima del nome delle squadre
  char squadre[NUMERO_SQUADRE][10] = { "Squadra A", "Squadra B", "Squadra C", "Squadra D", "Squadra E" };
  Risultato partite[NUMERO_SQUADRE][NUMERO_SQUADRE];
  int punteggi[NUMERO_SQUADRE] = { 0 };
  cout << "Il campionato è formato dalle seguenti squadre: " << endl;
  stampaNomiSquadre(squadre);
  cout << endl << "Inizio campionato" << endl;
  generaRisultatiRandom(partite);
  stampaRisultatiPartite(squadre, partite);
  cout << "Fine campionato" << endl;
  calcolaPunteggioFinale(partite, punteggi);
  cout << endl << "I punteggi sono:" << endl;
  stampaPunteggi(squadre, punteggi);
  stampaSquadraVincitrice(squadre, punteggi);
//  stampaSquadraCheHaFattoPiùGol(squadre, partite);
//  stampaSquadraCheHaSubitoPiùGol(squadre, partite);
}



void stampaNomiSquadre(char squadre[NUMERO_SQUADRE][10])
{
    for(int i = 0; i < NUMERO_SQUADRE; i++)
    {
        cout << squadre[i] << endl;
    }
}
void generaRisultatiRandom(Risultato partite[NUMERO_SQUADRE][NUMERO_SQUADRE])
{
    srand((unsigned)time(NULL));
    for(int i = 0; i < NUMERO_SQUADRE; i++)
    {
        for(int j = 0; j < NUMERO_SQUADRE; j++)
        {
        // ogni squadra non si scontra con se stessa
            if (i != j)
            {
                partite[i][j].gol1 = rand() % 3;
                partite[i][j].gol2 = rand() % 3;
            }
        }
    }
}



/*
Vogliamo simulare un campionato di calcio.



Innanzitutto teniamo le squadre in un array di stringhe, cioè in una matrice di caratteri.
La matrice di caratteri ha 5 righe (una riga per squadra) e 10 colonne (ogni squadra può
avere un nome lungo al massimo 10 caratteri -o meglio 9 caratteri, più uno di terminazione).



Abbiamo poi una seconda matrice che tiene le informazioni dei risultati delle partite. Ogni
riga e ogni colonna corrispondono a una squadra (ad esempio, la riga 0 e la colonna 0 corrispondono
alla squadra 0, la riga 1 e la colonna 1 alla squadra 1 e così via) e in questo modo possiamo
salvare tutti i risultati delle partite tra ogni squadra, sia all'andata sia al ritorno. Ovviamente
la diagonale non conterrà alcun valore perché corrisponderebbe a una partita tra una squadra e se stessa.



La matrice è una matrice della struttura Risultato, dove Risultato corrisponde a una struttura
che contiene due interi, uno per i gol fatti dalla squadra in casa e uno per i gol fatti dalla
squadra fuori casa.



Infine abbiamo un array con i punteggi finali.



Vengono già fornite due funzioni per stampare il nome delle squadre e per caricare dei risultati
random. Bisogna invece implementare le funzioni per:



stampare i risultati delle partite (ad esempio, "Squadra 1 - Squadra 2: 2-0, Squadra 1 - Squadra 3: 0-0, etc")
calcolare i punteggi finali (cioè, partendo dalla matrice delle partite, bisogna riempire l'array dei punteggi)
stampare la squadra vincente (cioè stampare la squadra che ha più punti o dire se ci sono più squadre a pari merito)
stampare la squadra che ha fatto più gol (o dire se ci sono più squadre a pari merito)
stampare la squadra che ha subito più gol (o dire se ci sono più squadre a pari merito)


Un possibile output è il seguente:



Il campionato è formato dalle seguenti squadre:

Squadra A

Squadra B

Squadra C

Squadra D

Squadra E



Inizio campionato

Squadra A - Squadra B = 2:2

Squadra A - Squadra C = 2:2

Squadra A - Squadra D = 2:0

Squadra A - Squadra E = 2:2

Squadra B - Squadra A = 1:2

Squadra B - Squadra C = 1:2

Squadra B - Squadra D = 1:0

Squadra B - Squadra E = 0:0

Squadra C - Squadra A = 0:2

Squadra C - Squadra B = 1:0

Squadra C - Squadra D = 1:2

Squadra C - Squadra E = 1:1

Squadra D - Squadra A = 1:2

Squadra D - Squadra B = 1:2

Squadra D - Squadra C = 0:1

Squadra D - Squadra E = 2:1

Squadra E - Squadra A = 0:0

Squadra E - Squadra B = 0:0

Squadra E - Squadra C = 2:1

Squadra E - Squadra D = 1:1

Fine campionato



I punteggi sono:

Squadra A: 10

Squadra B: 9

Squadra C: 9

Squadra D: 8

Squadra E: 9



La squadra Squadra A ha vinto il campionato con 10 punti



La squadra Squadra B ha fatto più gol (12)



La squadra Squadra D ha subito più gol (9)
/////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;
struct Risultato {
  int gol1;
  int gol2;
};
const int NUMERO_SQUADRE = 5;
void stampaNomiSquadre(char squadre[NUMERO_SQUADRE][10]);
void generaRisultatiRandom(Risultato partite[NUMERO_SQUADRE][NUMERO_SQUADRE]);
void stampaRisultatiPartite(char squadre[NUMERO_SQUADRE][10], Risultato partite[NUMERO_SQUADRE][NUMERO_SQUADRE]);
void calcolaPunteggioFinale(Risultato partite[NUMERO_SQUADRE][NUMERO_SQUADRE], int punteggi[NUMERO_SQUADRE]);
non in ordine di classifica
void stampaPunteggi(char squadre[NUMERO_SQUADRE][10], int punteggi[NUMERO_SQUADRE]);
void stampaSquadraVincitrice(char squadre[NUMERO_SQUADRE][10], int punteggi[NUMERO_SQUADRE]);
void stampaSquadraCheHaFattoPiùGol(char squadre[NUMERO_SQUADRE][10], Risultato partite[NUMERO_SQUADRE][NUMERO_SQUADRE]);
void stampaSquadraCheHaSubitoPiùGol(char squadre[NUMERO_SQUADRE][10], Risultato partite[NUMERO_SQUADRE][NUMERO_SQUADRE]);
int main(int argc, char **argv) {
  //10 è la lunghezza massima del nome delle squadre
  char squadre[NUMERO_SQUADRE][10] = { "Squadra A", "Squadra B", "Squadra C", "Squadra D", "Squadra E" };
  Risultato partite[NUMERO_SQUADRE][NUMERO_SQUADRE];
  int punteggi[NUMERO_SQUADRE] = { 0 };
  cout << "Il campionato è formato dalle seguenti squadre: " << endl;
  stampaNomiSquadre(squadre);
  cout << endl << "Inizio campionato" << endl;
  generaRisultatiRandom(partite);
  stampaRisultatiPartite(squadre, partite);
  cout << "Fine campionato" << endl;
  calcolaPunteggioFinale(partite, punteggi);
  cout << endl << "I punteggi sono:" << endl;
  stampaPunteggi(squadre, punteggi);
  stampaSquadraVincitrice(squadre, punteggi);
  stampaSquadraCheHaFattoPiùGol(squadre, partite);
  stampaSquadraCheHaSubitoPiùGol(squadre, partite);
}
void stampaNomiSquadre(char squadre[NUMERO_SQUADRE][10]) {
  for(int i = 0; i < NUMERO_SQUADRE; i++) {
    cout << squadre[i] << endl;
  }
}
void generaRisultatiRandom(Risultato partite[NUMERO_SQUADRE][NUMERO_SQUADRE]) {
  srand((unsigned)time(NULL));
  for(int i = 0; i < NUMERO_SQUADRE; i++) {
    for(int j = 0; j < NUMERO_SQUADRE; j++) {
      // ogni squadra non si scontra con se stessa
      if (i != j) {
        partite[i][j].gol1 = rand() % 3;
        partite[i][j].gol2 = rand() % 3;
      }
    }
  }
}

*/
