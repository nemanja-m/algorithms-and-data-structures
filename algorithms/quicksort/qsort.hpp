#ifndef __QSORT__
#define __QSORT__

template<class Iter, class Compare>
void qsort(Iter first, Iter last, Compare cmp);

template<class Iter>
void qsort(Iter first, Iter last);

#include "qsort.tpp"

#endif
