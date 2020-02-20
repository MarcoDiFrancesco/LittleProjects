#include <iostream>
#include <cmath>
using namespace std;

struct tupla {
  double a, b;
};

using namespace std;
int main() {
  int N = 100;
  tupla* y = new tupla[N];
  for(int i = 0; i < 10; i++) {
    y[i].a = i;
    cout << y[i].a << " ";
  }
  return 0;
}