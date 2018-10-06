#include <stdio.h>
#include <stdlib.h>

int main(){

  // EXERCISE 1
  printf("Esercizio 1\nInserisci due numeri per fare la somma\n");
  int es1n1,es1n2;
  scanf("%d",&es1n1);
  fflush(stdin);
  scanf("%d",&es1n2);
  printf("Value: %d\n\n",es1n1+es1n2);

  // EXSERCISE 2
  printf("Esercizio 2\nInserisci due numeri per fare la divisione\n");
  int es2n1,es2n2;
  double es2sum=0;
  scanf("%d",&es2n1);
  fflush(stdin);
  scanf("%d",&es2n2);
  es2sum=(float)es2n1/(float)es2n2;
  printf("Result: %f\n\n",es2sum);

  // EXERCISE 3
  printf("Esercizio 3\nInserisci la temperatura in gradi Fahranheit per trasformarli in Celsius\n");
  float celsius=0,fahranheit=0;
  scanf("%f",&fahranheit);
  fflush(stdin);
  celsius=(float)5/9*(fahranheit-32);
  printf("Gradi in Celsius: %f\n\n",celsius);

  // EXERCISE 6
  printf("Esercizio 6\nInserisci quattro caratteri per visualizzarli in modi differenti\n");
  char char1, char2, char3, char4;
  scanf("%c",&char1);
  fflush(stdin);
  scanf("%c",&char2);
  fflush(stdin);
  scanf("%c",&char3);
  fflush(stdin);
  scanf("%c",&char4);
  fflush(stdin);
  printf("Result in row:\n%c\n%c\n%c\n%c\n",char1,char2,char3,char4);
  printf("Result in column: %c%c%c%c\n",char1,char2,char3,char4);
  printf("Result with spaces (tab): %c\t%c\t%c\t%c",char1,char2,char3,char4);

  return 0;
}
