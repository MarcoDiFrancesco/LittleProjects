#include "fifo.h"

bool codaIsFull(CodaPointer _codaPointer)
{
  return _codaPointer->n == _codaPointer->dim;
}

bool codaIsEmpty(CodaPointer _codaPointer)
{
  return _codaPointer->n == 0;
}

void put(CodaPointer _codaPointer, Dato _dato)
{
  if (codaIsFull(_codaPointer))
  {
    cout << "Full - Cannot add: " << _dato.val << endl;
  }
  else
  {
    _codaPointer->s[_codaPointer->tail] = _dato;
    _codaPointer->tail = (_codaPointer->tail + 1) % (_codaPointer->dim);
    ++_codaPointer->n;
  }
}

Tdato get(CodaPointer _codaPointer)
{
  if (codaIsEmpty(_codaPointer))
  {
    cout << "Empty - not able to get" << endl;
  }
  else
  {
    Dato dato;
    dato = _codaPointer->s[_codaPointer->head];
    _codaPointer->head = (_codaPointer->head + 1) % (_codaPointer->dim);
    --_codaPointer->n;
    return dato;
  }
}

void print(CodaPointer _codaPointer)
{
  _codaPointer->print();
}

int random(int min, int max)
{
  return rand() % (max - min + 1) + min;
}

// Add data into "scarti.txt" file
void scrivi_file(char nome_file[], Tdato d)
{
  ofstream outFile;
  outFile.open("scarti.txt", ios::app);
  outFile << d.val << endl;
  outFile.close();
}
