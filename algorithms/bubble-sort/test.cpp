#include "bsort.hpp"
#include "../../helpers/helpers.hpp"
#include "iostream"

#define COUNT 10

using namespace std;

int main(int argc, char const *argv[]) {

  cout << "\n----- Bubble sort test -----\n\n";

  int *array = new int[COUNT];
  srand(time(0));

  for (size_t i = 0; i < COUNT; i++) {
    array[i] = rand() % 100;
  }

  cout << "\nOriginal array:" << endl;
  print(array, 10);
  cout << endl;

  bubble_sort(array, array + 10, [] (const int x, const int y) { return x > y; });
  cout << "Descending order:" << endl;
  print(array, 10);
  cout << endl;

  bubble_sort(array, array + 11);
  cout << "Ascending order:" << endl;
  print(array, 10);
  cout << "\n-----------------------------\n\n";

  return 0;
}
