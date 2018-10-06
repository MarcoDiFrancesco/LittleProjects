#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>

int main(){
  int row,col,middleRow; // needs to be odd
  row=col=30;
  middleRow=(row/2); // it considers the row in the middle of the grid
  while (1) {
    for (int character = 0; character < 4; character++) { // type of character (/ or | or - or \)
      Sleep(500);
      system("cls");
      for (size_t countRow = 0; countRow < row; countRow++) {
        for (size_t countCol = 0; countCol < col; countCol++) {
          switch (character) {
            case 0:
              if (countRow==countCol) {
                printf("\\");
              } else {
                printf(" ");
              }
              break;
            case 1:
              if (countCol==middleRow) {
                printf("|");
              } else {
                printf(" ");
              }
              break;
            case 2:
              if((countCol+countRow)==row-1){
                printf("/");
              } else {
                printf(" ");
              }
              break;
            case 3:
              if (countRow==middleRow) {
                printf("-");
              } else {
                printf(" ");
              }
              break;
            default:
              printf("d");
              break;
          }
        }
        printf("\n");
      }
    }
  }
}
