#include "structures.h"

void exportToFile(sFigure *figure);

int main() {
  sFigure figure = sFigure(5);
  
  cout << figure.point[0].distFromZero() << endl;
  cout << figure.point[1].distFromPoint(2,2) << endl;
  figure.point[2].print();
  figure.point[3] = sPoint(3,3);
  figure.point[3].print();
  figure.print();
  figure.furthestPoint();
  exportToFile(&figure);
}
Strutture Dati
Liste (Codice , 