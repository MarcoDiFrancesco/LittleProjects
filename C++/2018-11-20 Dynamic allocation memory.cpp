#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]) {
  int v1[10]; // stack
  v1[0] = 10;
  printf("Memory address of v1: %d\n", v1);
  printf("v1[0]:%d\n", v1[0]);
  int *v2;
  v2 = NULL;
  printf("Indirizzo di v2: %d\n",v2);
  v2 = new int[5];
  printf("Indirizzo di v2: %d\n",v2);
  v2[0]=5;
  printf("v2[0]=%d\n",*(v2+0));
  printf("v2[0]=%d\n",0[v2]);
  delete v2;

  char *nome=NULL;
  nome = new char[20];
  fflush(stdin);
  scanf("%s\n",nome);
  printf("Nome: %s\n",nome);
  delete nome;
}