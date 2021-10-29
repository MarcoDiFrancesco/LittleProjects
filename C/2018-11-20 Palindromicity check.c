#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int nchar = strlen(stringCheck); // number of characters in the string
  int w; // for the for
  int fc=0, bc=nchar-1; // forward counter and backword counter
  int diffCounter=0;

  // ask for the string
  char stringCheck[20];
  scanf("%s",stringCheck);

  for(w=0; w<(nchar/2); w++){
    printf("%d - ",fc); // number of the character checked
    printf("%d - ",bc);
    if(stringCheck[fc] == stringCheck[bc]){
      printf("same\n");
    } else {
      printf("different\n");
      diffCounter++;
    }
    fc++;
    bc--;
  }
  if(diffCounter>0){
    printf("Not palindrom");
  } else {
    printf("Palindrom");
  }
  
}