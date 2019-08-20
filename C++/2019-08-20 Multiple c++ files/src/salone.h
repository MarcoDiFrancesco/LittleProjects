#ifndef SALONE_H
#define SALONE_H
#define MAX_AUTO 100
#include <iostream>
using namespace std;

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
};

int askNVetture(Tsalone *salone);
void initializeSalone(Tsalone *salone);
void printSalone(Tsalone *salone);

#endif
