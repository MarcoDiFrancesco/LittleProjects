#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

int main() {
  ifstream in;
  in.open("input.txt");
  int nRows, nCols;
  in >> nRows;
  in >> nCols;
  int matrix[nRows][nCols];

  // Input matrix
  for(int i = 0; i < nRows; i++) {
    for(int w = 0; w < nCols; w++) {
      in >> matrix[i][w];
    }
  }

  int sum = 0, sumMax = 0;
  for(int i = 0; i < nRows; i++) {
    for(int w = 0; w < nCols; w++) {
      for(int y = i; y < nRows; y++) {
        for(int z = w; z < nCols; z++) {
          sum += matrix[y][z];
          if(sum > sumMax) {
            sumMax = sum;
          }
        }
      }
      sum = 0;
    }
  }

  // Print
  for(int i = 0; i < nRows; i++) {
    for(int w = 0; w < nCols; w++) {
      cout << matrix[i][w] << "\t";
    }
    cout << endl;
  }
  cout << endl;
  cout << sumMax;
  ofstream out;
  out.open("output.txt");
  out << sumMax;
}
