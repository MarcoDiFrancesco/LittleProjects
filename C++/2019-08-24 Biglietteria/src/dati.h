#ifndef __DATI__
#define __DATI__

#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

typedef enum Tmezzo {
  TRENO,
  AEREO, 
  TAXI
} Tmezzo;

typedef struct Tdata {
  unsigned int gg;
  unsigned int mm;
  unsigned int aa;
  Tdata() {
    gg = 1;
    mm = 1;
    aa = 1970;
  }
  Tdata(int _gg, int _mm, int _aa) {
    gg = _gg;
    mm = _mm;
    aa = _aa;
  }
  void stampa() const {
    cout << gg << "/" << mm << "/" << aa;
  }
} Tdata;

typedef struct Tbiglietto {
  Tdata dataViaggio;
  char destinazione[20];
  Tmezzo mezzo;
  Tbiglietto() {
    dataViaggio = Tdata();
    destinazione[0] = '\0';
    mezzo = AEREO;
  }
  void stampa() const {
    dataViaggio.stampa();
    cout << " viaggio ";
    if(mezzo == 0) {
      cout << "TRENO";
    } else if(mezzo == 1) {
      cout << "AEREO";
    } else {
      cout << "TAXI";
    }
    cout << " " << destinazione << endl;
  }
} Tbiglietto;

typedef struct Tnodo {
  Tbiglietto biglietto;
  Tnodo *next;
  Tnodo() {
    biglietto = Tbiglietto();
    next = NULL;
  }
  void stampa() const {
    if(next == NULL) {
      return;
    }
    while(next != NULL) {
      biglietto.stampa();
    }
  }
} Tnodo;

typedef struct Tbiglietteria {
  int numBiglietti;
  Tnodo *sportello;
  Tbiglietteria() {
    numBiglietti = 0;
    sportello = new Tnodo[3];
  }
  void stampa() const {
    for(int w = 0; w < 3; w++) {
      sportello[w].stampa();
      cout << endl;
    }
  }
} Tbiglietteria;

void creaBiglietto(Tbiglietto *);
void inserisciBiglietto(Tbiglietteria *, Tbiglietto);
int randomInt(int, int);

#endif
