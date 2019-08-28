/*
[Domanda 1 - punti 4] Descrivere una funzione (linguaggio C++ o pseudocodice) che dato in
input un array A[0, . . ,n-1] di interi di dimensione massima MAX ed un intero K determina se
esistono i e j tali che A[i] + A[j]= K.
La funzione ritorna la prima coppia di indici che soddisfa la richiesta. Restituisce valori di indici
-1 -1 nel caso in cui non siano presenti.
Definire eventuali strutture a supporto.
*/
#include <stdlib.h>
#include <iostream>
#define MAX 10
using namespace std;

int main() {
  int a[MAX] = {0,1,2,3,4,5,6,7,8,0};
  int a1, a2;
  for(int i = 0; i < MAX; i++) {
    for(int w = 0; w < MAX; w++) {
      if(i != w && a[w] == a[i]){
        cout << i << "-" << w;
      }
    }
  }
  cout << "-1" << "-" << "-1";
}
