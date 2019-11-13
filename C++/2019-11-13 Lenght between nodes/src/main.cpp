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
list<int> lengths;
int N, M, S, E;

void checkLength(int visiting, int length, vector<node> _graph) {
  cout << "Visiting " << visiting << " lenght " << length << endl;
  if(visiting == E) { // Save length
    lengths.push_back(length);
  } else if(_graph[visiting].visited == false) {
    _graph[visiting].visited = true; // Check as visited
    length++;
    for(int i:graph[visiting].connections) {
      checkLength(i, length, _graph);
    }
  }
}

void showList(list<int> _list) {
  list<int> :: iterator i;
  int min = INT32_MAX;
  int countLenghts = 0;
  for(i = _list.begin(); i != _list.end(); ++i) {
    cout << *i << "\t";
    if(*i < min) {
      min = *i;
      countLenghts = 1;
    } else if(*i == min) {
      countLenghts++;
    }
  }
  ofstream outFile("output.txt");
  cout << min << " " << countLenghts;
  outFile << min << " " << countLenghts;
}

int main(){
  ifstream in("input.txt");
  // N number of nodes
  // M number of arches
  // S starting node
  // E ending node
  in >> N >> M >> S >> E;
  graph.resize(N);

  for(int j = 0; j < M; j++) {
    int from, to;
    in >> from >> to;
    graph[from].connections.push_back(to);
  }

  checkLength(S, 0, graph);
  showList(lengths);
  return 0;
}
