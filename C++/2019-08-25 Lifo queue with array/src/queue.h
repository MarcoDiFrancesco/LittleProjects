#ifndef __QUEUE__
#define __QUEUE__

#include <iostream>
#include <stdlib.h>
#include <fstream>
#define K 12
using namespace std;

typedef struct Tdato
{
  int x;
  int y;
  int z;

  Tdato()
  {
    x = 0;
    y = 0;
    z = 0;
  }

  Tdato(int _x, int _y, int _z)
  {
    x = _x;
    y = _y;
    z = _z;
  }

  void stampa()
  {
    cout << "[" << x << "," << y << "," << z << "]";
  }
} Tdato;

typedef struct Tstack
{
  int n;   // Number of elemetns inside
  int dim; // Max size
  Tdato *dato;

  // Default constructor: size = 5
  Tstack()
  {
    n = 0;
    dim = 5;
    dato = new Tdato[dim];
  }

  Tstack(int _dim)
  {
    n = 0;
    dim = _dim;
    dato = new Tdato[dim];
  }

  ~Tstack()
  {
    delete[] dato;
  }

  void print()
  {
    if (n == 0)
    {
      cout << "Stack is empty";
    }
    else
    {
      int tempSize = n; // Copy of the temp size
      int i = 0;
      do
      {
        cout << "[" << i << "] = ";
        dato[i].stampa();
        cout << endl;
        --tempSize;
        ++i;
      } while (tempSize != 0);
    }
  }

  bool isFull()
  {
    return n == dim;
  }

  bool isEmpty()
  {
    return n == 0;
  }

  void push(Tdato d)
  {
    if (isFull())
    {
      cout << "Stack is full" << endl;
    }
    else
    {
      dato[n] = d;
      ++n;
    }
  }

  Tdato pop()
  {
    if (isEmpty())
    {
      cout << "Stack is empty" << endl;
      return Tdato();
    }
    else
    {
      --n;
      return dato[n];
    }
  }
} Tstack;

typedef Tstack Stack;
typedef Tstack *StackPointer;

void push(StackPointer, Tdato);
Tdato pop(StackPointer);
Tdato datoRandom();
int random(int, int);
void printArray(StackPointer[], int);

#endif
