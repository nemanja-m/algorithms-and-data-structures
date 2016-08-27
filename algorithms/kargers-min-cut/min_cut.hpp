#ifndef __MIN_CUT__
#define __MIN_CUT__

#include "graph.hpp"
#include "random"
#include "algorithm"

// Finds min cut in given graph.
//
// NOTE: Result isn't optimal and algorithms should be run several
// times to increase chance of getting min cut
// More precisely: after O( n^2 lg n) times probability to find
// min cut is P = 1/n where n is number of vertices in graph.
size_t karger_min_cut(Graph &graph);

// Merges two vertices into one with updating corresponding edges
void   contract(Graph &graph, size_t edge_idx);

// Detect and removes edges that connect same vertices
void   remove_self_loops(Edges &edges);

// Picks random uniform edge from graph
size_t random_edge(const size_t edges_count);

#endif
