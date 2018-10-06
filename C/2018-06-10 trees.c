#include <stdio.h>
#include <stdlib.h>
#define max 50

int main(){

  // SQUARE n*n

  int round1, round2;
  int size;
  int nCol, nRow;

  printf("Insert number of cols and rows: ");
  scanf("%d", &size);
  printf("\n");

  nCol=nRow=size;

  for (round1 = 0; round1 < nCol; round1++) {
    for (round2 = 0; round2 <nRow; round2++) {
      printf("X");
    }
    printf("\n");
  }
  printf("\n\n");

  // BACK HALF TREE

  int round3, round4;
  int countBack;

  printf("Set size of the back half tree: ");
  scanf("%d", &size);
  printf("\n");
  countBack = size;

  for(round3 = 0; round3 < size; round3++) {
    countBack--;
    /* countBack in this position and not in the bottom because it would make
    the tree smaller */
    for(round4 = 0; round4 < size; round4++) {
      if(countBack > round4) {
        printf(" ");
      } else {
        printf("*");
      }
    }
    printf("\n");
  }
  printf("\n\n");

  // HALF TREE

  int round5, round6;
  int countForw=0;

  printf("Set size of the half tree: ");
  scanf("%d", &size);
  printf("\n");

  for(round5 = 0; round5<size; round5++) {
    countForw++;
    /* countBack in this position and not in the bottom because it would make
    the tree bigger */
    for(round6 = 0; round6<size; round6++) {
      if (countForw > round6) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  printf("\n\n");

  // COMPLETE TREE

  int round7, roundLeftSpace, roundRightSpace, roundWidthTree;
  int rightSpace, leftSpace, widthTree = 1;

  printf("Set size of the (complete) tree: ");
  scanf("%d", &size);
  printf("\n");

  rightSpace = leftSpace = size;

  for(round7 = 0; round7 < size; round7++) {
    for(roundLeftSpace = 0; roundLeftSpace<leftSpace; roundLeftSpace++) {
      printf(" ");
    }
    for(roundWidthTree = 0; roundWidthTree<widthTree; roundWidthTree++) {
      printf("*");
    }
    for(roundRightSpace = 0; roundRightSpace<rightSpace; roundRightSpace++) {
      printf(" ");
    }

    rightSpace--;
    leftSpace--;
    widthTree = widthTree + 2;

    printf("-\n");
  }

  // TREE WITH DECORATIONS

  int round8; // round for the rows
  int roundLftSpc, lftSpc; // left spaces
  int roundDecor, decor = -1; // decorations

  printf("Set size of the (complete) tree: ");
  scanf("%d", &size);
  printf("\n");

  lftSpc = size;

  for(round8 = 0; round8 <= size; round8++){
    for(roundLftSpc = 0; roundLftSpc < lftSpc; roundLftSpc++) {
      printf(" ");
    }
    printf("*");
    for(roundDecor = 0; roundDecor < decor; roundDecor++) {
      printf("o");
    }
    if(round8 != 0) printf("*");

    decor = decor + 2;
    lftSpc--;
    printf("\n");
  }

  // RHOMBUS

  int round9;
  int roundSpcRho, spcRho;
  int roundChaRho, chaRho=1; // characters of rhombus
  int sizeRho;
  int halfRho; // detect half of the rhombus

  printf("Set size of the rhombus: ");
  scanf("%d", &size);
  printf("\n");

  spcRho = halfRho = size / 2;

  for(round9 = 0; round9 < size; round9++){
    for(roundSpcRho = 0; roundSpcRho < spcRho; roundSpcRho++) {
      printf(" ");
    }
    for(roundChaRho = 0; roundChaRho < chaRho; roundChaRho++) {
      printf("*");
    }

    if(halfRho>round9){
      spcRho--;
      chaRho = chaRho + 2;
    } else {
      spcRho++;
      chaRho = chaRho - 2;
    }
    printf("\n");
  }
}
