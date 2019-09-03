#include "dati.h"

int main() {
  Tnodo *nodo = new Tnodo();
  nodo->dato.index = 1;
  nodo->dato.value = 2.3;
  nodo->stampa();
}