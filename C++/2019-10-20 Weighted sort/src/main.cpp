#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <map>
using namespace std;

void printArray(int *numbers, int nElem) {
  for(int i = 0; i < nElem; i++) {
    cout << numbers[i] << " ";
  }
  cout << endl;
}

int getIndex(int *numbers, int value) {
  bool check = false;
  int i = 0;
  int index;
  do {
    if(numbers[i] == value) {
      check = true;
      index = i;
    }
    i++;
  } while(check == false);
  return index;
}

int switchSingleCost(int *numbers, int nElem) {
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
  return cost;
}

int switchValueCost(int *numbers, int nElem) {
  int cost = 0;
  printArray(numbers, nElem);

  // get first non-ordered element
  // get index of it
  // exchange it with the corresponding index
  // if same match
  // call recursivly the function
  cout << getIndex(numbers, 1) << " ";

  return cost;
}

int main() {
  ifstream in("input.txt");
  int nElem;
  in >> nElem;
  // unordered_map<int, int> numbersMap;
  int numbers1[nElem];
  int numbers2[nElem];
  int temp;
  for(int i = 0; i < nElem; i++) {
    in >> temp;
    numbers1[i] = temp;
    numbers2[i] = temp;
  }
  in.close();
  int singleCost = switchSingleCost(numbers1, nElem);
  int valueCost = switchValueCost(numbers2, nElem);
}
