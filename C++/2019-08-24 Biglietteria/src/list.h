#ifndef __LIST__
#define __LIST__

#include <stdlib.h>
#include <iostream>
#include <fstream>
#define STRING_LENGHT 50
using namespace std;

enum mezzo
{
  TRENO,
  AEREO,
  TAXI
};

typedef struct Tdata
{
  unsigned int gg;
  unsigned int mm;
  unsigned int aa;

  Tdata()
  {
    gg = 0;
    mm = 0;
    aa = 0;
  }

  Tdata(int _gg, int _mm, int _aa)
  {
    gg = _gg;
    mm = _mm;
    aa = _aa;
  }

  void stampa()
  {
    cout << gg << "/" << mm << "/" << aa;
  }
} Tdata;

typedef struct Tbiglietto
{
  Tdata dataViaggio;
  char destinazione[STRING_LENGHT];
  enum mezzo mezzo;

  // Default constructor
  Tbiglietto()
  {
    destinazione[0] = '\0';
    mezzo = TRENO;
  }
  
  Tbiglietto(Tdata _dataViaggio, char _destinazione[STRING_LENGHT], enum mezzo _mezzo){
    mezzo = _mezzo;
  }

  void stampa()
  {
    dataViaggio.stampa();
    cout << " viaggio ";
    switch(mezzo){
      case TRENO:
        cout << "Treno ";
        break;
      case AEREO:
        cout << "Aereo ";
        break;
      case TAXI:
        cout << "Taxi ";
        break;
    }
    cout << destinazione << "\t\t";
  }
}Tbiglietto;

typedef struct Tnodo
{
  Tbiglietto biglietto;
  Tnodo *next;

  Tnodo()
  {
    next = NULL;
  }

  Tnodo(Tbiglietto _biglietto)
  {
    biglietto = _biglietto;
    next = NULL;
  }

  void stampa()
  {
    biglietto.stampa();
  }
}Tnodo;

typedef struct Tbiglietteria
{
  int numBiglietti;
  Tnodo *sportello[3];

  Tbiglietteria()
  {
    numBiglietti = 0;
    sportello[0] = NULL;
    sportello[1] = NULL;
    sportello[2] = NULL;
  }

  void stampa()
  {
    for (int i = 0; i < 3; i++)
    {
      if (sportello[i] == NULL)
      {
        cout << "No elements inside sportello[" << i << "]";
      }
      else
      {
        cout << "Elements inside sportello[" << i << "]";
        Tnodo *newSportello = sportello[i];
        while (newSportello->next != NULL)
        {
          newSportello->stampa();
          newSportello = newSportello->next;
        }
      }
      cout << endl;
    }
  }
}Tbiglietteria;

void creaBiglietto(Tbiglietto *);
void inserisciBiglietto(Tbiglietteria *b, Tbiglietto x);
Tnodo *insertFirst(Tnodo *, Tbiglietto);
int random(int, int);
void salvaBiglietti(Tbiglietteria *, enum mezzo);

#endif
