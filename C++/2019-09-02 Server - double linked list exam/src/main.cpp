#include "dati.h"

int main()
{
  Tserver s;
  Tcloud *pc = NULL;
  for (int i = 0; i < 5; i++)
  {
    creaServer(&s);
    if (pc == NULL)
    {
      pc = new Tcloud(s, NULL, NULL);
    }
    else
    {
      inserisciServer(pc, s);
    }
  }
  salvaServer(pc);
}