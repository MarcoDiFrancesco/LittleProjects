#include <iostream>
#include <cmath>
struct dupla {
 double a, b;
} ;

using namespace std;
int main () {
int N = 100;
dupla* y = new dupla[N];
for(int i = 0; i < 10; i++) {
  y[i].a = i;
  cout << y[i].a << " ";
}
return 0;
}