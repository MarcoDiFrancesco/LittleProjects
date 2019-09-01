#ifndef __DATI__
#define __DATI__

#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

typedef enum Ttipo {  
  AUTO,
  MOTO,
  AUTOBUS
} Ttipo;

typedef struct Tveicolo {
  char marca[20];
  int cil;
  float kw;
  Ttipo tipo;
  
  Tveicolo() {
    marca[0] = '\0';
    cil = 0;
    kw = 0;
    tipo = AUTO;
  }
  
  void stampa() {
    cout << marca << " " << cil << " " << kw << " ";
    if(tipo == 0) {
      cout << "AUTO";
    } else if(tipo == 1) {
      cout << "MOTO";
    } else {
      cout << "AUTOBUS";
    }
    cout << endl;
  } 
} Tveicolo;

typedef struct TcodaFIFO {
  int n;
  int dim;
  int head;
  int tail;
  Tveicolo *s;
  TcodaFIFO(int x) {
    dim = x;
    n = 0;
    head = 0;
    tail = 0;
    s = new Tveicolo [x];
  }
  
  bool isFull() {
    return n == dim;
  }
  
  bool isEmpty() {
    return n == 0;
  }
  
  void stampa() {
    if(n == 0) {
      cout << "Coda is empty" << endl;
    } else {
      int newTail = tail; // Copy of tail
      for(int i = 0; i < n; i++) {
        s[newTail].stampa();
        ++newTail%dim;
      }
    }
  }
} TcodaFIFO;

void stampaVeicolo(TcodaFIFO *);
void creaVeicolo(Tveicolo *);
void addVeicolo(TcodaFIFO *, Tveicolo);
void delAuto(TcodaFIFO *, int);
int random(int, int);

#endif
