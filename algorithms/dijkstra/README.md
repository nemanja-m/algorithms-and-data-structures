# About

Dijkstra's algorithm is an algorithm for finding the shortest paths between nodes in a graph.
This version of algorithm fixes a single node as the "source" node and finds
shortest paths from the source to all other nodes in the graph, producing a shortest-path tree.

# Algorithm

Implementation is based on min-priority queue so running time is `O(m log(n))`
where `m` is number of edges and `n` is number of nodes.

Do while `priority_queue` isn't empty:

1. Initialize `priority_queue` with start node and path length 0.
Create a set of all the visited nodes.

2. Set top node from `priority_queue` as current (pop from `priority_queue`).
Compare the newly calculated tentative distance to the current assigned value and assign the smaller one.
Mark node as visited.

3. For the current node, consider all of its unvisited neighbors and calculate their tentative distances
and push neighbors to `priority_queue` only if they are unvisited.

# Tests

Graphs are represented as adjacency lists where each row represents
one node it's edges and corresponding path costs (lengths).

For example, let `nth` row be:

```
6 2,1 3,2
```
First number is key of node, comma separated values are adjacency nodes
and path length between them.

In above example node 6 is connected to nodes 2 and 3 with path lengths 1 and 2
respectively.

Run tests with:

```
make run
```
Change test files in `test.cpp`
