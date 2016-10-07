#include "utils.hpp"

Node make_node(Array &v, size_t array_no) {
  Node ret(v.front(), array_no);
  v.erase(v.begin());
  return ret;
}

bool arrays_empty(const Arrays &arrays) {
  for (auto array : arrays)
    if (!array.empty())
      return false;

  return true;
}

Array make_array(size_t length) {
  Array temp;
  int start = rand() % 15 + 1;

  for (size_t i = 0; i < length; i++) {
    temp.push_back(start + i);
  }

  return temp;
}

Arrays make_arrays(size_t count) {
  Arrays temp;

  for (size_t i = 0; i < count; i++) {
    temp.push_back(make_array(rand() % 4 + 2));
  }

  return temp;
}

void print_arrays(const Arrays & arrs) {
  for (auto &array : arrs)
    print(array.begin(), array.end());
}
