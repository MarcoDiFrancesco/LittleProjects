#include "header.h"

int main() {
  sMarks marks;
  initMarks(&marks);
  printMarks(&marks);
  printFiltedMarks(&marks, 18, 22);
}