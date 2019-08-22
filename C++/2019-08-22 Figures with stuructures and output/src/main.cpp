#include "structures.h"

void exportToFile(sFigure *);
void importFromFile(sFigure *);

int main()
{
  sFigure figure = sFigure(5);
  figure.print();
  figure.furthestPoint();
  exportToFile(&figure);

  sFigure importedFigure = sFigure(5);
  importFromFile(&importedFigure);
  // import from file is a little bit bugged but works
  importedFigure.print();
}
