#ifndef __BFS__
#define __BFS__

#include "queue"
#include "../../data-structures/graph-representation/graph.hpp"
#include "stdexcept"
#include "iostream"

void bfs(Graph *graph, int start) {
  if (!graph->exists(start))
    throw std::runtime_error("Key doesn't exists!");

  // Mark all vertices as unvisited
  bool visited[graph->vertices.size()];
  for (bool &v : visited)
    v = false;

  // Push initial vertex
  std::queue<Vertex *> queue;
  queue.push(graph->vertices[start]);

  while (!queue.empty()) {
    Vertex *vertex = queue.front();
    visited[vertex->key] = true;
    std::cout << vertex->key << std::endl;
    queue.pop();

    for (auto iter = vertex->edges.begin(); iter != vertex->edges.end(); iter++)
      if (!visited[*iter])
        queue.push(graph->vertices[*iter]);
  }
}

#endif
