#ifndef __KOSARAJUS_SCC__
#define __KOSARAJUS_SCC__

#include "../../data-structures/graph-representation/graph.hpp"
#include "stack"
#include "iostream"
#include "algorithm"

typedef std::stack<int> Stack;

// Array of SCCs
// Each row contains vertices for given SCC
typedef std::vector<std::vector<int> > SCCs;

// Some helper methods are added to original graph data structure
// These methods help in computing strongly connected components
struct ExtendedGraph : Graph {

  // Fills Stack with vertices (in increasing order of finishing times).
  // The top element of stack has the maximum finishing time
  void fill_stack(int key, std::map<int, bool> &visited, Stack &stack);

  // Returns reverse (or transpose) of this graph
  ExtendedGraph* transpose();

  // Prints all strongly connected components
  SCCs count_SCCs();

  // Prints all edges in graph
  void print_graph();

  // Depth first search. Returns number of traversed vertices
  // For SCC it returns size of single SCC
  void DFS(int key, std::map<int, bool> &visited, std::vector<int> &scc);
};

void ExtendedGraph::fill_stack(int key, std::map<int, bool> &visited, Stack &stack) {
  visited[key] = true;

  if (exists(key)) {
    for (auto i = vertices[key]->edges.begin(); i != vertices[key]->edges.end(); i++)
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

SCCs ExtendedGraph::count_SCCs() {
  // Mark all vertices as unchecked for 1st DFS
  // Take one extra value in one-based index
  std::map<int, bool> visited;
  for (auto &kv : this->vertices) {
    visited[kv.first] = false;
    for (auto i = kv.second->edges.begin(); i != kv.second->edges.end(); i++)
        visited[*i] = false;
  }

  Stack stack;

  // Fill vertices in stack according to their finishing time
  for (auto &kv : this->vertices) {
    if (!visited[kv.first])
      this->fill_stack(kv.first, visited, stack);
  }

  // Mark all vertices as unchecked for 2nd DFS
  for (auto &kv : this->vertices) {
    visited[kv.first] = false;
    for (auto i = kv.second->edges.begin(); i != kv.second->edges.end(); i++)
        visited[*i] = false;
  }

  ExtendedGraph *transposed = this->transpose();

  // List of all SCCs and theri vertices in graph
  SCCs sccs;

  while (!stack.empty()) {
    int key = stack.top();
    stack.pop();

    if (!visited[key]) {
      std::vector<int> scc;
      transposed->DFS(key, visited, scc);
      sccs.push_back(scc);
    }
  }

  // Sort SCCs in descending order according to SCC size
  std::sort(sccs.begin(), sccs.end(),
    [](std::vector<int> &a, std::vector<int> &b) { return a.size() > b.size();});

  delete transposed;
  return sccs;
}

void ExtendedGraph::DFS(int key, std::map<int, bool> &visited, std::vector<int> &scc) {
  visited[key] = true;

  // Add vertex to SCC
  scc.push_back(key);

  if (exists(key)) {
    for (auto i = vertices[key]->edges.begin(); i != vertices[key]->edges.end(); i++)
      if (!visited[*i])
        DFS(*i, visited, scc);
  }
}

void ExtendedGraph::print_graph() {
  for (auto &kv : this->vertices)
    for (auto i = kv.second->edges.begin(); i != kv.second->edges.end(); i++)
      std::cout << kv.first << " - " << *i << std::endl;

  std::cout << std::endl;
}

#endif
