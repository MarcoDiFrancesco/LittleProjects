#include <stdio.h>
#include <stdlib.h>
#define max 8
int main(){
  int matrix[max][max];
  int j, w, sum = 0;
  for(w = 0; w<max; w++){
    for(j = 0; j<max; j++){
      matrix[w][j]=rand()/1000;
    }
  }

  // print matrix
  for(w = 0; w<max; w++){
    for(j = 0; j<max; j++){
      printf("%d\t",matrix[w][j]);
      sum += matrix[w][j];
    }
    printf("\n");
  }
  int average = sum/(max*max);
  printf("average: %d\n",average);
  
  // print position of the cell with a value over the average
  for(w = 0; w<max; w++){ 
    for(j = 0; j<max; j++){
      if(matrix[w][j] > average){
        printf("[%d]",w);
        printf("[%d]\t",j);
      }
    }
    printf("\n");
  }
  
}