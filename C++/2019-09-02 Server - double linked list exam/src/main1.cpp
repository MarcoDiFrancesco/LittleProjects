#include "dati.h"

void creaServer(Tserver *s) {
  int randomValue = randomInt(0,2);
  if(randomValue == 0) {
    s->so = WIN;
  } else if(randomValue == 1) {
    s->so = MAC;
  } else {
    s->so = LINUX;
  }
  s->numCPU = randomInt(4,8);
  do {
    cout << "Ram: ";
    cin >> s->ram;
  } while(s->ram < 4 || s->ram > 16);
  cout << "Hostname: ";
  cin >> s->hostname;
}

int randomInt(int min, int max) {
  return rand()%(max-min+1)+min;
}