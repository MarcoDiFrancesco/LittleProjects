#include <errno.h>
#include <stdio.h>
#include <string.h>

int main() {
  int fp = open("pippo", "r");
  printf("Begin \n");
  printf("Errorno: %d, strerror: %s", errno, strerror(errno));
  printf("\n");
  printf("Perror in the following line\n");
  perror("Error is");
  return 0;
}