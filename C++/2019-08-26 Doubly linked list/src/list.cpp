#include "list.h"

NodoPointer insertFirst(NodoPointer _s, Dato _d)
{
  if (_s == NULL)
  {
    return new Nodo(_d, NULL, NULL);
  }
  NodoPointer newNodo = new Nodo(_d, NULL, _s);
  _s->prev = newNodo;
  return newNodo;
}

NodoPointer insertLast(NodoPointer _s, Dato _d)
{
  if (_s == NULL)
  {
    return new Nodo(_d, NULL, NULL);
  }
  NodoPointer newPointer = _s;
  while (newPointer->next != NULL)
  {
    newPointer = newPointer->next;
  }
  NodoPointer newNodo = new Nodo(_d, newPointer, NULL);
  newPointer->next = newNodo;
  return _s;
}

NodoPointer removeFirst(NodoPointer _s)
{
  if (_s == NULL)
  {
    cout << "Cannot remove" << endl;
    return _s;
  }
  if (_s->next == NULL)
  {
    delete _s;
    return NULL;
  }
  NodoPointer newPointer = _s;
  _s = _s->next;
  _s->prev = NULL;
  // delete newPointer;
  return _s;
}

NodoPointer removeLast(NodoPointer _s)
{
  if (_s == NULL)
  {
    cout << "Cannot remove" << endl;
    return _s;
  }
  if (_s->next == NULL)
  {
    delete _s;
    return NULL;
  }
  NodoPointer newPointer = _s;
  while (newPointer->next->next != NULL)
  {
    newPointer = newPointer->next;
  }
  delete newPointer->next;
  newPointer->next = NULL;
  return _s;
}

NodoPointer insertOrder(NodoPointer _s, Dato _d)
{
  if (_s == NULL)
  {
    return insertFirst(_s, _d);
  }
  NodoPointer newPointer = _s;
  while (newPointer->next != NULL && newPointer->d.value > _d.value)
  {
    newPointer = newPointer->next;
  }
  if (newPointer->prev == NULL)
  {
    return insertFirst(_s, _d);
  }
  NodoPointer newNodo = new Tnodo(_d, newPointer, newPointer->next);
  newPointer->next->prev = newNodo;
  newPointer->next = newNodo;
  return _s;
}

NodoPointer readFirst(NodoPointer _s)
{ 
  if(_s == NULL) {
    return NULL;
  }
  return _s;
}

NodoPointer readLast(NodoPointer _s)
{ 
  if(_s == NULL) {
    return NULL;
  }
  NodoPointer newNodo = _s;
  while(newNodo->next != NULL){
    newNodo = newNodo->next;
  }
  return newNodo;
}

float randomFloat(float min, float max)
{
  return ((float)rand() / RAND_MAX) * (max - min) + min;
}

int randomInt(int max, int min)
{
  return rand() % (max - min + 1) + min;
}