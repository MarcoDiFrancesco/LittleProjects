#include <stdlib.h>
#include <iostream>
using namespace std;

struct myStruct
{
  int dato = 0;
  char *c;
};

int random(int, int);
void print(int *);
void putRandomValues(int *);
void printStruct(myStruct *);

int main()
{
  // C version
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

  // C++ version
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

  cout << (int)sizeof(myStruct) << endl;
  cout << (int)sizeof(myStruct *) << endl;

  int *dynamicInt = new int[10];
  int staticInt[10];

  putRandomValues(dynamicInt);
  putRandomValues(staticInt);
  print(dynamicInt);
  print(staticInt);

  delete dynamicInt;

  myStruct staticArrayStuct[10];
  cout << sizeof(staticArrayStuct) << endl;

  myStruct *dynamicArrayStruct = new myStruct[10];
  printStruct(dynamicArrayStruct);
  cout << sizeof(dynamicArrayStruct);
  delete[] dynamicArrayStruct; 
}

int random(int min, int max)
{
  return rand() % (max - min + 1) + min;
}

void print(int *array)
{
  for (int i = 0; i < 10; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;
}

void printStruct(myStruct *array)
{
  for (int i = 0; i < 10; i++)
  {
    cout << array[i].dato << " ";
  }
  cout << endl;
}

void putRandomValues(int *array)
{
  for (int i = 0; i < 10; i++)
  {
    array[i] = random(0, 9);
  }
  cout << endl;
}