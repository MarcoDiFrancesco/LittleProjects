#include "dati.h"

int main() {
  TcodaFIFO *p[ARRAY_SIZE] = {NULL, NULL, NULL};
  Tspedizione s;
  for(int i = 0; i < 3; i++) {
    creaSpedizione(&s);
    addPacco(p, s);
  }
  stampaSpedizioni(p);
  delPacchi(p, ORDINARIO);
}
