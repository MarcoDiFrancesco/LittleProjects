#include "dati.h"

void creaBiglietto(Tbiglietto *x) {
  int randomValue = randomInt(0,2);
  if(randomValue == 0) {
    x->mezzo = TRENO;
  } else if(randomValue == 1) {
    x->mezzo = AEREO;
  } else {
    x->mezzo = TAXI;
  }
  cout << "Destinazione: ";
  cin >> x->destinazione;
  x->dataViaggio = Tdata(randomInt(1,31),randomInt(1,12),randomInt(2010,2012));
}

void inserisciBiglietto(Tbiglietteria *b, Tbiglietto x) {
  int randomValue = randomInt(0,2);
  if(b[randomValue].sportello == NULL) {
  
  }
}

int randomInt(int min, int max) {
  return rand()%(max-min+1)+min;
}