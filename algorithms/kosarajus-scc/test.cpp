#include "string"
#include "fstream"
#include "scc.hpp"
#include "iostream"

using namespace std;

ExtendedGraph* load_graph(string filename = "test_data/test_2.txt");
void print_graph(Graph *graph);

int main(int argc, char const *argv[]) {
  ExtendedGraph *graph = load_graph();
  // graph->print_graph();

  graph->print_SCCs();

  cout << "\n\n\t-------\n\n";
  //
  // ExtendedGraph *reverse = graph->transpose();
  // print_graph(reverse);
  //
  // delete reverse;
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
