#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

void printArray(int *, int);
void switchCost(int *, int);
void switchCumulatedCost(int *, int);
void writeOutput(int);

int main() {
  ifstream in("input.txt");
  int nElem;
  in >> nElem;
  int numbers[nElem];
  for(int i = 0; i < nElem; i++) {
    in >> numbers[i];
  }
  switchCost(numbers, nElem);
  switchCumulatedCost(numbers, nElem);
//  printArray(numbers, nElem);
}

void printArray(int *numbers, int nElem) {
  for(int i = 0; i < nElem; i++) {
    cout << numbers[i] << " ";
  }
  cout << endl;
}

void switchCost(int *numbers, int nElem) {
  int cost = 0;
  for(int i = 1; i < nElem + 1; i++) {
    // printArray(numbers, nElem);
    bool found = false;
    int w = i;
    do {
      if(i == numbers[w-1]){
        found = true;
        if(i != w) {
          cost++;
          int tempValue = numbers[i-1];
          numbers[i-1] = numbers[w-1];
          numbers[w-1] = tempValue;
        }
      }
      w++;
    } while(found != true);
  }
  writeOutput(cost);
}

void switchCumulatedCost(int *numbers, int nElem) {
  int cost = 0;
  for(int i = nElem; i > 0; i--) {
    bool found = false;
    int w = i;
    do {
      
      w--;
    } while(w != numbers[w-1]);
  }
  writeOutput(cost);
}

void writeOutput(int cost) {
  ofstream out("output.txt");
  out << cost << " ";
}