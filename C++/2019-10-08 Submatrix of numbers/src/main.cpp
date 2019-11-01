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
  int matrixV[nRows][nCols]; // Vertical
  int matrixH[nRows][nCols]; // Horizontal

  // Input matrix
  for(int i = 0; i < nRows; i++) {
    for(int w = 0; w < nCols; w++) {
      in >> matrix[i][w];
    }
  }

  // Vertical sum
  for(int i = 0; i < nRows; i++) {
    for(int w = 0; w < nCols; w++) {
      if(i == 0) {
        matrixV[i][w] = matrix[i][w];
      } else {
        matrixV[i][w] += matrixV[i-1][w];
      }
    }
  }

  // Print default matrix
  for(int i = 0; i < nRows; i++) {
    for(int w = 0; w < nCols; w++) {
      cout << matrix[i][w] << "\t";
    }
    cout << endl;
  }
  cout << endl << "----";

  // Print vertical matrix
  for(int i = 0; i < nRows; i++) {
    for(int w = 0; w < nCols; w++) {
      cout << matrixV[i][w] << "\t";
    }
    cout << endl;
  }
  cout << endl << "----";

  // Print horizontal matrix
  for(int i = 0; i < nRows; i++) {
    for(int w = 0; w < nCols; w++) {
      cout << matrixV[i][w] << "\t";
    }
    cout << endl;
  }
  cout << endl << "----";

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
  cout << sumMax;

  ofstream out;
  out.open("output.txt");
  out << sumMax;
}
