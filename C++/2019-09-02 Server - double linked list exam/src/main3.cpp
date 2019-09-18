#include "dati.h"

void salvaServer(Tcloud *pc)
{
  if (pc != NULL)
  {
    Tcloud *newPc = pc;
    ofstream outFile;
    outFile.open("server.txt", ios::app);
    while (newPc != NULL)
    {
      if (newPc->server.ram >= 8 && newPc->server.numCPU == 8)
      {
        outFile << newPc->server.hostname << "::";
        if (newPc->server.so == 0)
        {
          outFile << "WIN";
        }
        else if (newPc->server.so == 1)
        {
          outFile << "MAC";
        }
        else
        {
          outFile << "LINUX";
        }
        outFile << " CPU=";
        outFile << newPc->server.numCPU << " RAM=";
        outFile << newPc->server.ram;
      }
      newPc = newPc->next;
    }
  }
}