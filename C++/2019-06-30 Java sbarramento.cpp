// Example program
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
int x[] = {9, 2, 5, 1};
int f(int *x, int *y){ // f(x[2],x)
    y[3] = 5;
    return ++(*x); // ++(x[2]) = 6
}
int g(int a){ // g(2)
    x[0] = 0;
    return f(&x[a], x);
}
int main() {
    int a = 1;
    x[a] = a;
    cout << g(++a); // 6
    for (int i = 0; i<4; i++) cout << x[i];
    return 0;
}
/*
g(++a) -> 6
x[0] = 9 -> 0
x[1] = 2 -> 1
x[2] = 5 -> 6
x[3] = 1 -> 5
*/