#include "dati.h"

void creaPozzo(Tpozzo *p)
{
  int randomNumber = randomInt(0, 2);
  if (randomNumber == 0)
  {
    p->tipoEstrazione = GAS;
  }
  else if (randomNumber == 1)
  {
    p->tipoEstrazione = PETROLIO;
  }
  else
  {
    p->tipoEstrazione = ACQUA;
  }
  do
  {
    // cout << "Quantita (between 100.0 and 800.0): "; // Disabled for debugging
    // cin >> p->quantita; // Disabled for debugging
    p->quantita = randomFloat(100.0, 800.0);
  } while (p->quantita < 100.0 || p->quantita > 800.0);

  if (rand() % 2 == 0)
  {
    p->attivo = true;
  }
  else
  {
    p->attivo = false;
  }
  // cout << "Zona (Max 20 char): "; // Disabled for debugging
  // cin >> p->zona; // Disabled for debugging
  p->zona[0] = randomInt('a','z');
}

void addPozzo(TstackLIFO **pozzi, Tpozzo s)
{
  int randomNumber = randomInt(0, 2);
  pozzi[randomNumber]->push(s);
}

void stampaPozzi(TstackLIFO **pozzi)
{
  for (int i = 0; i < N_POZZI; i++)
  {
    pozzi[i]->stampa();
    cout << endl;
  }
}

int randomInt(int min, int max)
{
  return rand() % (max - min + 1) + min;
}

float randomFloat(float min, float max)
{
  return (rand() / RAND_MAX) * (max - min) + min;
}
