#include <stdio.h>
#include <stdlib.h>
#define studentsNumber 4
#define examsNumber 3
typedef char String[20];

/*
Matrix of marks with stuctures
Orizontal = students
Vertical = exams
*/
typedef struct Tstudent {
  String name;
  String surname;
  int mark[examsNumber];
} Tstudent;

int main(){
  Tstudent student[studentsNumber];
  student[0].mark[0] = 0;
  int w,j;
  String name1 = "nome"; ///
  for(w=0; w<studentsNumber; w++) {
    for(j=0; j<examsNumber; j++) {
      student[w].mark[j] = rand()/5000;
      student[w].name[0] = rand()%('Z'-'A'+1)+'A';
      student[w].name[1] = rand()%('z'-'a'+1)+'a';
      student[w].name[2] = '\0';
      
      student[w].surname[0] = rand()%('Z'-'A'+1)+'A';
      student[w].surname[1] = rand()%('z'-'a'+1)+'a';
      student[w].surname[2] = '\0';
    }
  }

  // print matrix of marks
  for(w=0; w<studentsNumber; w++){
    printf("%s %s\t",student[w].name,student[w].surname);
    for(j=0; j<examsNumber; j++){
      printf("%d\t",student[w].mark[j]);
    }
    printf("\n");
  }  

  // average by student
  int studentAnalyzed;
  printf("Student you want to analyze: ");
  scanf("%d",&studentAnalyzed);
  int studentAverage = 0;
  for(w=0; w<examsNumber; w++) {
    studentAverage += student[studentAnalyzed].mark[w];
  }
  studentAverage /= examsNumber;
  printf("Average by student: %d\n",studentAverage);

  // average by mark
  int markAnalyzed;
  printf("Number of the exam you want to analyze: ");
  scanf("%d",&markAnalyzed);
  int markAverage = 0;
  for(w=0; w<studentsNumber; w++) {
    markAverage += student[w].mark[markAnalyzed];
  }
  markAverage /= studentsNumber;
  printf("Average by mark: %d",markAverage);
}