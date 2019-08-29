#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void mergeSort(string, int, int);

int main(){
  mergeSort("A",0,3);
}

void mergeSort(string A, int p, int r) {
  cout << "(" << A << "," << p << ","<< r << ")" << endl;
  if(p < r) {
    int q = (p+r)/2;
    mergeSort(A, p, q);
    mergeSort(A, q+1, r);
  }
}
