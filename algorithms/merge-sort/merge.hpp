#ifndef __MERGE_SORT__
#define __MERGE_SORT__

#include "iterator"

template <class Iter, class Comparator>
void merge_sort(Iter begin, Iter end, Comparator cmp) {
  if (end - begin <= 1)
    return;

  typedef typename std::iterator_traits<Iter>::difference_type diff_t;
  diff_t center = (end - begin) / 2;

  merge_sort(begin, begin + center, cmp);
  merge_sort(begin + center, end, cmp);

  // Merge sorted subarrays
  typedef typename std::iterator_traits<Iter>::value_type Type;

  diff_t left_length  = center;
  diff_t right_length = end - (begin + center);

  Type *right = new Type[left_length];
  Type *left  = new Type[right_length];

  std::copy(begin, begin + center, left);
  std::copy(begin + center, end, right);

  Iter left_iter  = left;
  Iter right_iter = right;

  for (auto iter = begin; iter != end; iter++) {

    if (left_iter == left + left_length) // Left subarray merged
      *iter = *(right_iter++);
    else if (right_iter == right + right_length)
      *iter = *(left_iter++);
    else if (cmp( *right_iter, *left_iter) )
      *iter = *(right_iter++);
    else
      *iter = *(left_iter++);
  }

  delete[] right;
  delete[] left;
}

template <class Iter>
void merge_sort(Iter begin, Iter end) {
  typedef typename std::iterator_traits<Iter>::value_type T;
  merge_sort(begin, end, std::less<T>());
}

#endif
