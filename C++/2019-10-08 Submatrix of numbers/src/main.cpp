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
  int max = INT32_MIN;

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
        matrixV[i][w] = matrix[i][w] + matrixV[i-1][w];
      }
    }
  }

  // Horizontal sum
  for(int i = 0; i < nRows; i++) {
    for(int w = 0; w < nCols; w++) {
      if(w == 0) {
        matrixH[i][w] = matrix[i][w];
      } else {
        matrixH[i][w] = matrix[i][w] + matrixH[i][w-1];
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
  cout << "------------------ Vertical" << endl;

  // Print and check vertical matrix
  for(int i = 0; i < nRows; i++) {
    for(int w = 0; w < nCols; w++) {
      cout << matrixV[i][w] << "\t";
      if(matrixV[i][w] > max) {
        max = matrixV[i][w];
      }
    }
    cout << endl;
  }
  cout << "------------------ Horizontal" << endl;

  // Print and check horizontal matrix
  for(int i = 0; i < nRows; i++) {
    for(int w = 0; w < nCols; w++) {
      cout << matrixH[i][w] << "\t";
    }
    cout << endl;
  }
  cout << "------------------" << endl;

  cout << max;
  ofstream out;
  out.open("output.txt");
  out << max;
}
