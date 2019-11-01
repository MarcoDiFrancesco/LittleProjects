#include <fstream>
#include <iostream>
#define N 1000000
using namespace std;

void printArray(int *, int);

int main()
{
  int a[N];
  ifstream in;
  in.open("input.txt");
  int rowNumber;
  in >> rowNumber;
  for (int i = 0; i < rowNumber; i++)
  {
    in >> a[i];
  }
  int sum = 0, sumMax = 0;
  for (int i = 0; i < rowNumber; i++)
  {
    sum += a[i];
    if (sum > sumMax)
    {
      sumMax = sum;
    } else if(sum < 0) {
      sum = 0;
    }
  }

  cout << sumMax << "\n";

  ofstream out;
  out.open("output.txt");
  out << sumMax;
  printArray(a, rowNumber);
}

void printArray(int *a, int rowNumber)
{
  for (int i = 0; i < rowNumber; i++)
  {
    cout << a[i] << "\t";
  }
}