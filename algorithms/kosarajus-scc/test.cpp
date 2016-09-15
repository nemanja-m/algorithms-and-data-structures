#include "string"
#include "fstream"
#include "scc.hpp"
#include "iostream"

using namespace std;

ExtendedGraph* load_graph(string filename = "test_data/test_1.txt");
void print_graph(Graph *graph);

int main(int argc, char const *argv[]) {
  ExtendedGraph *graph = load_graph();
  print_graph(graph);


  delete graph;

  return 0;
}

ExtendedGraph* load_graph(string filename) {
  ifstream file(filename);
  ExtendedGraph *graph = new ExtendedGraph();

  int from, to;

  while (file >> from >> to) {
    graph->add_vertex(from);
    graph->add_edge(from, to);
  }

  return graph;
}

void print_graph(Graph *graph) {
  for (auto &kv : graph->vertices)
    for (auto i = kv.second->edges.begin(); i != kv.second->edges.end(); i++)
      cout << kv.first << " - " << *i << endl;
}
