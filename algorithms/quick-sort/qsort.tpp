#ifdef __QSORT__

#include "iterator"
#include "iostream"
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
    if (cmp( *(first + i), *first ) ) {                   // Smaller than pivot
      std::swap( *(first + i), *(first + idx++ ) );
    }
  }

  std::swap( *first, *(first + idx - 1) );          // Place pivot on right spot

  return idx - 1;   // Return index of pivot element after partitioning
}

template <class Iter, class Compare>
void qsort(Iter first, Iter last, Compare cmp) {
  if (first == last)
    return;

  typedef typename std::iterator_traits<Iter>::difference_type diff_t;
  diff_t count = last - first;

  size_t pivot = choose_pivot(0, count -1);
  size_t split_idx = partition(pivot, first, count, cmp);
  qsort(first, first + split_idx, cmp);
  qsort(first + split_idx + 1, last, cmp);
}

template <class Iter>
void qsort(Iter first, Iter last) {
  typedef typename std::iterator_traits<Iter>::value_type T;
  qsort(first, last, std::less<T>());
}

#endif
