#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct{
  int i;
  char *c; // array of characters
} Tdato;

int main(int argc, char *argv[]){
  Tdato v1[10];
  Tdato *v2;
  v2 = new Tdato[10];

  for(int i=0; i<10; i++){
    v1[i].i = rand();
    scanf("%s",v1[i].c);
  }

  for(int i=0; i<10; i++){
    v2[i].i = rand();
    scanf("%s",v1[i].c);
  }

  delete v2;
}