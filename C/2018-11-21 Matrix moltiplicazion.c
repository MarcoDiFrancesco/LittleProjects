#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  int size1 = 2; // size of cols matrix1 and rows matrix2 
  int size2 = 3; // size of rows matrix1 and cols matrix2 

  // select minimum number btw rows and cols
  int min; // smaller number btw rows and cols
  int max; // bigger number btw rows and cols
  if(size1<=size2){
    min = size1;
    max = size2;
  } else {
    min = size2;
    max = size1;
  }

  int matrixFinal[min][min];
  int matrix1[size1][size2];
  int matrix2[size2][size1];

  int w, j, k, y;
  // put random numbers into matrix1
  for(w=0; w<size1; w++){
    for(j=0; j<size2; j++){
      matrix1[w][j] = rand()/5000;
    }
  }

  // put random numbers into matrix2
  for(w=0; w<size2; w++){
    for(j=0; j<size1; j++){
      matrix2[w][j] = rand()/5000;
    }
  }

  // initialize matrixFinal
  for(w=0; w<min; w++){
    for(j=0; j<min; j++){
      matrixFinal[w][j] = 0;
    }
  }

  // calculate moltiplication matrix
  for(w=0; w<min; w++){
    for(j=0; j<min; j++){
      for(k=0; k<max; k++){
        matrixFinal[w][j] += matrix1[w][k]*matrix2[k][j];
      }
    }
  }

  // print matrix1
  printf("Matrix1\n");
  for(w=0; w<size1; w++){
    for(j=0; j<size2; j++){
      printf("%d\t",matrix1[w][j]);
    }
    printf("\n");
  }

  // print matrix2
  printf("\nMatrix2\n");
  for(w=0; w<size2; w++){
    for(j=0; j<size1; j++){
      printf("%d\t",matrix2[w][j]);
    }
    printf("\n");
  }

  // print matrixFinal
  printf("\nMatrixFinal\n");
  for(w=0; w<min; w++){
    for(j=0; j<min; j++){
      printf("%d\t",matrixFinal[w][j]);
    }
    printf("\n");
  }
}
