#include <stdio.h>
#include <stdlib.h>

int main(){
  char string1[] = {'c','i','\0'}; // prints ci
  char string2[3] = {'c','i'}; // prints ci
  char string3[] = "ci"; // prints ci

  printf("%s\n",string1);
  printf("%s\n",string2);
  printf("%s\n",string3);
  printf("%c\n",string1[0]); // prints firt charachter of string1 (c)
  printf("%c\n",string1[1]);
  printf("%c\n",string1[2]); // prints empty character
}