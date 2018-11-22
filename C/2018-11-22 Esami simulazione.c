#include <stdio.h>
#include <stdlib.h>

int main(){
  int w,j,k;
  int nol = 8; // number of lines
  int count = 0;
  int countback = nol; // counting back from nol 
  for(w=0; w<nol; w++){
    for(j=0; j<nol; j++){
      if(w==0 || j==0 || w==(nol-1) || j==(nol-1)){
        printf("x");
      } else if(w==1 || j==1 || w==(nol-2) || j==(nol-2)){
        printf("o");
      } else {
        printf("#");
      }
    }
    printf("\n");
  }
}