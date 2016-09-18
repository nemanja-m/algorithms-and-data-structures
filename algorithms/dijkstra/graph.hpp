#ifndef __GRAPH__
#define __GRAPH__

#include "vector"
#include "map"
#include "stddef.h"

struct Edge {
  int source;
  int destination;
  size_t cost;

  Edge(int s, int d, size_t c)
    : source(s), destination(d), cost(c) { }
};

typedef std::vector<Edge> Edges;

struct Vertex {
  int key;
  Edges edges;

  Vertex() : key(-1) { }
  Vertex(int k) : key(k) { }
  Vertex(const Vertex &rhs) : key(rhs.key), edges(rhs.edges) { }
};

typedef std::map<int, Vertex *> Vertices;

struct Graph {
  Vertices vertices;

  void add_vertex(const int key) {
    if (!exists(key)) {
      vertices[key] = new Vertex(key);
    }
  }

  void add_edge(const int src, const int dst, size_t cost) {
    Vertex *f = vertices.find(src)->second;
    f->edges.push_back(Edge(src, dst, cost));
  }

  bool exists(int key) {
    return vertices.find(key) != vertices.end();
  }

  ~Graph() {
    for (auto &kv : vertices)
      delete kv.second;
  }
};

#endif
