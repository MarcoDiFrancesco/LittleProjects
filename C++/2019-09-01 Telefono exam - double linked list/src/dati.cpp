#include "dati.h"

void newOrdine(Tordine *o) {
  int randomValueInt = randomInt(0,2);
  if(randomValueInt == 0) {
    o->tipoRichiesta = WEB;
  } else if(randomValueInt == 1) {
    o->tipoRichiesta = TELEFONO;
  } else {
    o->tipoRichiesta = UFFICIO;
  }
  do {
    cout << "Quantita': ";
    cin >> o->quantita;
  } while(o->quantita < 1 || o->quantita > 20);
  o->prezzo = randomFloat(10.0,99.99);
  cout << "Materiale: ";
  cin >>o->materiale;
}

void stampaNegozi(Tnodo **neg, int dim) {
  for(int i = 0; i < dim; i++) {
    Tnodo *newNeg = neg[i];
    cout << "neg[" << i << "]: ";
    if(newNeg == NULL) {
      cout << "Empty" << endl;
    } else {
      while(newNeg != NULL) {
        newNeg->stampa();
        newNeg = newNeg->next;
      }
    }
  }
}

void addOrdine(Tnodo **neg, int dim, Tordine o) {
  int randomValue = randomInt(0,dim-1);
  if(neg[randomValue] == NULL) { // Empty list
    neg[randomValue] = new Tnodo(o, NULL, NULL);
  } else {  // Not empty list
    Tnodo *newFirstNodo = new Tnodo(o, neg[randomValue], NULL);
    neg[randomValue]->prev = newFirstNodo;
    neg[randomValue] = newFirstNodo;
  }
}

Tordine cercaOrdine(Tnodo **neg, int dim) {
  Tordine newOrdine;
  for(int i = 0; i < dim; i++) {
    if(neg[i] != NULL){ // Check if empty
      Tnodo *newNodo = neg[i];
      while(newNodo != NULL) {
        if(!((newNodo->dato.prezzo / (float)newNodo->dato.quantita) < (newOrdine.prezzo / (float)newOrdine.quantita))) {
          newOrdine = newNodo->dato;
        }
        newNodo = newNodo->next;
      }
    }
  }
  ofstream outFile;
  outFile.open("costoso.txt", ios::app);
  outFile << newOrdine.materiale << " QTA=" << newOrdine.quantita << " (";
  if(newOrdine.tipoRichiesta == 0) {
    outFile << "WEB";
  } else if(newOrdine.tipoRichiesta == 1) {
    outFile << "TELEFONO";
  } else {
    outFile << "UFFICIO";
  }
  outFile <<") prezzo=" << newOrdine.prezzo << endl;
  return newOrdine;
}

int randomInt(int min, int max) {
  return rand()%(max-min+1)+min;
}

float randomFloat(float min, float max) {
  return ((float)rand()/RAND_MAX)*(max-min)+min;
}
