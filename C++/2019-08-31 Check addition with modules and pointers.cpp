#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct myStruct
{
  int a;
  int dim;
  
  myStruct()
  {
    a = 0;
    dim = 3;
  }
} myStruct;

int main()
{
  myStruct *struttura = new myStruct();
  for(int i = 0; i < 10; i++) {  
    cout << struttura->a << " ";
    struttura->a = ++struttura->a%struttura->dim; // This or below
    // struttura->a = (struttura->a + 1)%struttura->dim;
    
  }
}