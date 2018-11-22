#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define numStudenti 5
#define numEsami 4

int main(){
  int tabellaVoti[numStudenti][numEsami];
  int w,j;
  for(w=0; w<numStudenti; w++){
    for(j=0; j<numEsami; j++){
      tabellaVoti[w][j]=rand()/5000;
    }
  }

  for(w=0; w<numStudenti; w++){
    for(j=0; j<numEsami; j++){
      printf("%d\t",tabellaVoti[w][j]);
    }
    printf("\n");
  }  

  // average of a single student
  int studentAverage = 0;
  int studentAnalyzed;

  printf("Which student you want to know the average? ");
  scanf("%d",&studentAnalyzed);
  for(w=0;w<numEsami;w++){
    studentAverage += tabellaVoti[studentAnalyzed][w];
  }
  studentAverage = studentAverage/numEsami;
  printf("\nAverage: %d\n",studentAverage);

  // average of all the students
  int studentsAverage = 0;
  for(w=0; w<numStudenti; w++){
    for(j=0; j<numEsami; j++){
      studentsAverage += tabellaVoti[w][j];
    }
  }
  studentsAverage = studentsAverage / (numStudenti*numEsami);
  printf("Average of all the students: %d\n", studentsAverage);
}