#include <stdio.h>
#include <stdlib.h>

int main(){
  int counter = 0;
  int c=0; // init character
  while((c=getchar()) != 'q'){
    if(c == ' ' || c == '\t' || c == '\n'){
      counter++;
    }
  }
  printf("%d",counter);
}