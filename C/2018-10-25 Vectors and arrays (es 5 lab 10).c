#include <stdio.h>
#include <stdlib.h>

deftype struct{
  float x,y;
  char nome[max];
}Tpunto;

Tpunto init_punto(float x, float y);
void stampa_punto(Tpunto p);
int casuale(int min, int max);
void str_casuale(char s[max], int len);
void init(Tpunto vett[], int dim);

int main(){
  int x, y;

  Tpunto p;
  p = init_punto(casuale(-5,5),casuale(-5,5));
  stampa_punto(Tpunto p);
}

Tpunto init_punto(float x,float y){
  Tpunto ris;
  ris.x = x;
  ris.y = y;
  return ris;
}

void stampa_punto(Tpunto p) {
  printf("[%f,%f]",p.x,p.y);
}

int casuale(int min, int max){
  return rand()%(min-max+1)+min;
}
