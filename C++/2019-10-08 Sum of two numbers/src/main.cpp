#include <fstream>
using namespace std;

int main() {
  int n,m;
  ifstream in;
  in.open("input.txt");
  in >> n >> m;
  ofstream out;
  out.open("output.txt");
  out << n + m << "\n";
}