#include "merge.hpp"
#include "../../helpers/helpers.hpp"
#include "iostream"

#define COUNT 10

using namespace std;

int main(int argc, char const *argv[]) {

  cout << "\n----- Merge sort test -----\n";

  int *array = new int[COUNT];
  srand(time(0));

  for (size_t i = 0; i < COUNT; i++) {
    array[i] = rand() % 100;
  }

  cout << "\nOriginal array:" << endl;
  print(array, COUNT);
  cout << endl;

  merge_sort(array, array + COUNT, greater<int>());
  cout << "Descending order:" << endl;
  print(array, COUNT);
  cout << endl;

  merge_sort(array, array + COUNT);
  cout << "Ascending order:" << endl;
  print(array, COUNT);
  cout << "\n----------------------------\n\n";

  delete[] array;
  
  return 0;
}
