#include <iostream>
#include <fstream>
#include <vector>
#include <list>
using namespace std;

struct node {
  vector<int> connections;
  bool visited;
};

vector<node> graph;
int maxDiameter = 0;

void checkDiameter(int node, int diameter) {
  if(graph[node].visited == false) {
    graph[node].visited = true; // Check as visited
    // 
    connected.push_back(node);
    for(int i:graph[node].connections) {
      checkFriend(i);
    }
  }
}

void writeOutput(int _output) {
  ofstream outFile("output.txt");
  outFile << _output;
}

int main(){
  ifstream in("input.txt");
  int N, M;
  // N number of nodes
  // M number of arches
  in >> N >> M;
  graph.resize(N);

  for(int j=0; j<M; j++) {
    int from, to;
    in >> from >> to;
    graph[from].connections.push_back(to);
    graph[to].connections.push_back(from);
  }

  for(int i = 0; i < N; i++) {
    checkDiameter(i, 0);
  }
  writeOutput(maxDiameter);
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


