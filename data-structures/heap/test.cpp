#include "heap.hpp"
#include "../../helpers/print.hpp"
#include "iostream"
#include "stdlib.h"
#include "vector"

#define COUNT 5

using namespace std;

// Generate int array with 'count' random elements
template <class Type>
void gen_array(Type &type, size_t count);

int main(int argc, char const *argv[]) {

  // Make heap example

  int *array = new int[COUNT];
  gen_array(array, COUNT);
  cout << "\nArray:" << endl;
  print(array, array + COUNT);
  make_heap(array, array + COUNT);
  print(array, array + COUNT);

  vector<int> v(COUNT);
  gen_array(v, COUNT);
  cout << "\nVector:" << endl;
  print(v.begin(), v.end());
  make_heap(v.begin(), v.end());
  print(v.begin(), v.end());

  delete[] array;

  // Push heap example

  v.push_back(99);
  cout << "\nAfter push:" << endl;
  print(v.begin(), v.end());

  cout << "\nAfter heap push: " << endl;
  push_heap(v.begin(), v.end());
  print(v.begin(), v.end());
  cout << endl;

  return 0;
}

template <class Type>
void gen_array(Type &array, size_t count) {
  srand(time(0));

  for (size_t i = 0; i < count; ++i)
    array[i] = rand() % 20;
}
