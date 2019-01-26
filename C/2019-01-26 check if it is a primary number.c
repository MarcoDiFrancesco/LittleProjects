// function for testing an exercisie from the exam 

bool CercaSQPrimo(int sq[], int len){
  int shift = 0, i;
  int sum = 0;

  for(i = 0; i < len; i++){
    for(w = 0; w < len; w++){
      if(i != w){
        sum = sq[i];
        sum += sq[w];
        if (sum == numeroPrimo) {
          /* è un numero primo */
        }      
      }
    }  
  }  
}
