#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in;
    in.open("input.txt");
    // Capacity, N items
    int C = 0, N = 0;
    in >> C >> N;
    // Weight, Value
    int W[N], V[N];
    for(int i = 0; i < N; i++){
        in >> W[i];
        in >> V[i];
    }
}
