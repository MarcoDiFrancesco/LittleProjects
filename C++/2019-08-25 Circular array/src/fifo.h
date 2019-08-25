#ifndef __STRUCTURE__
#define __STRUCTURE__

#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

typedef struct Tdato
{
  int val;
  
  Tdato(){
    val = 0;
  };
  
  Tdato(int _val) {
    val = _val;
  }
  
  ~Tdato(){
    // delete []val;
  }
  
  void print() {
    cout << val << "\t";
  }
}Tdato;

typedef struct Tcoda {
  int n; // Number of elements inside the queue
  int dim; // Max dimension of the queue
  int head; // Position of the element in the head
  int tail; // Position of the element in the tail
  Tdato *s;
  
  // Default constructor
  Tcoda() {
    n = 0;
    dim = 10;
    head = 0;
    tail = 0;
    s = new Tdato[dim];
  }
  
  Tcoda(int _dim) {
    n = 0;
    dim = _dim;
    head = 0;
    tail = 0;
    s = new Tdato[_dim];
  }
  
  ~Tcoda() {
    // delete []s;
  }
  
  void print() {
    if(n == 0) {
      cout << "Empty" << endl;
    } else {
      int i = head;
      cout << "List:\t";
      do {
        s[i].print();
        i = ++i%dim;
      } while(i != tail);
      cout << endl;
    }
  }
} Tcoda;

typedef Tcoda Coda;
typedef Tcoda *CodaPointer;
typedef Tdato Dato;

bool codaIsFull(CodaPointer);
bool cosaIsEmpty(CodaPointer);
void put(CodaPointer, Dato);
Tdato get(CodaPointer);
void print(CodaPointer);
int random(int,int);

#endif
