#include "fifo.h"

int main()
{
  CodaPointer codaPointer = new Tcoda(5);
  put(codaPointer, Dato(1));
  put(codaPointer, Dato(2));
  put(codaPointer, Dato(3));
  put(codaPointer, Dato(4));
  put(codaPointer, Dato(5));
  put(codaPointer, Dato(6));
  print(codaPointer);
  get(codaPointer);
  get(codaPointer);
  get(codaPointer);
  get(codaPointer);
  get(codaPointer);
  get(codaPointer);
  print(codaPointer);
  put(codaPointer, Dato(6));
  put(codaPointer, Dato(7));
  put(codaPointer, Dato(8));
  print(codaPointer);

  CodaPointer w = new Tcoda(15);
  int i, k = 40;
  for (i = 0; i < k; i++)
  {
    // cin >> randNumber; // Disabled for debugging
    int randNumber = random(10, 99);
    int ni = random(1, 20);
    if (ni > 10)
    {
      put(w, Tdato(ni));
    }
    print(w);
    ni = random(1, 20);
    if (ni < 10)
    {
      get(w);
    }
    print(w);
  }

  Coda p(10);
  Coda d(10);
  for (i = 0; i < 40; i++)
  {
    int randNumber = random(1, 9);
    if (randNumber % 2 != 0 && randNumber < 6)
    {
      put(&d, Tdato(randNumber));
      cout << "Added to p: " << randNumber << endl;
    }
    else if (randNumber % 2 == 0 && randNumber < 5)
    {
      put(&p, Tdato(randNumber));
      cout << "Added to d: " << randNumber << endl;
    }
    else if (randNumber % 2 != 0 && randNumber > 5)
    {
      Tdato dato;
      dato = get(&d);
      cout << "Extracted from d: ";
      dato.print();
      cout << endl;
    }
    else if (randNumber % 2 == 0 && randNumber < 5)
    {
      Tdato dato;
      dato = get(&p);
      cout << "Extracted from p: ";
      dato.print();
      cout << endl;
    }
  }
  cout << "Coda d: ";
  print(&d);
  cout << endl;
  cout << "Coda p: ";
  print(&p);
  cout << endl;

  Tdato dato(10);
  CodaPointer p2[3];
  for (i = 0; i < 3; i++)
  {
    p2[i] = new Tcoda(6);
  }
  for (i = 0; i < 10; i++)
  {
    Tdato randomDato(random(10, 99));
    int randomInt = random(0, 2);
    if (!codaIsFull(p2[randomInt]))
    {
      put(p2[randomInt], randomDato);
      cout << "Added to " << randomInt << " queue" << endl;
    }
    else
    {
      cout << "Full to " << randomInt << " queue, added to scarti" << endl;
      scrivi_file("scarti.txt", dato);
    }
  }
  p2[0]->print();
  p2[1]->print();
  p2[2]->print();
}
