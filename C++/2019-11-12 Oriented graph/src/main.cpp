#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct nodo{
  vector<int> friends;
  bool visited;
};

vector<nodo> graph;
vector<nodo> connected;

int main(){
  ifstream in("input.txt");
  int N, M, S;
  in >> N >> M >> S;
  graph.resize(N);

  for(int j=0; j<M; j++) {
    int from, to;
    in >> from >> to;
    graph[from].friends.push_back(to);
  }

  
/*
  for(int i=0; i<N; i++) {
    cout << "Nodo " << i << " ha " << grafo[i].friends.size() <<" vicini" << endl;
    for(int v: grafo[i].friends) {
      cout << "  " << v << endl;
    }
  }
*/
  return 0;
}

