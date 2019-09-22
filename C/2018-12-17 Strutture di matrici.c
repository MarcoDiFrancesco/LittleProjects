#include <stdio.h>
#include <stdlib.h>
#define NR 6 // should be 25
#define NC 5 // should be 10 

// Lab 8 es 2, non finito, è incomprensibile

typedef struct {
  char c;
  float val;
} Telemento;

typedef Telemento Tdato[NR][NC];

int main(){
  Tdato mat;
  int w, j;
  for(w=0; w<NR; w++) {
    for(j=0; j<NC; j++) {
      mat[w][j].c = '!';
    }
  }
  
  for(w=0; w<NR; w++) {
    for(j=0; j<NC; j++) {
      printf("%c - ",mat[w][j].c);
    }
    printf("\n");
  }
}