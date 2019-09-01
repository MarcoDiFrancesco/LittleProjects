#ifndef __DATI__
#define __DATI__

#include <iostream>
#include <stdlib.h>
#include <fstream>
#define ARRAY_SIZE 3
using namespace std;

typedef enum Tpacco {
  ORDINARIO,
  CELERE,
  PRIORITY
} Tpacco;

typedef struct Tspedizione {
  char destinatario[20];
  bool assicurato;
  float peso;
  Tpacco tipoPacco;
  Tspedizione() {
    destinatario[0] = '\0';
    assicurato = false;
    peso = 0.0;
    tipoPacco = ORDINARIO;
  }
  void stampa() {
    cout << destinatario << " PESO=" << peso << " PACCO=" << tipoPacco << "\t";
  }
} Tspedizione;

typedef struct TcodaFIFO {
  Tspedizione dato;
  TcodaFIFO *next;
  TcodaFIFO() {
    dato = Tspedizione();
    next = NULL;
  }
  
  TcodaFIFO(Tspedizione d){
    dato = d;
    next = NULL;
  }
  
  TcodaFIFO(TcodaFIFO *n, Tspedizione d) {
    dato = d;
    next = n;
  }
  
  void stampa() {
    dato.stampa();
  }
} TcodaFIFO;

bool isEmpty(TcodaFIFO *);
void creaSpedizione(Tspedizione *);
void addPacco(TcodaFIFO **, Tspedizione);
void stampaSpedizioni(TcodaFIFO **);
TcodaFIFO * insertFirst(TcodaFIFO *, Tspedizione);
TcodaFIFO * removeFirst(TcodaFIFO *);
void delPacchi(TcodaFIFO **, Tpacco);
int random(int, int);

#endif
