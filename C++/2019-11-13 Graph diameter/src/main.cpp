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
list<int> connected;

void checkFriend(int node) {
  if(graph[node].visited == false) {
    graph[node].visited = true; // Check as visited
    connected.push_back(node);
    for(int i:graph[node].connections) {
      checkFriend(i);
    }
  }
}

void showList(list<int> _list) {
  list<int> :: iterator i;
  int countNodes = 0;
  for(i = _list.begin(); i != _list.end(); ++i) {
    cout << *i << "\t";
    countNodes++;
  }
  ofstream outFile("output.txt");
  outFile << countNodes;
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
  }

  checkFriend(S);
  showList(connected);
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


