#include <iostream>
#include <fstream>
#include <stdlib.h>
#define ARRAY_SIZE 100000
using namespace std;

void writeArray(int *, int, int);
void checkArrayDigits(int *);
void writeFile(int, int);
void printArray(int *);

int main() {
  int numbers[ARRAY_SIZE];
  for(int i = 0; i < ARRAY_SIZE; i++) {
    numbers[i] = 0;
  }
  ifstream in("input.txt");
  int nElem;
  in >> nElem;
  int start, end;
  for(int i = 0; i < nElem; i++) {
    in >> start;
    in >> end;
    writeArray(numbers, start, end);
  }
  checkArrayDigits(numbers);
//  printArray(numbers);
}

void writeArray(int *numbers, int start, int end) {
  for(int i = start; i < end; i++) {
    numbers[i] = 1;
  }
}

void checkArrayDigits(int *numbers) {
  int start = 0, end = 0, maxStart = 0, maxEnd = 0;
  for(int i = 0; i < ARRAY_SIZE; i++) {
    if(numbers[i] == 0) {
      if(numbers[i-1] == 1) {
        start = i;
      }
      if(numbers[i+1] == 1) {
        end = i;
      }
      if(end - start > maxEnd - maxStart) {
        maxEnd = end;
        maxStart = start;
      }
    }
  }
  writeFile(maxStart, maxEnd);
}

void writeFile(int start, int end) {
  ofstream out("output.txt");
  if(end-start != 0) {
    out << start << " ";
    out << end;
  } else {
    out << "0";
  }
}

void printArray(int *array) {
  for(int i = 0; i < ARRAY_SIZE; i++) {
    cout << array[i] << " ";
  }
}