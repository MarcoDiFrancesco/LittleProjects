#include "structures.h"

void exportToFile(sFigure *figure)
{
  cout << endl;
  ofstream outputFile;
  outputFile.open("output.txt");
  for(int i = 0; i < MAX_POINTS; i++){
    outputFile << figure->point[i].x << " ";
    outputFile << figure->point[i].y << "\n";
  }
}
