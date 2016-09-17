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

  vector<int> v(COUNT);
  gen_array(v, COUNT);
  cout << "\nVector:" << endl;
  print(v.begin(), v.end());
  make_heap(v.begin(), v.end());
  print(v.begin(), v.end());

  int *array = new int[COUNT];
  gen_array(array, COUNT);
  cout << "\nArray:" << endl;
  print(array, array + COUNT);
  make_heap(array, array + COUNT);
  print(array, array + COUNT);

  delete[] array;

  return 0;
}

template <class Type>
void gen_array(Type &array, size_t count) {
  srand(time(0));

  for (size_t i = 0; i < count; ++i)
    array[i] = rand() % 20;
}
