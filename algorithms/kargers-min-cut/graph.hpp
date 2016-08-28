#ifndef __GRAPH__
#define __GRAPH__

#include "stddef.h"
#include "vector"

struct Edge {
  size_t first;
  size_t second;

  // Updates connected vertices after merging
  void update(size_t old_vertex, size_t new_vertex) {
    if (this->first == old_vertex)
      this->first = new_vertex;

    if (this->second == old_vertex)
      this->second = new_vertex;
  }

  Edge(size_t first, size_t second) {
    this->first = first;
    this->second = second;
  }

  Edge(): Edge(0, 0) {}
};

typedef std::vector<Edge> Edges;

struct Graph {
  size_t vertices_count;
  Edges  edges;

  Graph(size_t v_count, size_t e_count) {
    this->vertices_count = v_count;
    this->edges = Edges(e_count);
  }

  Graph(size_t v_count, const Edges edges) {
    this->vertices_count = v_count;
    this->edges = edges;
  }
};

#endif
