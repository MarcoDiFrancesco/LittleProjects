#include <stdlib.h>
#include <stdio.h>
#define N_GIOCATORI 10
#define STRING_LENGTH 10

typedef struct {
  char nome[STRING_LENGTH];
  char conome[STRING_LENGTH];
  int playerNumber;
} Tgiocatore;

typedef struct {
  char nomeSquadra[N_GIOCATORI];
  Tgiocatore giocatore[N_GIOCATORI];
} Tsquadra;

typedef struct {
  Tsquadra[2];
  int date;
  int dayNumber; // numero della giornata della partita
  int girone; // 0 andata, 1 ritorno
  Result result;
} Tpartita;

typedef struct {
  Tpartita partite;
  char serie; // A, B, C...
} Tcampionato;

typedef struct {
  int winner; // 0 tie, 1 first team, 2 second
  int numberOfGoal;
} Result;

int main() {

}
