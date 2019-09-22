#include <stdio.h>
#include <stdlib.h>
#define nr 10
#define nc 10

void init(int m[nr][nc], int dimR, int dimC);
void stampa(int m[nr][nc], int dimR, int dimC);

int main(){
  int a[nr][nc], b[nr][nc];
  init(a,5,5);
  init(b,5,5);
  stampa(a,5,5);
  printf("\n");
  stampa(b,5,5);
}

void init(int m[nr][nc], int dimR, int dimC){
  int w1,w2;
  for(w1 = 0; w1 < dimR; w1++){
    for(w2 = 0; w2 < dimC; w2++){
      m[w1][w2] = w1*w2;
    }
  }
}

void stampa(int m[nr][nc], int dimR, int dimC){
  int w1,w2;
  for(w1 = 0; w1 < dimR; w1++){
    for(w2 = 0; w2 < dimC; w2++){
      printf("%d\t", m[w1][w2]);
    }
    printf("\n");
  }
}
