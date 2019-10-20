#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void deleteElem(char *, int);
void deleteRandomElem(char *, int);
void printArray(char *, int);
int randomInt(int, int);

int main() {
  int nElem;
  ifstream in;
  in.open("input.txt");
  in >> nElem;
  char triangles[nElem];
  for(int i = 0; i < nElem; i++) {
    in >> triangles[i];
  }

  printArray(triangles, nElem);
  for(int i = 0; i < nElem/2; i++) {
    deleteRandomElem(triangles, nElem);
    printArray(triangles, nElem);
  }
  // int delValue = randomInt(1,nElem - 2);
  // deleteElem(triangles, delValue);
  printArray(triangles, nElem);
}

void deleteRandomElem(char *triangles, int nElem) {
  int delValue;
  do {
    delValue = randomInt(1,nElem - 2);
  } while(triangles[delValue] == ' ');

  int searchValue;
  if(triangles[delValue] == 'd') {
    searchValue = delValue + 1;
    while(triangles[searchValue] == ' ') {
      searchValue++;
    }
  } else if(triangles[delValue] == 's') {
    searchValue = delValue - 1;
    while(triangles[searchValue] == ' ') {
      searchValue--;
    }
  }
  triangles[delValue] = ' ';
  triangles[searchValue] = ' ';
}

void deleteElem(char *triangles, int delValue) {
  if(triangles[delValue] == 'd') {
    triangles[delValue] = triangles[delValue + 1] = ' ';
  } else if(triangles[delValue] == 's') {
    triangles[delValue] = triangles[delValue - 1] = ' ';
  }
}

void printArray(char * triangles, int nElem) {
  for(int i = 0; i < nElem; i++) {
    if(triangles[i] == 's') {
      cout << "◀ ";
    } else if(triangles[i] == 'd')  {
      cout << "▶ ";
    } else {
      cout << "  ";
    }
  }
  cout << endl;
}

int randomInt(int min, int max) {
  srand(time(NULL));
  return rand()%(max-min+1)+min;
}
