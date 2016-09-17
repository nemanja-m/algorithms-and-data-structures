#ifndef __HEAP_H__
#define __HEAP_H__

#include "iterator"

// Following functions are available in this compilation unit only
namespace {
  template <class Iter>
  Iter get_left(Iter begin, Iter node) {
    auto idx = std::distance(begin, node);
    return begin + (idx << 1) + 1;
  }

  template <class Iter>
  Iter get_right(Iter begin, Iter node) {
    auto idx = std::distance(begin, node);
    return begin + (idx << 1) + 2;
  }

  template <class Iter>
  Iter parent(Iter begin, Iter node) {
    auto idx = std::distance(begin, node);
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
}

// Rearranges the elements in the range [first,last)
// in such a way that they form a heap.
// The elements are compared using 'cmp' function
// The element with the highest value is an element for which this would return
// false when compared to every other element in the range.
template <class Iter, class Comparator>
void make_heap(Iter first, Iter last, Comparator cmp) {
  // Heapify first half of input array
  auto middle = (std::distance(first, last) >> 1) - 1;
  for (auto iter = middle; iter >= 0; --iter) {
    heapify(first, last, iter + first, cmp);
  }
}

// This version of the function uses operator< to compare the elements
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

#endif
