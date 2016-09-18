#ifndef __DIJKSTRA__
#define __DIJKSTRA__

#include "graph.hpp"
#include "queue"
#include "tuple"
#include "iostream"
using namespace std;

struct Path {
  std::vector<int> nodes;
  int cost;

  Path() : cost(0) { }
  Path(int c) : cost(c) {}
};

// Extend bas struct with parent, cost and operator> so we can
// use priority_queue
struct PriorityVertex : Vertex {
  size_t cost;
  int parent;

  PriorityVertex(size_t c) : cost(c) { }
  PriorityVertex(const Vertex &rhs, size_t c) : Vertex(rhs), cost(c) { }

  friend bool operator> (const PriorityVertex &lhs, const PriorityVertex &rhs) {
    return lhs.cost > rhs.cost;
  }
};

typedef std::map<int, size_t> Dist;

Dist dijkstra(Graph *graph, const int source) {
  Path path;

  std::priority_queue<PriorityVertex,
                      std::vector<PriorityVertex>,
                      std::greater<PriorityVertex> >
  queue;

  std::map<int, bool> visited;
  Dist distances;

  // Push source vertex
  queue.push(PriorityVertex(*graph->vertices[source], 0));
  distances[source] = 0;

  while (!queue.empty()) {
    PriorityVertex top = queue.top();
    queue.pop();

    if ((distances.find(top.key) != distances.end()) &&
        (top.cost < distances[top.key]))
      distances[top.key] = top.cost;

    visited[top.key] = true;

    for (auto &edge : top.edges) {
      if (visited.find(edge.destination) == visited.end()) {
        queue.push(PriorityVertex(*graph->vertices[edge.destination],
          top.cost + edge.cost));

        distances[edge.destination] = top.cost + edge.cost;
      }
    }
  }

  return distances;
}

#endif
