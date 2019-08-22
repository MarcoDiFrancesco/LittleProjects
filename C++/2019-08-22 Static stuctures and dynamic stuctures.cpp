#include <stdlib.h>
#include <iostream>
#define ARRAY_SIZE 10
using namespace std;

struct Tdato
{
  int k;
  int c;
};

struct Tnodo
{
  int n;
  Tdato *p;
};

int random(int, int);

int main()
{
  Tnodo v[ARRAY_SIZE];
  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    int randomNumber = random(2, 8);
    v[i].n = randomNumber;
    v[i].p = new Tdato[randomNumber];
    for (int w = 0; w < randomNumber; w++)
    {
      v[i].p[w].k = random(0, 99);
      v[i].p[w].c = random(0, 99);

      cout << v[i].p[w].k << " e " << v[i].p[w].c << "\t\t";
    }
    cout << endl;
  }
}

int random(int min, int max)
{
  return rand() % (max - min + 1) + min;
}