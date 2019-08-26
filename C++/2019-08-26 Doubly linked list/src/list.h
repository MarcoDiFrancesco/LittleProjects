#ifndef __LIST__
#define __LIST__

#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

typedef struct Tdato
{
  int index;
  float value;
  
  Tdato() {
    index = 0;
    value = 0;
  }
  
  Tdato(float _value) {
    index = 0;
    value = _value;
  }
  
  Tdato(int _index, float _value) {
    index = _index;
    value = _value;
  }
  
  void print() {
    cout << value << " ";
  }
} Tdato;

typedef Tdato Dato;

typedef struct Tnodo
{
  Tdato d;
  Tnodo* prev;
  Tnodo* next;
  
  Tnodo() {
    d = Tdato();
    prev = NULL;
    next = NULL;
  }
  
  Tnodo(Tdato _d) {
    d = _d;
    prev = NULL;
    next = NULL;
  }
  
  Tnodo(Tdato _dato, Tnodo* _prev, Tnodo* _next) {
    d = _dato;
    prev = _prev;
    next = _next;
  }
  
  void print() {
    d.print();
    Tnodo *newPointer = next;
    while(newPointer != NULL) {
      newPointer->d.print();
      newPointer = newPointer->next; 
    }
    cout << endl;
  }
} Tnodo;

typedef Tnodo Nodo;
typedef Tnodo *NodoPointer;

// Functions definition
NodoPointer insertFirst(NodoPointer, Dato);
NodoPointer insertLast(NodoPointer, Dato);
NodoPointer insertOrder(NodoPointer, Dato);
NodoPointer removeFirst(NodoPointer);
NodoPointer removeLast(NodoPointer);
NodoPointer readFirst(NodoPointer);
NodoPointer readLast(NodoPointer);
float randomFloat(float, float);
int randomInt(int, int);

#endif
