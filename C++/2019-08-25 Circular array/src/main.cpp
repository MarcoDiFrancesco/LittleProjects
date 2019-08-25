#include "fifo.h"

int main() {
  CodaPointer codaPointer = new Tcoda(5);
  put(codaPointer, Dato(1));
  put(codaPointer, Dato(2));
  put(codaPointer, Dato(3));
  put(codaPointer, Dato(4));
  put(codaPointer, Dato(5));
  put(codaPointer, Dato(6));
  print(codaPointer);
  Tdato dato;
  get(codaPointer);
  get(codaPointer);
  get(codaPointer);
  get(codaPointer);
  get(codaPointer);
  get(codaPointer);
  print(codaPointer);
  put(codaPointer, Dato(6));
  put(codaPointer, Dato(7));
  put(codaPointer, Dato(8));
  print(codaPointer);
  
  
}
