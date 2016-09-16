#include "string"
#include "fstream"
#include "scc.hpp"
#include "iostream"

using namespace std;

ExtendedGraph* load_graph(string filename = "test_data/test_4.txt");
void print_graph(Graph *graph);

// Save SCCs in file. First column is size of each SCC
// Every row contains SCC size and vertices in that SCC
// i.e. 1st row -> 3 5 8 9
// means that given SCC have 3 vertices: 5, 8, 9
void write_logs(SCCs &sccs);

int main(int argc, char const *argv[]) {
  cout << "-- Loading graph --" << endl;

  ExtendedGraph *graph = load_graph();

  cout << "-- Graph loaded --" << endl;

  cout << "-- Counting SCCs --" << endl;
  SCCs sccs = graph->count_SCCs();

  write_logs(sccs);
  cout << "-- SCCs saved in 'sccs.log' --" << endl;

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

void write_logs(SCCs &sccs) {
  ofstream file("sccs.log");

  for (auto &scc : sccs) {
    file << scc.size() << " ";
    auto iter = scc.begin();
    for (; iter != scc.end() - 1; iter++)
      file << *iter << " ";

    file << *iter << "\n";
  }

}
