#include <iostream>
using namespace std;

int random(int, int);

int main()
{
  for (int i = 0; i < 20; i++)
  {
    cout << random(0, 2) << " ";
  }
}

int random(int min, int max)
{
  return rand() % (max - min + 1) + min;
}
