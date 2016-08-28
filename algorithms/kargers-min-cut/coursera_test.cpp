#include "graph.hpp"
#include "min_cut.hpp"
#include "iostream"
#include "string"
#include "sstream"
#include "fstream"

#define TRIALS 100  // How many times we run min-cut algorithm

using namespace std;

Graph load_graph(string filename = "graph.txt");
void  run_test(string filename, size_t expected_result, size_t trials = TRIALS);

int main(int argc, char const *argv[]) {

  // Parse input args and run heavy test if its ON
  if (argc == 2 && argv[1] == string("ON") ) {
    cout << "\nRunning heavy test! This may take time ..." << endl;
    run_test("test_data/graph_0.txt", 17, 20000);
  }

  run_test("test_data/graph_1.txt", 2);
  run_test("test_data/graph_2.txt", 2);
  run_test("test_data/graph_3.txt", 1);
  run_test("test_data/graph_4.txt", 3);

  return 0;
}

void  run_test(string filename, size_t expected_result, size_t trials) {
  cout << "\n+------------------------------+" << endl;
  cout << "Test: " << "\"" + filename + "\"" << endl;
  cout << "+------------------------------+" << endl;

  Graph graph = load_graph(filename);

  cout << "\nVertices: " << graph.vertices_count << endl;
  cout << "Edges:    " << graph.edges.size() << endl << endl;
  size_t results[trials];

  for (size_t i = 0; i < trials; i++) {
    results[i] = karger_min_cut(graph);
  }

  size_t min_cut = *min_element(results, results + trials);

  if (min_cut == expected_result)
    cout << "PASSED => Min cut: " << min_cut << endl;
  else
    cout << "FAILED => Expected " << expected_result << " got "
         << min_cut << endl;

  cout << "+----------------------+" << endl;
}

Graph load_graph(string filename) {
  ifstream file(filename);
  string   line;
  Edges    edges;
  size_t   vertices_count = 0;

  while (getline(file, line)) {
    vertices_count++;

    size_t buffer;
    stringstream stream(line);

    // Read first number in line
    stream >> buffer;
    size_t vertex = buffer;

    // Read vertices that are adjacent to current one and for edges
    while (stream >> buffer) {
      if (buffer > vertices_count)
        edges.push_back(Edge(vertex, buffer));
    }
  }

  return Graph(vertices_count, edges);
}
