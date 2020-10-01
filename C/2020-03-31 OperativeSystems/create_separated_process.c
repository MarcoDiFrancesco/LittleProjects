#include <stdio.h>

int main() {
  printf("Starting\n");
  char *args[] = {"./alice.out", NULL};
  // Execvp create a completely separated process and won't end the execution of this file
  execvp(args[0], args);
  printf("Ending\n");  // This will be displayed only if exec returns error
}