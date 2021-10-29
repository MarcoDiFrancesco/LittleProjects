#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_AUTO 100

// LAB 8 es 1

typedef struct {
  char nome[100];
  char cognome[100];
} Tacquirente;

typedef struct {
  char marca[10];
  int cilindrata;
  int annoDiImmatricolazione;
  Tacquirente acquirente;
} Tvettura;

typedef struct {
  int n_vetture;
  Tvettura vettura[MAX_AUTO];
} Tsalone;

int main(){
  Tsalone salone;
  int correct = 0;
  printf("Inset number of cars: ");
  scanf("%d",&salone.n_vetture);
  while(correct == 0) { // check number of cars
    if(salone.n_vetture <3 || salone.n_vetture > MAX_AUTO) {
      printf("Nuber of car not valid, try again: ");
      scanf("%d",&salone.n_vetture);
    } else {
      correct = 1;
    }
  }
  int w,k; // set random values function
  for(w=0; w<salone.n_vetture; w++) {
    salone.vettura[w].marca[0] = 'A' + (rand() % 26); // set uppercase letter
    for(k=1; k<5; k++) { // set lowercase letters
      salone.vettura[w].marca[k] = 'a' + (rand() % 26);
    }
    salone.vettura[w].cilindrata = 1000 + (rand() % 20)*100;
    salone.vettura[w].annoDiImmatricolazione = 2000 + (rand() % 10);
    salone.vettura[w].acquirente.nome[1] = 'A' + (rand() % 26);
    salone.vettura[w].acquirente.cognome[1] = 'A' + (rand() % 26);
  }

  // print function
  for(w=0; w<salone.n_vetture; w++) {
    if(salone.vettura[w].cilindrata > 1500) {
      printf("%s - ",salone.vettura[w].marca);
      printf("%d - ",salone.vettura[w].cilindrata);
      printf("%d - ",salone.vettura[w].annoDiImmatricolazione);
      printf("%c - ",salone.vettura[w].acquirente.nome[1]);
      printf("%c\n",salone.vettura[w].acquirente.cognome[1]);
    }
  }  

  // print max engine capacity
  int max = 0;
  char maxSurname;
  for(w=0; w<salone.n_vetture; w++) {
    if(salone.vettura[w].cilindrata > max) {
      max = salone.vettura[w].cilindrata;
      maxSurname = salone.vettura[w].acquirente.cognome[1];
    }
  }
  printf("Max -> %d - %c",max,maxSurname);

}
