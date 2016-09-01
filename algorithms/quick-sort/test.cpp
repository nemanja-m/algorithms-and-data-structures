#include "qsort.hpp"
#include "../../helpers/helpers.hpp"
#include "vector"

#define COUNT 20

using namespace std;

int main(int argc, char const *argv[]) {

  cout << "\n----- Quick sort test -----\n";

  srand(time(0));
  vector<int> array;

  for (size_t i = 0; i < COUNT; i++) {
    array.push_back(rand() % 100);
  }

  cout << "\nOriginal array: " << endl;
  print(array);
  cout << endl;

  qsort(array.begin(), array.end());

  cout << "\nAscending order: " << endl;
  print(array);
  cout << endl;

  qsort(array.begin(), array.end(), greater<int>());

  std::cout << "Descending order: " << std::endl;
  print(array);
  cout << "\n----------------------------\n\n";

  return 0;
}
