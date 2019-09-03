#ifndef __DATI__
#define __DATI__

#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct Tdato {
  int index;
  float value;
  Tdato() {
    index = 0;
    value = 0.0;
  }
  void stampa() const {
    cout << "Index: " << index << " Value: " << value;
  }
} Tdato;

typedef struct Tnodo {
  Tdato dato;
  Tnodo *next;
  Tnodo() {
    dato = Tdato();
    next = NULL;
  }
  Tnodo(Tdato _dato) {
    dato = _dato;
    next = NULL;
  }
  Tnodo(Tdato _dato, Tnodo *_next) {
    dato = _dato;
    next = _next;
  }
  void stampa() const {
    dato.stampa();
  }
  bool lt(Tdato _dato) const {
    return (dato.value < _dato.value);
  }
  bool gt(Tdato _dato) const {
    return (dato.value > _dato.value);
  }
  ~Tnodo() {
    // delete next;
  }
} Tnodo;

#endif
