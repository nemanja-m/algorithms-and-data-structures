#include "qselect.hpp"
#include "../../helpers/print.hpp"
#include "iostream"
#include "algorithm"

#define COUNT 10

using namespace std;

int main(int argc, char const *argv[]) {

  cout << "\n-------- Quick select test --------\n";

  int *array = new int[COUNT];
  srand(time(0));

  for (size_t i = 0; i < COUNT; i++) {
    array[i] = rand() % 100;
  }

  cout << "\nOriginal array:" << endl;
  print(array, array + COUNT);
  cout << endl;

  for (size_t i = 0; i < COUNT / 2; i++) {
    cout << i << "th smallest element: "
         << *quick_select(array, array + COUNT, i) << endl;
  }

  cout << endl;

  for (size_t i = 0; i < COUNT / 2; i++) {
    cout << i << "th biggest element: "
         << *quick_select(array, array + COUNT, i, greater<int>()) << endl;
  }

  cout << endl;

  cout << "Sorted:" << endl;
  std::sort(array, array + COUNT);
  print(array, array + COUNT);
  cout << "\n----------------------------------\n\n";

  delete[] array;

  return 0;
}
