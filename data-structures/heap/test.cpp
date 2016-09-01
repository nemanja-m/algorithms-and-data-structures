#include "heap.hpp"
#include "../../helpers/print.hpp"
#include "iostream"
#include "stdlib.h"

#define COUNT 9

using namespace std;

// Generate int array with 'count' random elements
int* gen_array(size_t count);

// Test for removing nodes from heap
template <typename T> void remove_test(Heap<T> &);

int main(int argc, char const *argv[]) {

  int *array = gen_array(COUNT);
  cout << "\nOriginal:" << endl;
  print(array, array + COUNT);

  Heap<int> heap(array, COUNT, MIN);
  cout << "\nPretty: " << endl;
  heap.print();

  for (size_t i = 0; i < COUNT; i++) {
    remove_test(heap);
  }

  delete[] array;

  return 0;
}

int* gen_array(std::size_t count) {
  int *array = new int[count];
  srand(time(0));

  for (size_t i = 0; i < count; i++) {
    array[i] = rand() % 20;
  }

  return array;
}

template <typename T> void remove_test(Heap<T> &heap) {
  cout << "\nRemoved element: " << heap.remove(0) << endl;
  heap.print();
}
