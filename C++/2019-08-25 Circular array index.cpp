#include <iostream>
#include <stdlib.h>
using namespace std;

// Program to test how modules work
// Needed for circular arrays

int main() {
  int index = 0;
  int dim = 5;
  
  int i = 0;
  for(i = 0; i < 20; i++) {
    cout << index << " ";
    index = (++index)%dim; // 
  }
}