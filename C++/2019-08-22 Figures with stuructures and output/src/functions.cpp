#include "structures.h"

void exportToFile(sFigure *figure)
{
  cout << endl;
  ofstream outputFile;
  outputFile.open("output.txt");
  for (int i = 0; i < figure->n; i++)
  {
    outputFile << figure->point[i].x << " ";
    outputFile << figure->point[i].y << "\n";
  }
  outputFile.close();
}

void importFromFile(sFigure *figure)
{
  ifstream inputFile("output.txt");
  if (inputFile.is_open())
  {
    int readInt;
    int xORy;
    int counter = 0;
    while (inputFile >> readInt)
    {
      if (xORy == 0)
      {
        xORy = 1;
        figure->point[counter].x = (float)readInt;
      }
      else
      {
        xORy = 0;
        figure->point[counter].y = (float)readInt;
      }
      counter++;
      cout << readInt << "-";
    }
    inputFile.close();
  }
}
