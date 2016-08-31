#ifndef __BUBBLE_SORT__
#define __BUBBLE_SORT__

#include "iterator"

template<class Iter, class Comparator>
void bubble_sort(Iter begin, Iter end, Comparator cmp) {
  for (auto i = begin; i != (end - 1); i++) {
    for (auto j = i + 1; j != end; j++) {
      if (cmp(*j, *i))
        std::swap(*i, *j);
    }
  }
}

template<class Iter>
void bubble_sort(Iter begin, Iter end) {
  typedef typename std::iterator_traits<Iter>::value_type T;
  bubble_sort(begin, end, std::less<T>());
}

#endif
