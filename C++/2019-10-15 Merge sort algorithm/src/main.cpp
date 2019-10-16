#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

void mergeSort(int *, int, int);
void merge(int *, int, int, int);
void print(int *, int);

int main() {
  ifstream in;
  in.open("input.txt");
  int n;
  in >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    in >> a[i];
  }
  print(a, n);
  mergeSort(a, 0, n-1);
  // print(a, n);
  ofstream out;
  out.open("output.txt");
  for(int i = 0; i < n; i++) {
    out << a[i] << " ";
  }
}

void mergeSort(int *a, int left, int right) {
  if(left < right) {
    int middle = (right+left)/2;
    // cout << left << " " << right << "\t";
    mergeSort(a, left, middle);
    mergeSort(a, middle+1, right);
    merge(a, left, middle, right);
  }
}

void merge(int *a, int left, int middle, int right) {
  int nElem = right - left + 1;
  if(nElem == 0) { // Impossible case
    cout << "Impossible case: error" << endl;
    exit(1);
  } else if(nElem == 1) { // Ordered element
    return;
  } else if(nElem == 2) { // 2 elements
    if(a[left] > a[right]) {
      int temp = a[right];
      a[right] = a[left];
      a[left] = temp;
    }
    // cout << endl << a[right] << a[left] << endl;
  } else { // More than 2 elements
    int temp[nElem];
    int n1 = left;
    int n2 = middle + 1;
    cout << left << " " << right << " " << "\t";
    for(int i = left; i < middle + 1; i++) {
      cout << a[i] << " ";
    }
    cout << "\t\t";
    for(int i = middle + 1; i < right+1; i++) {
      cout << a[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < nElem; i++) {
      if(a[n1] < a[n2] && n1 <= middle) {
        temp[i] = a[n1];
        n1++;
      } else if (n2 <= right){
        temp[i] = a[n2];
        n2++;
      } else {
        temp[i] = a[n1];
        n1++;
      }
    }
    print(temp, nElem);

    int k = 0;
    for(int i = left; i < right+1; i++) {
      a[i] = temp[k];
      k++;
    }
  }
}

// Prints array
void print(int *a, int n) {
  for(int i = 0; i < n; i++) {
    cout << a[i] << "\t";
  }
  cout << endl;
}
