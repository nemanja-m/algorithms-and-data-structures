#include "graph.hpp"
#include "min_cut.hpp"
#include "iostream"

using namespace std;

int main(int argc, char const *argv[]) {
  Graph graph(4, 5);

  graph.edges[0] = Edge(0, 1);
  graph.edges[1] = Edge(0, 2);
  graph.edges[2] = Edge(0, 3);
  graph.edges[3] = Edge(1, 3);
  graph.edges[4] = Edge(2, 3);

  cout << "\nMin cut: " << karger_min_cut(graph) << endl;
  cout << "\nCrossing edges: " << endl;

  for (auto e : graph.edges)
    cout << e.first << " - " << e.second << endl;

  return 0;
}
