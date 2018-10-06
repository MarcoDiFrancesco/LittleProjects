#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
/* ESERCIZIO 2
	bool test=false;
	int nInput=0; // set 0 to make the first while false

	while(test == false){
		if (nInput >= 10 || nInput <= 1)	{
			test = false;
			printf("Insert a number: ");
			scanf("%d",&nInput);
		} else {
			test = true;
		}
	}

	if(nInput < 5){
		for (int i = nInput; i <= 10; ++i) {
			printf("%d\n", i);
		}
	} else {
		for (int i = 10; i >= nInput; --i) {
			printf("%d\n", i);
		}
	}

	printf("end");
*/

/* ESERCIZIO 3
	int nInput=0; int count=1950;
	printf("Insert a number bigger than 1950: ");
	scanf("%d",&nInput);

	while(nInput < 1950) {
		printf("Insert a bigger number: ");
		scanf("%d",&nInput);
	}

	while(count<=nInput){
		if(count%400 == 0 || (count%4 == 0 && count%100 != 0) )
			printf("%d - ", count);
		count++;
	}
*/

// ESERCIZIO 4
  int numbers[5];
  int min=0, max=0;
  float avg;

  for (int i = 0; i < 5; ++i) { // Search minimum number
      scanf("%d",&numbers[i]);
	  if(min > numbers[i])
	  	min = numbers[i];
	  if(max < numbers[i])
	  	max = numbers[i];
	  avg=avg+numbers[i];
  }
  avg=avg/5;
  printf("Min: %d\n",min);
  printf("Max: %d\n",max);
  printf("Average: %d\n",avg);

}
