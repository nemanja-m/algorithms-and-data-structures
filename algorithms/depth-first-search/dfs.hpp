#ifndef __DFS__
#define __DFS__

#include "stack"
#include "../../data-structures/graph-representation/graph.hpp"
#include "stdexcept"
#include "iostream"

void dfs(Graph *graph, int start) {
  if (!graph->exists(start))
    throw std::runtime_error("Key doesn't exists!");

  // Mark all vertices as unvisited
  bool visited[graph->vertices.size()];
  for (bool &v : visited)
    v = false;

  // Push initial vertex
  std::stack<Vertex *> front;
  front.push(graph->vertices[start]);

  while (!front.empty()) {
    Vertex *vertex = front.top();
    visited[vertex->key] = true;
    std::cout << vertex->key << std::endl;
    front.pop();

    for (auto iter = vertex->edges.begin(); iter != vertex->edges.end(); iter++)
      if (!visited[*iter])
        front.push(graph->vertices[*iter]);
  }
}

#endif
