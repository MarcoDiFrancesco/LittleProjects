#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define numStudenti 100

typedef struct Studente {
  int matricola;
  int voto[];
} Studente;

int main() {
  Studente studenti[numStudenti];

  studenti[0].matricola = 200;
  studenti[1].matricola = 300;
  studenti[2].matricola = 400;
  // why does this make error?
  studenti[0].voto[5]={4};
  studenti[1].voto[5];
  studenti[2].voto[5];
  
  printf("%d-",studenti[0].matricola);
}