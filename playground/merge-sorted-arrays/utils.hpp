#ifndef __DEFS__
#define __DEFS__

#include "stddef.h"
#include "ostream"
#include "vector"
#include "../../helpers/print.hpp"

// Represents element in array with information about
// index of that array. Used for merging k sorted arrays into single sorted
// array in O(n * log(k)) time complexity where n is total number of elements
// in all arrays and k is number of merged arrays

struct Node {
  int    value;
  size_t list_no;   // Index of array which contains this node

  Node() {
    this->value = 0;
    this->list_no = 0;
  }

  Node(int value, size_t list_no) {
    this->value = value;
    this->list_no = list_no;
  }

  friend bool operator<(Node a, Node b) {
    return a.value < b.value;
  }

  friend bool operator>(Node a, Node b) {
    return a.value > b.value;
  }

  friend std::ostream& operator<<(std::ostream &output, const Node &a) {
    output << a.value;
    return output;
  }

};

typedef std::vector<int> Array;
typedef std::vector<Array > Arrays;

// Make array filled with sorted random elements
Array  make_array(size_t);
Arrays make_arrays(size_t);

// Check if given arrays are empty
bool   arrays_empty(const Arrays &);

// Take first element fro marray and construct 'Node'
Node   make_node(Array &, size_t);

// Prints input arrays
void   print_arrays(const Arrays &);

#endif
