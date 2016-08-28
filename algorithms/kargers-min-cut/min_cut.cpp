#include "min_cut.hpp"

size_t karger_min_cut(Graph graph) {
  while (graph.vertices_count > 2) {
    size_t edge = random_edge(graph.edges.size() - 1);
    contract(graph, edge);
    remove_self_loops(graph.edges);
  }

  return graph.edges.size();
}

void contract(Graph &graph, size_t edge_idx) {
  Edge edge = graph.edges[edge_idx];

  graph.vertices_count--;
  graph.edges.erase(graph.edges.begin() + edge_idx);  // Remove edge

  // For each edge in graph update corresonding vertex only if
  // edge is connected with merged vertex
  for (auto &e : graph.edges) {
    // We merge second vertex into first one
    e.update(edge.second, edge.first);
  }
}

void remove_self_loops(Edges &edges) {
  Edges::iterator new_end = std::remove_if(edges.begin(), edges.end(),
    [](Edge &e) { return e.first == e.second; });

  edges.erase(new_end, edges.end());
}

size_t random_edge(const size_t edges_count) {
  std::random_device                    rand_dev;
  std::mt19937                          generator(rand_dev());
  std::uniform_int_distribution<size_t> distr(0, edges_count);

  return distr(generator);
}
