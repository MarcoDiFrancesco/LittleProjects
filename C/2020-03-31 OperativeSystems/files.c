#include <stdio.h>

int main() {
  FILE *file;
  int c;
  file = fopen("files.c", "r");
  while (1) {
    c = fgetc(file);
    if (feof(file)) {
      break;
    }
    printf("%c", c);
  }
  fclose(file);
  printf("\nEnd\n");
}