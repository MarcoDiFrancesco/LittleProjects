#include "list.h"

int main()
{
  NodoPointer lista = NULL;
  NodoPointer listaOrdinata = NULL;
  
  int i;
  for (i = 0; i < 10; i++)
  {
    lista = insertLast(lista, Dato(randomFloat(-5.0, 5.0)));
  }
  lista->print();
  
  listaOrdinata = insertOrder(listaOrdinata, lista->d);
  lista = removeFirst(lista);
  listaOrdinata->print();
  
  listaOrdinata = insertOrder(listaOrdinata, lista->d);
  lista = removeFirst(lista);
  listaOrdinata->print();
  
  listaOrdinata = insertOrder(listaOrdinata, lista->d);
  lista = removeFirst(lista);
  listaOrdinata->print();

  lista->print();
}
