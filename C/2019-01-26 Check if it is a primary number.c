#include <math.h>
// function for testing an exercisie from the exam 

bool CercaSQPrimo(int sq[], int len){
  int shift = 0, i, sum;

  for(i = 0; i < len; i++){
    sum = sq[i];
    for(w = i+1; w < len; w++){
      while(  )
      if(i != w){ // check if it's not adding the same number
        sum += sq[w];
        if (sum == numeroPrimo) {
          /* è un numero primo */
        }
        sum -= sq[w];        
      }
    }
  }  
}
