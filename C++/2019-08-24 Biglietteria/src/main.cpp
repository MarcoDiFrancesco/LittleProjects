#include "list.h"
  
int main() {
  Tbiglietto biglietto;
  Tbiglietteria biglietteria;
  for(int i = 0; i < 5; i++) {
    creaBiglietto(&biglietto);
    inserisciBiglietto(&biglietteria, biglietto);
  }
  biglietteria.stampa();
  salvaBiglietti(&biglietteria,TRENO);
}