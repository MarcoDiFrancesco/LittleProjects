#include "header.h"

void initMarks(sMarks *marks){
  for(int i = 0; i < marks->dim; i++) {
    marks->mark[i] = random(18,30);
  }
}

void printMarks(sMarks *marks) {
  for(int i = 0; i < marks->dim; i++) {
    cout << marks->mark[i] << " ";
  }
  cout << endl;
}

int random(int min, int max) {
  return rand()%(max-min+1)+min;
}

void printFiltedMarks(sMarks *marks, int min, int max) {
  for(int i = 0; i < marks->dim; i++) {
    if(marks->mark[i] >= min && marks->mark[i] <= max) {
      cout << marks->mark[i] << " ";
    }
  }
  cout << endl;
}

