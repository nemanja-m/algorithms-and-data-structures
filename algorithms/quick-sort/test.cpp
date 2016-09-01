#include "qsort.hpp"
#include "../../helpers/print.hpp"
#include "vector"

#define COUNT 10

using namespace std;

int main(int argc, char const *argv[]) {

  cout << "\n-------- Quick sort test --------\n";

  srand(time(0));
  vector<int> array;

  for (size_t i = 0; i < COUNT; i++) {
    array.push_back(rand() % 100);
  }

  cout << "\nOriginal array: " << endl;
  print(array.begin(), array.end());
  cout << endl;

  cout << "\nAscending order: " << endl;
  qsort(array.begin(), array.end());
  print(array.begin(), array.end());
  cout << endl;

  std::cout << "Descending order: " << std::endl;
  qsort(array.begin(), array.end(), greater<int>());
  print(array.begin(), array.end());
  cout << "\n----------------------------------\n\n";

  return 0;
}
