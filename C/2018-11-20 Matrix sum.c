#include <stdio.h>
#include <stdlib.h>
#define row 3
#define col 3

int main(){
  int matrix1[row][col];
  int matrix2[row][col];
  int matrixSum[row][col];
  
  int j, w;
  for(w = 0; w<row; w++){
    for(j = 0; j<col; j++){
      matrix1[w][j]=rand()/5000;
      matrix2[w][j]=rand()/5000;
    }
  }

  // init matrix
  for(w = 0; w<row; w++){
    for(j = 0; j<col; j++){
      matrixSum[w][j] = 0;      
    }
  }

  // print matrix1 and sum
  for(w = 0; w<row; w++){
    for(j = 0; j<col; j++){
      printf("%d\t",matrix1[w][j]);
      matrixSum[w][j] += matrix1[w][j];
    }
    printf("\n");
  }
  printf("\n");
  
  // print matrix2 and sum
  for(w = 0; w<row; w++){
    for(j = 0; j<col; j++){
      printf("%d\t",matrix2[w][j]);
      matrixSum[w][j] += matrix2[w][j];
    }
    printf("\n");
  }
  printf("\n");

  // print matrixSum
  printf("Matrix sum\n");
  for(w = 0; w<row; w++){
    for(j = 0; j<col; j++){
      printf("%d\t",matrixSum[w][j]);
    }
    printf("\n");
  }
}