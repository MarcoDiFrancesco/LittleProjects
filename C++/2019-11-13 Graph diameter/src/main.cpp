#include <iostream>
#include <fstream>
#include <vector>
#include <list>
using namespace std;

struct node {
  vector<int> connections;
  int distance;
  bool visited;
};

vector<node> graph;
int maxDistance = 0;

void checkDistance(vector<node> _graph, int node, int distance) {
  cout << "Node " << node << " distance " << distance << endl;
  if(_graph[node].visited == false) { // If not visited
    _graph[node].visited = true;
    _graph[node].distance = distance;
    for(int i:_graph[node].connections) {
      distance++;
      checkDistance(_graph, i, distance);
    }
  } else { // If already visited
    if(_graph[node].distance > distance){
      // Check if node distance is smaller than current distance
      _graph[node].distance = distance;
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
    checkDistance(graph, i, 0);
  }

  
  writeOutput(maxDistance);
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


