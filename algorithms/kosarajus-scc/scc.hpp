#ifndef __KOSARAJUS_SCC__
#define __KOSARAJUS_SCC__

#include "../../data-structures/graph-representation/graph.hpp"
#include "stack"
#include "iostream"

typedef std::stack<int> Stack;

// Some helper methods are added to original graph data structure
// These methods help in computing strongly connected components
struct ExtendedGraph : Graph {

  // Fills Stack with vertices (in increasing order of finishing times).
  // The top element of stack has the maximum finishing time
  void fill_stack(int key, bool visited[], Stack &stack);

  // Returns reverse (or transpose) of this graph
  ExtendedGraph* transpose();

  // Prints all strongly connected components
  void print_SCCs();

  // Prints all edges in graph
  void print_graph();

  // Depth first search. Returns number of traversed vertices
  // For SCC it returns size of single SCC
  size_t DFS(int key, bool visited[], size_t count = 0);
};

void ExtendedGraph::fill_stack(int key, bool visited[], Stack &stack) {
  visited[key] = true;

  for (auto i = vertices[key]->edges.begin(); i != vertices[key]->edges.end(); i++) {
    if (!visited[*i])
      fill_stack(*i, visited, stack);
  }

  stack.push(key);
}

ExtendedGraph* ExtendedGraph::transpose() {
  ExtendedGraph *graph = new ExtendedGraph();

  for (auto &kv : this->vertices) {
    for (auto i = kv.second->edges.begin(); i != kv.second->edges.end(); i++) {
      graph->add_vertex(*i);
      graph->add_edge(*i, kv.first);
    }
  }

  return graph;
}

void ExtendedGraph::print_SCCs() {
  // Mark all vertices as unchecked for 1st DFS
  // Take one extra value in one-based index

  // TODO Use map instead of bool array

  bool *visited = new bool[this->vertices.size() + 1];
  for (size_t i = 0; i < this->vertices.size() + 1; i++)
    visited[i] = false;

  Stack stack;

  // Fill vertices in stack according to their finishing time
  for (auto &kv : this->vertices) {
    if (!visited[kv.first])
      this->fill_stack(kv.first, visited, stack);
  }

  // Mark all vertices as unchecked for 2nd DFS
  for (size_t i = 0; i < this->vertices.size() + 1; i++)
    visited[i] = false;

  ExtendedGraph *transposed = this->transpose();
  transposed->print_graph();

  // transposed->DFS(9, visited);
  while (!stack.empty()) {
    int key = stack.top();
    stack.pop();
    //  Print Strongly connected component of the popped vertex
    if (!visited[key]) {
      transposed->DFS(key, visited, 0);
      // std::cout << transposed->DFS(key, visited, 0);
      std::cout << std::endl;
     }
  }

  delete[] visited;
  delete transposed;
}

size_t ExtendedGraph::DFS(int key, bool visited[], size_t count) {
  visited[key] = true;
  std::cout << key << " ";

  for (auto i = vertices[key]->edges.begin(); i != vertices[key]->edges.end(); i++)
    if (!visited[*i])
      DFS(*i, visited, count + 1);

  return count;
}

void ExtendedGraph::print_graph() {
  for (auto &kv : this->vertices)
    for (auto i = kv.second->edges.begin(); i != kv.second->edges.end(); i++)
      std::cout << kv.first << " - " << *i << std::endl;

  std::cout << std::endl;
}

#endif
