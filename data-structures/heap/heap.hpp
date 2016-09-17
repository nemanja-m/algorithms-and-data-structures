#ifndef __HEAP_H__
#define __HEAP_H__

#include "iterator"

#define PARENT(x) ( (x - 1) >> 1 )
#define LEFT(x)   ( (x << 1) + 1 )
#define RIGHT(x)  ( (x << 1) + 2 )

template <class Iter, class Comparator>
void make_heap(Iter first, Iter last, Comparator cmp) {

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

namespace {

  template <class Iter>
  Iter find_replace_node(Iter left, Iter right, Iter parent) {

  }
  
  template <class Iter>
  void heapify(Iter node) {
    Iter for_replace = find_replace_node(LEFT(node), RIGHT(node), node);

    if (for_replace != node) {
      std::swap( *node, *for_replace);
      heapify(for_replace);
    }
  }
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
