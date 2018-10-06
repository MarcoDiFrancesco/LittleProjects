#include <stdio.h>
#include <stdlib.h>

int main(){
  int c=getchar(); // take the first input character
	putchar(c); // the variable must be int
	int counter=0;
	while((c=getchar()) != EOF){ // read untill the end of the string
			// EOF = end of file, to call it ctrl + c
		counter++;
		putchar(c);
	}
	printf("Number of character: %d", counter);
  return 0;
}