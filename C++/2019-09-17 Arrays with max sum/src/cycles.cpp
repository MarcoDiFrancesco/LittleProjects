#include "main.h"

void efficency1(int *a)
{
  int sum = 0, max = INT32_MIN, first = 0, last = 0;
  for (int i = 0; i < SIZE; i++)
  {
    for (int w = i; w < SIZE; w++)
    {
      sum += a[w];
      if (sum > max)
      {
        max = sum;
        first = i;
        last = w;
      }
    }
    sum = 0;
  }

  cout << max << " - " << first << " - " << last << endl;
}

void efficency2(int *a)
{
  int sum = 0, sumMax = INT32_MIN, first = 0, firstMax = 0, lastMax = 0;
  for (int i = 0; i < SIZE; i++)
  {
    sum += a[i];
    if (sum > sumMax) // Memorize max
    {
      if(a[i] > sum) {
        sum = a[i];
        firstMax = i;
      } else {
        firstMax = first+1;
      
      }
      sumMax = sum;
      lastMax = i;
    }
    if (sum < a[first])
    {
      sum = 0;
      first = i+1;
    }
  }

  cout << sumMax << " - " << firstMax << " - " << lastMax << endl;
}
