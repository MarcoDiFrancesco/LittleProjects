#include <iostream>
#include <stdlib.h>
using namespace std;
// Program to check if in C++ you can compare float and int
int main(){
  float a = 0.0;
  float b = 1.0;
  float c = 2.0;
  
  if(a<b){
    cout << "C++ uses < and >" << endl;
  }
  if(b<c){
    cout << "C++ uses < and >" << endl;
  }
  if(c>a){
    cout << "C++ uses < and >" << endl;
  }
  if(c>b){
    cout << "C++ uses < and >" << endl;
  }
  
  
}