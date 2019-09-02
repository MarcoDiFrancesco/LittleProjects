#include "dati.h"

bool isEmpty(TcodaFIFO *coda) {
  return coda == NULL;
}

void creaSpedizione(Tspedizione *s) {
  int randomValue = random(0,2);
  if(randomValue == 0) {
    s->tipoPacco = ORDINARIO;
  } else if(randomValue == 1) {
    s->tipoPacco = CELERE;
  } else {
    s->tipoPacco = PRIORITY;
  }
  do {
    cout << "Insert peso: ";
    cin >> s->peso;
  } while(s->peso < 200.0 || s->peso > 5000.0);
  
  if(s->tipoPacco == CELERE || s->tipoPacco == PRIORITY) {
    s->assicurato = true;
  } else {
    s->assicurato = false;
  }
  cout << "Insert destinatario: ";
  cin >> s->destinatario;
}
void addPacco(TcodaFIFO **p, Tspedizione s) {
  int randomValue = random(0,2);
  if(isEmpty(p[randomValue])) { // Case coda is empty
    p[randomValue] = new TcodaFIFO(s);
  } else { // Coda is not empty
    p[randomValue] = insertFirst(p[randomValue], s);
  }
}

void stampaSpedizioni(TcodaFIFO **p) {
  for(int i = 0; i < ARRAY_SIZE; i++) {
    cout << "p[" << i << "]: ";
    if(isEmpty(p[i])) {
      cout << "Coda is empty" << endl;
    } else {
      TcodaFIFO *newPointer = p[i];
      while(newPointer != NULL) {
        newPointer->stampa();
        newPointer = newPointer->next;
      }
    }
    cout << endl;
  }
}

void delPacchi(TcodaFIFO **p, Tpacco tp) {
  ofstream outFile;
  outFile.open("pacchiOrdinari.txt", ios::app);
  while(!isEmpty(p[1])){  
    outFile << p[1]->dato.destinatario;
    outFile << " PESO=" << p[1]->dato.peso;
    outFile << endl;
    p[1] = removeFirst(p[1]);
  }
}

TcodaFIFO * insertFirst(TcodaFIFO *_coda, Tspedizione _spedizione) {
  return new TcodaFIFO(_coda, _spedizione);
}

TcodaFIFO * removeFirst(TcodaFIFO *_coda) {
  TcodaFIFO *newCoda = _coda;
  _coda = _coda->next;
  //delete newCoda;
  return _coda;
}

int random(int min, int max) {
  return rand()%(max-min+1)+min;
}