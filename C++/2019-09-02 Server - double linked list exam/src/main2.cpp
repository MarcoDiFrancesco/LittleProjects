#include "dati.h"

void inserisciServer(Tcloud *pc, Tserver s){
  Tcloud *newPc = pc; // Pointer copy
  while(newPc->next != NULL) {
    newPc = newPc->next;
  }
  Tcloud *newNodo = new Tcloud(s, NULL, newPc);
  newPc->next = newNodo;
}
