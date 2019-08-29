#include "dati.h"

void creaVeicolo(Tveicolo *v) {
  int randomValue = randomInt(0,2);
  if(randomValue == 0) {
    v->tipo = AUTO;
  } else if(randomValue == 1) {
    v->tipo = MOTO;
  } else {
    v->tipo = AUTOBUS;
  }
  // cin >> v->cil; // Disabled for debugging
  v->cil = randomInt(900,4000);
  v->kw = v->cil/17;
  // cin >> v->marca; // Disable for debugging
  v->marca[0] = randomInt('A', 'Z');
}

void addVeicolo(TcodaFIFO *p, Tveicolo v){
  p->put(v);
}

int randomInt(int min, int max) {
  return rand()%(max-min+1)+min;
}

void stampaVeicolo(TcodaFIFO *p) {
  p->stampa();
}

void delAuto(TcodaFIFO *p, int c) {
  
}