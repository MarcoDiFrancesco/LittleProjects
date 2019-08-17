#include <stdio.h>
#include <stdlib.h>

int main() {
  char a, b, c, d;
  scanf("%c", &a);
  fflush(stdin);
  scanf("%c", &b);
  fflush(stdin);
  scanf("%c", &c);
  fflush(stdin);
  scanf("%c", &d);
  
  printf("Output1:\n%c\n%c\n%c\n%c",a,b,c,d);
}