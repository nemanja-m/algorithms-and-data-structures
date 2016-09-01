#include "vector.hpp"
#include "../../helpers/print.hpp"
#include "iostream"

#define COUNT 5

using namespace std;

int main(int argc, char const *argv[]) {

  cout << "\n----- Vector test -----\n";

  srand(time(0));
  Vector<int> vector;

  for (size_t i = 0; i < COUNT; i++) {
    vector.push_back(rand() % 100);
  }

  cout << "\nOriginal vector: " << endl;
  print(vector.begin(), vector.end());

  cout << "\n\n----------------------------\n\n";

  return 0;
}
