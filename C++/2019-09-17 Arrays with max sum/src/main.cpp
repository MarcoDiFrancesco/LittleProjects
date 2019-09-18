#include "main.h"

/*
Input: un vettore di interi A[1 . . . n]
Output: il sottovettore A[i . . . j] di somma massimale, ovvero
il sottovettore la cui somma degli elementi sommatoria j, k=i A[k] è più
grande o uguale alla somma degli elementi di qualunque altro sottovettore.
*/
int main()
{
  int a[SIZE];
  randomArray(a);
  printArray(a);

  auto t1 = std::chrono::high_resolution_clock::now();

//  efficency1(a);
  efficency2(a);

  auto t2 = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
  cout << duration;
}

void randomArray(int *_a)
{
  for (int i = 0; i < SIZE; i++)
  {
    _a[i] = rand() % (10 - (-10) + 1) - 10;
  }
}

void printArray(int *_a)
{
  for (int i = 0; i < SIZE; i++)
  {
    cout << i << "=[" << _a[i] << "]\t";
  }
  cout << endl;
}
