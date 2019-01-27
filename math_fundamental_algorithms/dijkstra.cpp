#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <tuple>
#include <vector>

#define inf 999

using namespace std;
class Graph {
  private:
  const int vertexNum_;                           // vertex number
  const int edgeNum_;                             // edge number
  map<char, vector<pair<char, float>>> digraph_;  // direction graph
  map<char, float> minWeight;                     // minium weight

  public:
  Graph(const int vertexNum, const int edgeNum, const vector<tuple<char, char, float>> &d);
  void printGraph();
  void dijkstra(const char source);
};

Graph::Graph(const int vertexNum, const int edgeNum, const vector<tuple<char, char, float>> &d)
    : vertexNum_(vertexNum), edgeNum_(edgeNum) {
  for (unsigned int i = 0; i < edgeNum_; i++) {
    // init graph
    digraph_[get<0>(d[i])].push_back(make_pair(get<1>(d[i]), get<2>(d[i])));
    // init mw
    minWeight[get<0>(d[i])] = inf;
    minWeight[get<1>(d[i])] = inf;  // In case of ignoring vertex
  }
}

void Graph::printGraph() {
  cout << "Graph: " << endl;
  for (auto a : digraph_) {
    cout << a.first << '|';
    for (auto p : digraph_[a.first]) {
      cout << a.first << "->" << p.first << ":" << p.second << ";";
    }
    cout << endl;
  }
}

/**
 * @Detail: dijkstra algorithm from source to end.
 * @Param: source- begining vertex, end- end vertex.
 * @Return: null
 */
void Graph::dijkstra(const char source) {
  queue<char> finished;
  finished.push(source);
  // definite begin and end
  minWeight[source] = 0;
  while (!finished.empty()) {
    char temp = finished.front();
    finished.pop();
    // TODO: 存在重复遍历的情况，需要优化。
    for (auto v : digraph_[temp]) {
      // refresh distance
      minWeight[v.first] = min(minWeight[v.first], minWeight[temp] + v.second);
      finished.push(v.first);
    }
  }
  // output
  cout << "Dijkstra distance with source: " << source << endl;
  for (auto v : minWeight) {
    cout << v.first << ":" << v.second << endl;
  }
}

// test
int main(void) {
  // creat map tuple
  vector<tuple<char, char, float>> digraph = {
      make_tuple('s', 'a', 0.5),
      make_tuple('s', 'b', 0.3),
      make_tuple('s', 'c', 0.2),
      make_tuple('s', 'd', 0.4),
      make_tuple('a', 'e', 0.3),
      make_tuple('b', 'a', 0.2),
      make_tuple('b', 'f', 0.1),
      make_tuple('c', 'f', 0.4),
      make_tuple('c', 'h', 0.8),
      make_tuple('d', 'c', 0.1),
      make_tuple('d', 'h', 0.6),
      make_tuple('e', 'g', 0.1),
      make_tuple('f', 'e', 0.1),
      make_tuple('f', 'h', 0.2),
      make_tuple('h', 'g', 0.4),
  };
  Graph *test = new Graph(9, 15, digraph);
  test->printGraph();
  test->dijkstra('c');
}
