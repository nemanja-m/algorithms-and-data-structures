#ifndef __GRAPH__
#define __GRAPH__

#include <vector>
#include <map>

struct Vertex {
  int key;
  std::vector<int> edges;

  Vertex(int key) : key(key) { }
};

struct Graph {
  std::map<int, Vertex *> vertices;

  void add_vertex(const int key) {
    if (!exists(key)) {
      vertices[key] = new Vertex(key);
    }
  }

  void add_edge(const int from, const int to) {
    Vertex *f = vertices.find(from)->second;
    f->edges.push_back(to);
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
