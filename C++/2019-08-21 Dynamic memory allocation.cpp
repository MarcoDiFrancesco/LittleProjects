#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
  // Allocate memory using
  int *p;
  p = (int *)malloc(sizeof(int));

  if (!p)
  {
    cout << "Not assigned" << endl;
  }
  else
  {
    cout << "Assigned" << endl;
  }
  // Free up memory
  free(p);

  // Allocate memory with new
  int *pointer1 = new int;      // Allocate memory for 1 int
  int *pointer2 = new int[100]; // Allocate memory for 100 int and pointer to the first one
  // If pointer is already defined
  int *pointer3;
  pointer3 = new int[10];
  // Free up memory allocated to the ponter but does not delete the pointer (it can be reused)
  delete pointer1;   // delete single variable
  delete[] pointer2; // delete array
  delete[] pointer3;
}
