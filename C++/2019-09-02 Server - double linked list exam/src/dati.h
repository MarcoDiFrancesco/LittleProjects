#ifndef __DATI__
#define __DATI__

#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

typedef enum Tsistoper {
  WIN,
  MAC,
  LINUX
} Tsistoper;

typedef char Stringa[20];

typedef struct Tserver {
  Stringa hostname;
  int numCPU;
  int ram;
  Tsistoper so;
} Tserver;

typedef struct Tcloud {
  Tserver server;
  Tcloud *next;
  Tcloud *prev;
  
  Tcloud(Tserver _server, Tcloud *_next, Tcloud *_prev) {
    server = _server;
    next = _next;
    prev = _prev;
  } 
} Tcloud;

void creaServer(Tserver *);
int randomInt(int, int);
void inserisciServer(Tcloud *, Tserver);
void salvaServer(Tcloud *);

#endif
