#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]){
  int v1[10];
  int *v2;
  v2 = new int[10];

  for(int i=0; i<10; i++){
    v1[i] = rand();
    v2[i] = rand();
  }
  for(int i=0; i<10; i++){
    printf("[%d]",v1[i]);
  }
  printf("\n");
  for(int i=0; i<10; i++){
    printf("[%d]",v2[i]);
  }
  delete v2;
}