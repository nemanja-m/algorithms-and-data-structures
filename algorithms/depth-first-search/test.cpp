#include "string"
#include "fstream"
#include "dfs.hpp"

using namespace std;

Graph* load_graph(string filename = "test_data/test_1.txt");

int main(int argc, char const *argv[]) {
  Graph *graph = load_graph();

  // Treverses graph and prints all reachable vertices from starting vertex
  dfs(graph, 2);
  delete graph;

  return 0;
}

Graph* load_graph(string filename) {
  ifstream file(filename);
  Graph *graph = new Graph();

  int from, to;

  while (file >> from >> to) {
    graph->add_vertex(from);
    graph->add_edge(from, to);
  }

  return graph;
}
