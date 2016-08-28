#include "graph.hpp"
#include "min_cut.hpp"
#include "iostream"

#define TRIALS 10

using namespace std;

int main(int argc, char const *argv[]) {
  Graph graph(4, 5);

  graph.edges[0] = Edge(0, 1);
  graph.edges[1] = Edge(0, 2);
  graph.edges[2] = Edge(0, 3);
  graph.edges[3] = Edge(1, 3);
  graph.edges[4] = Edge(2, 3);

  size_t results[TRIALS];

  // Run algorithm multiple times to increase probabilty that
  // we'll find min cut
  for (size_t i = 0; i < TRIALS; i++) {
    results[i] = karger_min_cut(graph);
  }

  cout << "\nMin cut: " << *min_element(results, results + TRIALS) << "\n\n";

  return 0;
}
