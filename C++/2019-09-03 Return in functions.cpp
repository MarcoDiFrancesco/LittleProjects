#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct myStruct {
  int a = 0;
  
  myStruct(){
    a = 1;
  }
  
  int method(){
    a = 2;
    if(a == 2){  
      return a;
    }
    a = 3;
    return a;
  }
  
} myStruct;

int main() {
  myStruct struct1;
  cout << struct1.method();
}
