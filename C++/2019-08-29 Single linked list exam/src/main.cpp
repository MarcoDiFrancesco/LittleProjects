#include "dati.h"

int main() {
  TcodaFIFO *p = new TcodaFIFO(10);
  Tveicolo v;
  for(int i = 0; i < 5; i++) {
    creaVeicolo(&v);
    addVeicolo(p,v);
  }
  stampaVeicolo(p);
}