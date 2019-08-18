#include <iostream>
using namespace std;

const int MAX_AUTO = 100;

struct persona
{
  string nome;
  string cognome;
};

struct vettura
{
  string marca;
  int cilindrata;
  int anno;
  persona acquirente;
};

struct Tsalone
{
  int nVetture = 0;
  vettura vetture[MAX_AUTO];
} salone;

int askNVetture();
void initializeSalone();
void printSalone();

int main()
{
  salone.nVetture = askNVetture();
  initializeSalone();
  printSalone();
}

int askNVetture()
{
  int nVetture;
  do
  {
    cout << "Number of cars: ";
    cin >> nVetture;
  } while (nVetture < 3 || nVetture > MAX_AUTO);
  return nVetture;
}

void initializeSalone()
{
  for (int i = 0; i < salone.nVetture; i++)
  {
    salone.vetture[i].anno = rand() % (2050 - 1950 + 1) + 1950;
    salone.vetture[i].acquirente.nome = rand() % ('z' - 'a' + 1) + 'a';
    salone.vetture[i].acquirente.cognome = rand() % ('Z' - 'A' + 1) + 'A';
    salone.vetture[i].cilindrata = rand() % (2000 - 1000 + 1) + 1000;
  }
}

void printSalone()
{
  for (int i = 0; i < salone.nVetture; i++)
  {
    cout << salone.vetture[i].anno << " ";
  }
  cout << endl;
  for (int i = 0; i < salone.nVetture; i++)
  {
    cout << salone.vetture[i].acquirente.nome << " ";
  }
  cout << endl;
  for (int i = 0; i < salone.nVetture; i++)
  {
    cout << salone.vetture[i].acquirente.cognome << " ";
  }
  cout << endl;
  for (int i = 0; i < salone.nVetture; i++)
  {
    cout << salone.vetture[i].cilindrata << " ";
  }
  cout << endl;
  // macchine con cilindrata maggiore di 1500
  for (int i = 0; i < salone.nVetture; i++)
  {
    if (salone.vetture[i].cilindrata > 1500)
    {
      cout << salone.vetture[i].cilindrata << " ";
    }
  }
  cout << endl;
  // numero di macchine che sono state immatricolate tra il 2000 e 2050
  int filterMacchineImmatricolate = 0;
  for (int i = 0; i < salone.nVetture; i++)
  {
    if (salone.vetture[i].anno > 2000 && salone.vetture[i].anno < 2050)
    {
      filterMacchineImmatricolate++;
    }
  }
  cout << filterMacchineImmatricolate;
}
