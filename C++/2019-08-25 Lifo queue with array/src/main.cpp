#include "queue.h"

int main()
{
  Stack *stack;
  stack = new Tstack(5);  
  push(stack, Tdato(1,2,3));
  push(stack, Tdato(4,5,6));
  push(stack, Tdato(7,8,9));
  push(stack, Tdato(1,2,3));
  push(stack, Tdato(4,5,6));
  push(stack, Tdato(7,8,9));
  
  stack->print();
}