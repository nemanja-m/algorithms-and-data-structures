#include "qsort.hpp"
#include "../../helpers/helpers.hpp"
#define COUNT 20
#include "vector"

int main(int argc, char const *argv[]) {

  srand(time(0));
  std::vector<int> array;

  for (size_t i = 0; i < COUNT; i++) {
    array.push_back(rand() % 10 + 1);
  }

  std::cout << "\nOriginal: " << std::endl;
  print(array);

  qsort(array.begin(), array.end());

  std::cout << "\nSorted ascending: " << std::endl;
  print(array);

  qsort(array.begin(), array.end(), std::greater<int>());

  std::cout << "\nSorted descending: " << std::endl;
  print(array);

  return 0;
}
