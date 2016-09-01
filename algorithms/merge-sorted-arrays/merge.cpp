#include "../../helpers/helpers.hpp"
#include "../../data-structures/heap/heap.hpp"
#include "utils.hpp"
#include "iostream"

using namespace std;

int main(int argc, char const *argv[]) {

  if (argc != 2) {
    cerr << "\nInvalid number of params!\n"
         << "Please enter number of arrays\n" << std::endl;
    return -1;
  }

  // Randomize seed for generating arrays
  srand(time(0));

  // Number of arrays to merge
  size_t count = stoi(argv[1]);
  // Make 'count' arrays with sorted random numbers
  Arrays arrays = make_arrays(count);

  print(arrays);

  // Take 1st element from all arrays
  Node *nodes = new Node[count];
  for (size_t i = 0; i < count; i++) {
    nodes[i] = make_node(arrays[i], i);
  }

  // Build Heap with 1st elements (total 'count' elements in heap)
  Heap<Node> heap(nodes, count, MIN);

  cout << "\nInitial Heap:" << endl;
  heap.print();

  // Resulting array of merged sorted elements from all smaller arrays
  Array final_array;

  while (true) {
    // Remove smallest element from heap
    Node removed = heap.remove(0);
    final_array.push_back(removed.value);

    if (heap.empty())
      break;

    // Insert new element into heap from previous array unless it's empty
    // If so, find next array which isn't empty
    if (!arrays_empty(arrays)) {
      size_t idx = removed.list_no;
      while (arrays[idx].empty()) {
        idx = (idx + 1) % count;
      }

      Node temp = make_node(arrays[idx], idx);
      heap.insert(temp);
    }
  }

  cout << "\nFinal array: " << endl;
  print(final_array);

  delete[] nodes;
  
  return 0;
}
