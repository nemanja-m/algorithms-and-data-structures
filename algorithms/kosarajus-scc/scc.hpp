#ifndef __KOSARAJUS_SCC__
#define __KOSARAJUS_SCC__

#include "../../data-structures/graph-representation/graph.hpp"
#include "stack"

typedef std::stack<Vertex *> Stack;

// Some helper methods are added to original graph data structure
// These methods help in computing strongly connected components
struct ExtendedGraph : Graph {
  void fill_stack(Vertex *vertex, bool visited[], Stack &stack);
};

// Fills Stack with vertices (in increasing order of finishing times).
// The top element of stack has the maximum finishing time
void ExtendedGraph::fill_stack(Vertex *vertex, bool visited[], Stack &stack) {
  visited[vertex->key] = true;

  for (auto i = vertex->edges.begin(); i != vertex->edges.end(); i++) {
    if (!visited[vertex->key])
      fill_stack(this->vertices[*i], visited, stack);
  }

  stack.push(vertex);
}


#endif
