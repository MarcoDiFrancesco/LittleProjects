#include "list.h"

void creaBiglietto(Tbiglietto *x)
{
  x->mezzo = TRENO; // Random between TRENO, AEREO and TAXI
  // cin >> x->destinazione; // Disabled for debugging
  x->destinazione[0] = 'd';
  x->dataViaggio = Tdata(random(1, 31), random(1, 12), random(2010, 2012));
}

void inserisciBiglietto(Tbiglietteria *b, Tbiglietto x)
{
  int randomNumber = random(0, 2);
  b->sportello[randomNumber] = insertFirst(b->sportello[randomNumber], x);
  b->numBiglietti++;
}

Tnodo *insertFirst(Tnodo *_sportello, Tbiglietto x)
{
  if (_sportello == NULL)
  {
    return new Tnodo(x);
  }
  Tnodo *newSportello = new Tnodo(x);
  newSportello->next = _sportello;
  return newSportello;
}

Tbiglietto removeFirst(Tnodo *_sportello)
{
  Tbiglietto removedBiglietto = _sportello->biglietto;
  _sportello = _sportello->next;
  return removedBiglietto;
}

int random(int min, int max)
{
  return rand() % (max - min + 1) + min;
}

void salvaBiglietti(Tbiglietteria *_biglietteria, enum mezzo _mezzo)
{
  ofstream outFile;
  outFile.open("biglietti.txt", ios::app);
  for (int i = 0; i < 3; i++)
  {
    Tnodo *sportello = _biglietteria->sportello[i];
    if (sportello != NULL)
    {
      while (sportello->next != NULL)
      {
        Tbiglietto newBiglietto = removeFirst(sportello);
        if (newBiglietto.mezzo == _mezzo)
        {
          outFile << newBiglietto.dataViaggio.gg << "/";
          outFile << newBiglietto.dataViaggio.mm << "/";
          outFile << newBiglietto.dataViaggio.aa << " ";
          outFile << newBiglietto.destinazione << endl;
        }
        sportello = sportello->next;
      }
    }
  }
  outFile.close();
}