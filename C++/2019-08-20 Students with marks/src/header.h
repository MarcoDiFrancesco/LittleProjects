#include <iostream>
using namespace std;
#define N_MARKS 25

struct sMarks {
  int mark[N_MARKS];
  int dim = N_MARKS;
};

void initMarks(sMarks *marks);
void printMarks(sMarks *marks);
int random(int min, int max);
void printFiltedMarks(sMarks *marks, int min, int max);
