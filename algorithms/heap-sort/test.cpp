#include "hsort.hpp"
#include "iostream"
#include "../../helpers/helpers.hpp"

#define COUNT 10

using namespace std;

int main(int argc, char const *argv[]) {
  cout << "\n----- Heap sort test -----\n";

  srand(time(0));
  int *array = new int[COUNT];

  for (size_t i = 0; i < COUNT; i++) {
    array[i] = rand() % 100;
  }

  cout << "\nOriginal array:" << endl;
  print(array, COUNT);

  heap_sort(array, array + COUNT);
  cout << "\nAscending order:" << endl;
  print (array, COUNT);

  heap_sort(array, array + COUNT, greater<int>());
  cout << "\nDescending order:" << endl;
  print(array, COUNT);
  cout << "\n---------------------------\n\n";

  delete[] array;

  return 0;
}
