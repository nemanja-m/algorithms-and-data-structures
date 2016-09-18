#include "dijkstra.hpp"
#include "fstream"
#include "iostream"
#include "string"
#include "sstream"

using namespace std;

Graph* load_graph(string filename = "test_data/test_2.txt");

int main(int argc, char const *argv[]) {
  Graph *graph = load_graph();
  Dist distances = dijkstra(graph, 1);

  // Print distances from source vertex to
  // all otehr vertices in the graph
  size_t count = graph->vertices.size();
  for (size_t i = 1; i <= count; i++)
    cout << i << " " << distances[i] << endl;

  delete graph;
  return 0;
}

Graph* load_graph(string filename) {
  Graph *graph = new Graph();

  ifstream file(filename);
  string line;

  while (getline(file, line)) {
    istringstream stream(line);

    // Read 1st number from line representing vertex
    size_t src;
    stream >> src;
    graph->add_vertex(src);

    string edge;

    while (stream >> edge) {
      size_t pos = edge.find(",");
      int dst = stoi(edge.substr(0, pos));
      int cost = stoi(edge.substr(pos + 1));
      graph->add_vertex(dst);
      graph->add_edge(src, dst, cost);
    }
  }

  return graph;
}
