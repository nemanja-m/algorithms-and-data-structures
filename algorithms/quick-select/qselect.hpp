#ifndef __QUICK_SELECT__
#define __QUICK_SELECT__

#include "iterator"
#include "random"

size_t choose_pivot(size_t range_from, size_t range_to) {
  std::random_device                    rand_dev;
  std::mt19937                          generator(rand_dev());
  std::uniform_int_distribution<size_t> distr(range_from, range_to);

  return distr(generator);
}

template <class Iter, class Compare>
size_t partition(size_t pivot, Iter first, size_t count, Compare cmp) {
  std::swap(*first, *(first + pivot));

  size_t idx = 1; // Begining of elements bigger than pivot

  for (size_t i = 1; i < count; i++) {
    if (cmp( *(first + i), *first ) ) { // Smaller than pivot
      std::swap( *(first + i), *(first + idx++ ) );
    }
  }

  std::swap( *first, *(first + idx - 1) );  // Place pivot on right spot

  return idx - 1; // Return index of pivot element after partitioning
}

template <class Iter, class Compare>
Iter quick_select(Iter begin, Iter end, size_t k, Compare cmp) {
  if (end - begin == 1)
    return begin;

  typedef typename std::iterator_traits<Iter>::difference_type diff_t;
  diff_t count = end - begin;

  size_t pivot = choose_pivot(0, count -1);
  size_t pivot_idx = partition(pivot, begin, count, cmp);

  if (pivot_idx == k)
    return begin + pivot_idx;
  else if (pivot_idx < k)
    return quick_select(begin + pivot_idx + 1, end, k - pivot_idx - 1, cmp);
  else
    return quick_select(begin, begin + pivot_idx, k, cmp);
}

template <class Iter>
Iter quick_select(Iter begin, Iter end, size_t k) {
  typedef typename std::iterator_traits<Iter>::value_type T;
  return quick_select(begin, end, k, std::less<T>());
}

#endif
