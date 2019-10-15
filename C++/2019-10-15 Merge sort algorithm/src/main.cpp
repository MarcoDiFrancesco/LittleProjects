#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

void mergeSort(int *a, int left, int right);
void merge(int *a, int left, int middle, int right);

int main() {
  ifstream in;
  in.open("input.txt");
  int n;
  in >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    in >> a[i];
  }
  for(int i = 0; i < n; i++) {
    cout << a[i] << "\t";
  }
  cout << endl;

  mergeSort(a, 0, n);

  for(int i = 0; i < n; i++) {
    cout << a[i] << "\t";
  }
  cout << endl;
}

void mergeSort(int *a, int left, int right) {
  if(left < right) {
    int middle = (right+left)/2;
    mergeSort(a, left, middle);
    mergeSort(a, middle+1, right);
    merge(a, left, middle, right);
  }
}

void merge(int *a, int left, int middle, int right) {
  int temp[right-left+1];
  int l = left;
  int m = middle+1;
  int k = 0;
  while(l < middle && m <= right) {
    if(a[l] <= a[m]) {
      temp[k] = a[l];
      k += 1;
      l += 1;
    } else {
      temp[k] = a[m];
      k += 1;
      m += 1;
    }
  }
  while(l <= middle) {
    temp[k] = a[l];
    k += 1;
    l += 1;
  }
  while(m <= right) {
    temp[k] = a[m];
    k += 1;
    m +=1;
  }
  for(l = left; l <= right; l += 1) {
    a[l] = temp[l-left];
  }
}