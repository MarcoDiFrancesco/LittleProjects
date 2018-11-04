#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct Tvettore{
  int v[N];
  unsigned int n_elem; // write unsigned during the exam
}Tvettore;

int casuale(int min, int max);
void init(int vett[], int dim);
void stampa(int vett[], int dim);

int main() {
  int vet1[N];
 // srand(time(0));
  init(vet1,N);
  stampa(vet1,N);

  Tvettore vet2;
  vet2.n_elem = 0;
  printf("\ndim= ");
  scanf("%d", &vet2.n_elem);

  init(vet2.v, vet2.n_elem);
  stampa(vet2.v, vet2.n_elem);
  stampa2(vet2);
}

void stampa(int vett[], int dim){
  int i;
  for(i = 0; i<dim; i++) {
    printf("%3d",vett[i]);
  }
}

void stampa2(Tvettore vett){
  int i;
  for(i = 0; i<vett.n_elem; i++) {
    printf("%3d",vett.v[i]);
  }
}

void init(int vett[], int dim){
  int i;
  for(i = 0; i<dim; i++) {
    vett[i] = casuale(-5,5);
  }
}

int casuale(int min, int max){
  return rand()%(min-max+1)+min;
}
