#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
  int **a;
  a = new int*[10];
  for(int i = 0; i < 10; i++) {
    a[i] = new int[5];
  }
  a[3][2] = 5;
}

