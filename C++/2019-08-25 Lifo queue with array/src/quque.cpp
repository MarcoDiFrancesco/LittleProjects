#include "queue.h"

bool stackIsFull(StackPointer p)
{
  return p->n == p->dim;
}

bool stackIsEmpty(StackPointer p)
{
  return p->n == 0;
}

void push(StackPointer p, Tdato d)
{
  if (stackIsFull(p))
  {
    cout << "Stack is full" << endl;
    return;
  }
  p->dato[p->n] = d;
  ++p->n;
}

Tdato pop(StackPointer p)
{
  if (stackIsEmpty(p))
  {
    cout << "Stack is empty" << endl;
    return Tdato();
  }
  Tdato dato;
  --p->n;
  return p->dato[p->n];
}

Tdato datoRandom()
{
  return Tdato(random(0, 9), random(0, 9), random(0, 9));
}

int random(int min, int max)
{
  return rand() % (max - min + 1) + min;
}

void printArray(StackPointer _pv[], int _n)
{
  int i;
  for (i = 0; i < _n; i++)
  {
    cout << "pv[" << i << "]:" << endl;
    _pv[i]->print();
    cout << endl;
  }
}
