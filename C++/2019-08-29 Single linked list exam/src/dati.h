#ifndef __DATI__
#define __DATI__

#include <iostream>
#include <stdlib.h>
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
  void stampa() {
    cout << marca << " CILINDRATA=" << cil << " KW=" << kw << "Tipo:";
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
  TcodaFIFO(int x){
    dim = x;
    n = 0;
    head = 0;
    tail = 0;
    s = new Tveicolo[x];
  }
  bool isFull(){
    return n == dim;
  }
  void stampa() {
    if(n == 0) {
      cout << "Coda is empty" << endl;
    } else {
      for(int i = 0; i < n; i++) {
        s[i].stampa();
      }
    }
  }
  void put(Tveicolo v) {
    if(!isFull()){
      s[head] = v;
      ++n;
      ++head%dim;
    }
  }
  Tveicolo get() {
    Tveicolo newVeicolo = s[head];
    s[head]
    return newVeicolo;
  }
} TcodaFIFO;

void creaVeicolo(Tveicolo *);
void addVeicolo(TcodaFIFO *, Tveicolo);
int randomInt(int, int);
void stampaVeicolo(TcodaFIFO *);
void delAuto(TcodaFIFO *, int);

#endif
