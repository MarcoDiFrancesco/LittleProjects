#include <iostream>
#include <cstdlib>
using namespace std;
#define NUM_STUDENTI 8
#define NUM_ESAMI 8

typedef struct studente {
  int matricola;
  int voti[NUM_ESAMI];
} studente;

int main(int argc, char const *argv[]) {
  studente studenti[NUM_STUDENTI];
  int stud,mark;

  for(stud=0;stud<NUM_STUDENTI;stud++) {
    for(mark=0;mark<NUM_ESAMI;mark++) {
      studenti[stud].voti[mark] = mark;
      printf("%d  ",studenti[stud].voti[mark]);
    }
    studenti[stud].matricola = stud;
    printf("-%d-\n",studenti[stud].matricola);
  }
}
