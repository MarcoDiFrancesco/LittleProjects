#include <stdlib.h>
#include <stdio.h>
#define N_GIOCATORI 10
#define N_PARTITE 10
#define STR_LENGTH 10

// Lab 8 es 5

typedef struct Data {
  int anno;
  int mese;
  int giorno;
} Data;

typedef struct Tgiocatore {
  char nome[STR_LENGTH];
  char conome[STR_LENGTH];
  int playerNumber;
} Tgiocatore;

typedef struct Tsquadra {
  char nomeSquadra[STR_LENGTH];
  Tgiocatore giocatore[N_GIOCATORI];
} Tsquadra;

typedef struct Tpartita {
  Tsquadra squadra[2]; // squadra A ([0]) and B ([1])
  int date;
  Data data; // numero della giornata della partita
  int girone; // 0 andata, 1 ritorno
  int goalTeamA;
  int goalTeamB;
} Tpartita;

typedef struct Tcampionato {
  Tpartita partita[N_PARTITE];
  char serie; // A, B, C...
} Tcampionato;

int main() {
  Tcampionato campionato1;
  Tcampionato campionato2;
  
  campionato1.serie = 'A';
  campionato2.serie = 'B';
  printf("%c - ",campionato1.serie);
  printf("%c - ",campionato2.serie);

  campionato1.partita[0].data.anno = 1998;
  printf("%d - ",campionato1.partita[0].data.anno);
}
