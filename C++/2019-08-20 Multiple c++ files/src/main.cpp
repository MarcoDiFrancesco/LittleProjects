#include "salone.h"

int main()
{
  Tsalone salone;
  // ask number of vehicles
  salone.nVetture = askNVetture(&salone);
  initializeSalone(&salone);
  printSalone(&salone);
}
