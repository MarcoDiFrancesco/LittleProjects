#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
  int **matrix = new int *[10];
  for (int i = 0; i < 10; i++)
  {
    matrix[i] = new int[5];
  }
  
  // put values and print matrix
  int counter = 0;
  for (int i = 0; i < 10; i++)
  {
    for (int w = 0; w < 5; w++)
    {
      matrix[i][w] = counter++;
      cout << matrix[i][w] << "\t";
    }
    cout << endl;
  }
  
  // delete matrix
  for (int i = 0; i < 10; i++)
  {
    delete []matrix[i];
  }
  // delete []matrix; // somehow doesn't work
  
  // put values and print matrix
  counter = 0;
  for (int i = 0; i < 10; i++)
  {
    for (int w = 0; w < 5; w++)
    {
      matrix[i][w] = counter++;
      cout << matrix[i][w] << "\t";
    }
    cout << endl;
  }
}