#ifndef __DATI__
#define __DATI__

#include <iostream>
#include <stdlib.h>
#include <fstream>
#define DIM 2
using namespace std;

typedef enum Trichiesta {
  WEB,
  TELEFONO,
  UFFICIO
} Trichiesta;

typedef struct Tordine {
  char materiale[20];
  int quantita;
  float prezzo;
  Trichiesta tipoRichiesta;
  Tordine() {
    materiale[0] = '\0';
    quantita = 0;
    prezzo = 0.0;
    tipoRichiesta = WEB;
  }
  void stampa() {
    cout << materiale << " QTA=" << quantita << " (";
    if(tipoRichiesta == 0) {
      cout << "WEB";
    } else if(tipoRichiesta == 1) {
      cout << "TELEFONO";
    } else {
      cout << "UFFICIO";
    }
    cout <<") prezzo=" << prezzo << endl;
  }
} Tordine;

typedef struct Tnodo {
  Tordine dato;
  Tnodo *next;
  Tnodo *prev;
  Tnodo() {
    dato = Tordine();
    next = NULL;
    prev = NULL;
  }
  Tnodo(Tordine o, Tnodo *n, Tnodo *p){
    dato = o;
    next = n;
    prev = p;
  }
  void stampa(){
    dato.stampa();
  }
} Tnodo;

void stampaNegozi(Tnodo **, int);
void newOrdine(Tordine *);
int randomInt(int, int);
float randomFloat(float, float);
void addOrdine(Tnodo **, int, Tordine);
Tordine cercaOrdine(Tnodo **, int);

#endif
