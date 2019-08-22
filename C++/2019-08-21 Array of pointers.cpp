#include <stdlib.h>
#include <iostream>
#define N_STRINGS 5
using namespace std;


int main() {
  char **dictionary;
  dictionary = new char *[10];
  string input;
  
  // add text inside the matrix
  
  for(int i = 0; i < N_STRINGS; i++) {
    cin >> input;
    dictionary[i] = new char[input.length()];
    for(int w = 0; w < input.length(); w++) {
      dictionary[i][w] = input[w];
    }
  }
  
  // print
  for(int i = 0; i < N_STRINGS; i++) {
    for(int w = 0; w < input.length(); w++) {
      cout << dictionary[i][w] << " ";
    }
    cout << endl;
  }
}