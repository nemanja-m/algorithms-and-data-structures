#ifndef __HEAP_H__
#define __HEAP_H__

#include "iterator"

// #define PARENT(x) ( (x - 1) >> 1 )
// #define LEFT(x)   ( (x << 1) + 1 )
// #define RIGHT(x)  ( (x << 1) + 2 )


namespace {

}

template <class Iter>
Iter get_left(Iter begin, Iter node) {
  auto idx = node - begin;
  return begin + (idx << 1) + 1;
}

template <class Iter>
Iter get_right(Iter begin, Iter node) {
  auto idx = node - begin;
  return begin + (idx << 1) + 2;
}

template <class Iter>
Iter parent(Iter begin, Iter node) {
  auto idx = node - begin;
  return begin + ((idx - 1) >> 1);
}

template <class Iter, class Comparator>
void heapify(Iter begin, Iter end, Iter node, Comparator cmp) {
  Iter for_replace;

  // Get left and right child of parent node
  Iter left  = get_left(begin, node);
  Iter right = get_right(begin, node);

  // Find element which breaks heap rule
  if ((left < end) && !cmp( *left, *node))
    for_replace = left;
  else
    for_replace = node;

  if ((right < end) && !cmp( *right, *for_replace))
    for_replace = right;

  // Replace element wich breaks heap rule and recur on that element
  if (for_replace != node) {
    std::swap( *node, *for_replace);
    heapify(begin, end, for_replace, cmp);
  }
}

template <class Iter, class Comparator>
void make_heap(Iter first, Iter last, Comparator cmp) {
  // Heapify first half of input array
  auto middle = ((last - first) >> 1) - 1;
  for (auto iter = middle; middle >= 0; --middle)
    heapify(first, last, iter + first, cmp);
}

template <class Iter>
void make_heap(Iter first, Iter last) {
  typedef typename std::iterator_traits<Iter>::value_type T;
  make_heap(first, last, std::less<T>());
}

// Inserts the element at the position last-1 into the max heap
// defined by the range [first, last-1).
// Uses the given comparison function cmp.
template <class Iter, class Comparator>
void push_heap(Iter first, Iter last, Comparator cmp);

// This version of the function uses operator< to compare the elements
template <class Iter>
void push_heap(Iter first, Iter last) {
  typedef typename std::iterator_traits<Iter>::value_type T;
  push_heap(first, last, std::less<T>());
}

template <class Iter, class Comparator>
void pop_heap(Iter first, Iter last, Comparator cmp);

template <class Iter>
void pop_heap(Iter first, Iter last) {
  typedef typename std::iterator_traits<Iter>::value_type T;
  pop_heap(first, last, std::less<T>());
}


// #include <stddef.h>
// #include <vector>
//
// enum Type   { MAX, MIN };
// enum Order  { ASC, DESC };
// template<class T>
// class Heap {
//
//  typedef std::vector<T> Nodes;
//
//  public:
//   Heap(const T *array, size_t length, Type type = MAX);
//
//   static void sort(T *array, size_t length, Order ord = ASC);
//
//   T get_root_element();
//   T extract_root();
//
//   void update_key(int node, T key);
//
//   void insert(T key);
//   T    remove(int node);
//
//   void print();
//
//   Nodes get_nodes()  { return nodes; }
//   int   get_size()   { return size; }
//   int   get_length() { return this->nodes.size(); }
//   Type  get_type()   { return type; }
//   bool  empty()      { return this->size == 0; }
//
//  private:
//   Nodes nodes;
//   int   size;
//   Type  type;
//
//   void heapify(int node);
//   int  find_replace_index(int left, int right, int parent);
//   void build_heap();
// };
//
// #include "heap.tpp"

#endif
