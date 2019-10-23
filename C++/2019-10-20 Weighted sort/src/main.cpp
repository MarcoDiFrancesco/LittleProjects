#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <unordered_map>
using namespace std;

void writeValue(unordered_map<int, int> *numbers, int index, int value) {
  // write first in second
}

void inputValues(unordered_map<int, int> *numbers) {
  ifstream in("input.txt");
  int nElem;
  in >> nElem;
  int temp;
  for(int i = 0; i < nElem; i++) {
    in >> temp;
    numbers->insert({i,temp});
  }
  in.close();
}

int getIndex(unordered_map<int,int> const *numbers, int value) {
  auto iterator = numbers->begin();
  for(int i = 0; i < numbers->size(); i++) {
    if(iterator->second == value) {
      return iterator->first;
    }
    iterator++;
  }
  return -1;
}

int getValue(unordered_map<int,int> const *numbers, int index) {
  return numbers->at(index);
}

void print(unordered_map<int,int> const *numbers) {
  for(int i = 0; i < numbers->size(); i++) {
    cout << "[" << i << "]=" << getValue(numbers, i) << " ";
  }
}

int switchSingleCost(unordered_map<int,int> const *numbers, int nElem) {
  int cost = 0;
  for(int i = 1; i < numbers->size() + 1; i++) {
    bool found = false;
    int w = i;
    do {
      if(i == getValue(numbers, w-1)) {
        found = true;
        if(i != w) {
          cost++;
          int tempValue = getValue(numbers, i-1);
          writeValue(numbers, getIndex(i-1), getIndex(w+1));
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

  // get first non-ordered element
  // get index of it
  // exchange it with the corresponding index
  // if same match
  // call recursivly the function
  
  return cost;
}

int main() {
  unordered_map<int, int> numbers;
  inputValues(&numbers);
  print(&numbers);
  int singleCost = switchSingleCost(&numbers);
//  int valueCost = switchValueCost(&numbers);
}
