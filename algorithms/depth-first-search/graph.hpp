#ifndef __GRAPH__
#define __GRAPH__

#include <vector>
#include <map>

struct Vertex {
  int key;
  std::vector<int> edges;

  Vertex(int key) {
    this->key = key;
  }

};

struct Graph {
  std::map<int, Vertex *> vertices;

  void add_vertex(const int key) {
    if (vertices.find(key) == vertices.end()) {
      vertices[key] = new Vertex(key);
    }
  }

  void add_edge(const int from, const int to) {
    Vertex *f = vertices.find(from)->second;
    f->edges.push_back(to);
  }
};

#endif
