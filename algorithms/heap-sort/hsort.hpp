#ifndef __HEAP_SORT__
#define __HEAP_SORT__

#include "iterator"
#include "algorithm"

template<class Iter, class Comparator>
void heap_sort(Iter begin, Iter end, Comparator cmp) {
  if (begin == end)
    return;

  typedef typename std::iterator_traits<Iter>::difference_type diff_t;
  diff_t count = end - begin;

  std::make_heap(begin, end, cmp);

  for (diff_t i = 0; i < count - 1; i++) {
    std::pop_heap(begin, end - i, cmp);
  }
}

template<class Iter>
void heap_sort(Iter begin, Iter end) {
  typedef typename std::iterator_traits<Iter>::value_type T;
  heap_sort(begin, end, std::less<T>());
}

#endif
