#include "dati.h"

int main() {
  Tnodo *negozio[DIM];
  for(int i = 0; i < DIM; i++) {
    negozio[i] = NULL;
  }
  Tordine o;
  for(int i = 0; i < 5; i++) {
    newOrdine(&o);
    addOrdine(negozio, DIM, o);
  }
  stampaNegozi(negozio, DIM);
  o = cercaOrdine(negozio, DIM);
  o.stampa();
}