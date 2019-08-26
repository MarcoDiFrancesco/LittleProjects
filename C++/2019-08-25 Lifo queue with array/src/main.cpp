#include "queue.h"

int main()
{
  int i = 0;
  // Stack definition
  Stack *stack;
  stack = new Tstack(5);
  // Push commands
  push(stack, Tdato(i++, i++, i++));
  push(stack, Tdato(i++, i++, i++));
  push(stack, Tdato(i++, i++, i++));
  push(stack, Tdato(i++, i++, i++));
  push(stack, Tdato(i++, i++, i++));
  push(stack, Tdato(i++, i++, i++));
  stack->print();

  // Pop commands
  Tdato dato;
  dato = pop(stack);
  dato = pop(stack);
  cout << endl;
  stack->print();

  // Push commandts to check if it put the in the tail
  push(stack, Tdato(i++, i++, i++));
  push(stack, Tdato(i++, i++, i++));
  cout << endl;
  stack->print();

  // Pop command called inside the stucture
  stack->pop();
  stack->pop();
  cout << endl;
  stack->print();

  // Push command called inside the structure
  stack->push(Tdato(i++, i++, i++));
  stack->push(Tdato(i++, i++, i++));
  stack->push(Tdato(i++, i++, i++));
  cout << endl;
  stack->print();

  // Second program
  cout << "Second program" << endl;
  StackPointer pv;
  pv = new Tstack[3];
  for(i = 0; i < 3; i++) {
    pv[i] = Tstack(4);
  }

  Tdato d;
  for (i = 0; i < K; i++)
  {
    d = datoRandom();
    pv[random(0, 2)].push(d);
  }

  printArray(&pv, 2);
}
