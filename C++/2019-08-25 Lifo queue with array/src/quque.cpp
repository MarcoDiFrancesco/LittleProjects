#include "queue.h"

bool stackIsFull(StackPointer p) {
  return p->n == p->dim;
}

bool stackIsEmpty(StackPointer p) {
  return p->n == 0;
}

void push(StackPointer p, Tdato d) {
  if(stackIsFull(p)) {
    cout << "Stack is full" << endl;
  } else {
    p->dato[p->n] = d;
    p->n = p->n + 1;
  }
}

Tdato pop(StackPointer p) {
  if(stackIsEmpty(p)){
    cout << "Stack is empty" << endl;
  } else {
    Tdato dato;
    dato = p->dato;
  }
}