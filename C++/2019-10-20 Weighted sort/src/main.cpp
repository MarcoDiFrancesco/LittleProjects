#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

void printArray(int *, int);
void switchCost(int *, int);
void switchCumulatedCost(int *, int);
void switchCumulatedCostToOne(int *, int);
void writeOutput(int);

int main() {
  ifstream in("input.txt");
  int nElem;
  in >> nElem;
  int numbers1[nElem];
  int numbers2[nElem];
  int temp;
  for(int i = 0; i < nElem; i++) {
    in >> temp;
    numbers1[i] = temp;
    numbers2[i] = temp;
  }
  in.close();

  switchCost(numbers1, nElem);
  // switchCumulatedCost(numbers2, nElem);
  switchCumulatedCost(numbers2, nElem);
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

  ofstream out("output.txt", ios::out | ios::trunc);
  out << cost << " ";
  out.close();
}

void switchCumulatedCost(int *numbers, int nElem) {
  int cost = 0;
  printArray(numbers, nElem);
  for(int i = 0; i < nElem; i++) {
    bool found = false;
    while(numbers[i] != i + 1) { // If number are not in correct position
      int getElem = numbers[i];
      int temp = numbers[getElem - 1];
      numbers[getElem - 1] = getElem;
      numbers[i] = temp;
      cost = cost + i + 1 + getElem;
      cout << "CC" << cost << " C" << i + 1 + getElem << " S" << i+1 << " E" << getElem << endl;
      printArray(numbers, nElem);
    }
  }
  // need to exchange the 1
  ofstream out("output.txt", ios::app);
  out << cost;
  out.close();
}

void switchCumulatedCostToOne(int *numbers, int nElem) {
  int cost = 0;
  printArray(numbers, nElem);
  for(int i = 0; i < nElem; i++) {
    bool found = false;
    int end = nElem;
    while(numbers[i] != end) { // If number are not in correct position
      i++;
    }
    
  }
  // need to exchange the 1
  ofstream out("output.txt", ios::app);
  out << cost;
  out.close();
}
