#ifndef __DATI__
#define __DATI__

#include <stdlib.h>
#include <iostream>
#include <fstream>
#define N_POZZI 3
#define DEFAULT_DIM 10
using namespace std;

typedef enum Testrazione
{
  GAS,
  PETROLIO,
  ACQUA
} Testrazione;

typedef struct Tpozzo
{
  char zona[20];
  bool attivo;
  float quantita;
  Testrazione tipoEstrazione;

  Tpozzo()
  {
    zona[0] = '\0';
    attivo = false;
    quantita = 0;
    tipoEstrazione = GAS;
  }

  void stampa()
  {
    cout << zona;
    cout << " QTA=" << quantita;
    cout << "(";
    if(tipoEstrazione == 0){
      cout << "GAS";
    } else if(tipoEstrazione == 1){
      cout << "PETROLIO";
    } else {
      cout << "ACQUA";
    }
    cout << ")";
    cout << " attivo=";
    if(attivo == 0) {
      cout << "NO";
    } else {
      cout << "SI";
    }
    cout << endl;
  }
} Tpozzo;

typedef struct TstackLIFO
{
  Tpozzo *s;
  int dim;
  int N;

  TstackLIFO()
  {
    dim = 10;
    N = 0;
    s = new Tpozzo[10];
  }

  TstackLIFO(int _dim)
  {
    dim = _dim;
    N = 0;
    s = new Tpozzo[dim];
  }

  bool stackIsFull()
  {
    return N == dim;
  }

  bool stackIsEmpty()
  {
    return N == 0;
  }

  void push(Tpozzo p)
  {
    if (stackIsFull())
    {
      cout << "Stack is full, adding Tpozzo to file" << endl;
      ofstream outFile;
      outFile.open("noprod.txt", ios::app);
      outFile << p.zona;
      outFile << " QTA=";
      outFile << p.quantita;
      outFile << " (";
      outFile << p.tipoEstrazione;
      outFile << " )";
      outFile << " attivo=";
      outFile << p.attivo;
      outFile << endl;
      return;
    }
    s[N] = p;
    ++N;
  }

  Tpozzo pop()
  {
    if (stackIsEmpty())
    {
      cout << "Stack is empty" << endl;
      return Tpozzo();
    }
    --N;
    return s[N];
  }

  void stampa()
  {
    if (stackIsEmpty())
    {
      cout << "Stack is empty" << endl;
      return;
    }
    for (int i = 0; i < N; i++)
    {
      cout << "s[" << i << "]:";
      s[i].stampa();
    }
  }
} TstackLIFO;

void creaPozzo(Tpozzo *);
void addPozzo(TstackLIFO **, Tpozzo);
void stampaPozzi(TstackLIFO **);
int randomInt(int, int);
float randomFloat(float, float);

#endif
