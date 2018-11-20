#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]){
  int **m;
  m = new int*[5];
  for(int i=0; i<5;i++){
    m[i] = new int[10]; // columns
  }

  for(int i=0; i<5;i++){
    for(int j=0; j<10; j++){
      m[i][j]=0;    
    }
  }
  for(int i=0; i<5; i++) {
    delete[] m[i];
  }
  
  delete[] m;
}