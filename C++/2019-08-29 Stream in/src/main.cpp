#include <iostream>
#include <stdlib.h>
#include <fstream>
#define FILE_SIZE 3
using namespace std;

int main()
{
  ifstream inFile;
  inFile.open("text.txt");
  string nome[FILE_SIZE];
  int eta[FILE_SIZE];
  int maxEta = 0, maxEtaIndice = 0;
  int minEta = 100, minEtaIndice = 0;
  for (int i = 0; i < FILE_SIZE; i++)
  {
    inFile >> nome[i];
    inFile >> eta[i];
    if (eta[i] > maxEta)
    {
      maxEta = eta[i];
      maxEtaIndice = i;
    }
    if (eta[i] < minEta)
    {
      minEta = eta[i];
      minEtaIndice = i;
    }
  }
  cout << "Min eta: " << nome[minEtaIndice] << endl;
  cout << "Max eta: " << nome[maxEtaIndice] << endl;
}