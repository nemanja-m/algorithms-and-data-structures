#ifndef __SELECTION_SORT__
#define __SELECTION_SORT__

#include "iterator"
#include "algorithm"

template<class Iter, class Comparator>
void selection_sort(Iter begin, Iter end, Comparator cmp) {
  for (auto i = begin; i != end - 1; i++) {
    Iter min = std::min_element(i, end, cmp);
    std::swap(*i, *min);
  }
}

template<class Iter>
void selection_sort(Iter begin, Iter end) {
  typedef typename std::iterator_traits<Iter>::value_type T;
  selection_sort(begin, end, std::less<T>());
}

#endif
