#include <stdio.h>
#include <stdlib.h>

int main(){
  int c=getchar(); // take the first input character
	printf("numero inserito:");
	putchar(c); // the variable must be int
	printf("\n");
	int counter=0;
	while((c=getchar()) != EOF)
	{ 	// read untill the end of the string
		// EOF = end of file, to call it ctrl + c
		counter++;
		printf("numero inserito:");
		putchar(c);
		printf("\n");
	}
	printf("\nNumber of character: %d", counter);
  return 0;
}
