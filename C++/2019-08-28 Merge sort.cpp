#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define MAX 6
using namespace std;

void mergesort(int a[], int left, int right)
{
  if (left < right)
  {
    int center = (left + right) / 2;
    //printf("left=%d center=%d right=%d \n", left, center, right);
    cout << "left=" << left << " center="<< center << " right=" << right << endl;
    mergesort(a, left, center);
    mergesort(a, center + 1, right);
    // merge(a, left, center, right); /*si suppone implementata*/
  }
}
int main()
{
  //Inserisci le cifre della tua matricola, una alla volta
  int m[MAX] = {2,0,2,3,5,1};
  /*
  int i;
  for (i = 0; i < MAX; i++)
  {
    scanf("%d", &m[i]);
  }
  */
  mergesort(m, 0, MAX - 1);
}
