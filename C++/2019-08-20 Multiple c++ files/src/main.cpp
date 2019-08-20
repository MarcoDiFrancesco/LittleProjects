#include <iostream>
#include "salone.h"
using namespace std;

int main()
{
  Tsalone salone;
  // ask number of vehicles
  salone.nVetture = askNVetture(&salone);
  initializeSalone(&salone);
  printSalone(&salone);
}
