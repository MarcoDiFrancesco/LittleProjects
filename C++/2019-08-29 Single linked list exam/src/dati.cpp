#include "dati.h"

void stampaVeicolo(TcodaFIFO *p) {
  p->stampa();
}

void creaVeicolo(Tveicolo *v) {
  int randomValue = random(0,2);
  if(randomValue == 0) {
    v->tipo = AUTO;
  } else if(randomValue == 1) {
    v->tipo = MOTO;
  } else {
    v->tipo = AUTOBUS;
  }
  cout << "Insert cilindrata: ";
  cin >>v->cil;
  v->kw = v->cil/17;
  cout << "Insert marca: ";
  cin >> v->marca;
}

void addVeicolo(TcodaFIFO *p, Tveicolo v){
  if(p->isFull()){ // Check if stack is full
    cout << "Stack is full";
  } else {
    p->s[p->head] = v;
    ++(p->head)%p->dim; // Increment head
    ++p->n; // Increment element number inside the stack
  }
}

void delAuto(TcodaFIFO *p, int c) {
  ofstream outFile;
  outFile.open("auto.txt", ios::app); // ios::app avoid overwriting of the lines
  int newN = p->n; // COpy of current number of elements
  for(int i = 0; i < newN; i++) {
    if(p->s[p->tail].cil < c){
      outFile << p->s[p->tail].marca << " CILINDRATA=";
      outFile << p->s[p->tail].cil << " KW=";
      outFile << p->s[p->tail].kw << endl;
      p->s[p->tail] = Tveicolo(); // Delete current veicolo
      p->tail = (++p->tail)%p->dim; // Increment tail
      --p->n; // Decrement number of elements inside the stack
    }
  }
  outFile.close();
}

int random(int min, int max) {
  return rand()%(max-min+1)+min;
}
