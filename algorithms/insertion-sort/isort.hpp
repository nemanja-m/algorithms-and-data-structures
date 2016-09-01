#ifndef __INSERTION_SORT__
#define __INSERTION_SORT__

#include "iterator"

template <typename Iter, typename Comparator>
void insertion_sort(Iter begin, Iter end, Comparator cmp) {
  for (auto i = begin + 1; i != end; i++) {
    auto j = i;
    while (j > begin && cmp( *j, *(j - 1) ) ) {
      std::swap( *(j - 1), *j );
      j--;
    }
  }
}

template <typename Iter>
void insertion_sort(Iter begin, Iter end) {
  typedef typename std::iterator_traits<Iter>::value_type T;
  insertion_sort(begin, end, std::less<T>());
}

#endif
