# About

Kosaraju's algorithm (also known as the Kosaraju–Sharir algorithm) is a linear time algorithm to find
the strongly connected components of a directed graph.

More [about](https://en.wikipedia.org/wiki/Strongly_connected_component)
strongly connected components.

# Algorithm

1. Create an empty stack ‘S’ and do `DFS` traversal of a graph. In `DFS` traversal, after calling recursive `DFS` for adjacent vertices of a vertex, push the vertex to stack.

2. Reverse directions of all arcs to obtain the transpose graph.

3. One by one pop a vertex from S while S is not empty. Let the popped vertex be `v`. Take `v` as source and do `DFS` . The `DFS` starting from v counts strongly connected component of `v`.

# How it works

The above algorithm is DFS based. It does DFS two times. DFS of a graph produces a single tree if all vertices are reachable from the DFS starting point. Otherwise DFS produces a forest. So DFS of a graph with only one SCC always produces a tree. The important point to note is DFS may produce a tree or a forest when there are more than one SCCs depending upon the chosen starting point. To find and print all SCCs, we would want to start DFS from sink vertex, then move to next sink and finally any of the remaining vertices. So how do we find this sequence of picking vertices as starting points of DFS? Unfortunately, there is no direct way for getting this sequence. However, if we do a DFS of graph and store vertices according to their finish times, we make sure that the finish time of a vertex that connects to other SCCs (other that its own SCC), will always be greater than finish time of vertices in the other SCC (See [this](http://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/GraphAlgor/strongComponent.htm) for proof).
In the next step, we reverse the graph. Consider the graph of SCCs. In the reversed graph, the edges that connect two components are reversed. So if we do a DFS of the reversed graph using sequence of vertices in stack, we process vertices from sink to source (in reversed graph). That is what we wanted to achieve and that is all needed to print SCCs one by one.

# Tests

To run test:
```bash
make run
```

Result will be saved in `sccs.log` file. Each row of file represents one strongly connected component. First number in row indicates size of SCC.

For example:

If `nth` row is:

```
2 5 4
```
than that row represents SCC with 2 vertices: 5 and 4.
