#include <stdio.h>
#include <math.h>


/*
Data una sequenza di caratteri in
ingresso, riscriverla in ordine inverso.
Si assuma che la fine della sequenza
venga indicata da un carattere ( es. %).
*/

int main() {
  int array[5] = {1,4,5,2,3};
  int counter;
  int reverseArray[5];
  int arraySize = sizeof(array)/sizeof(array[0]);

  int reverseCount = arraySize - 1; // minus one because the array 
    // is long 5 and we want the counter starting from array[4]

  for(counter = 0; counter < arraySize; counter++) {
    reverseArray[counter] = array[reverseCount];
    reverseCount--;
    printf("%d ", reverseArray[counter]);
    printf("\n");
  }
}
