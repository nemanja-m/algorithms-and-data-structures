#ifndef __PRINT__
#define __PRINT__

#include "iostream"

template <class Iter>
void print(Iter begin, Iter end) {
  std::cout << "[ ";

  for (auto iter = begin; iter != end; iter++)
    std::cout << *iter << " ";

  std::cout << "]" << std::endl;
}

#endif
