#include "two_sum.hpp"
#include "iostream"
#include "fstream"
#include "string"

#define LOWER_BOUND -10000
#define UPPER_BOUND 10000

using namespace std;

vector<int> load_array(string filename = "test_data/big_test.txt");

int main(int argc, const char *argv[]) {
  vector<int> array = load_array();

  size_t counter = 0;

  for (int target = LOWER_BOUND; target <= UPPER_BOUND; ++target) {
    if (TwoSum::count(array, target) != 0)
      ++counter;
  }

  cout << "\nNumber of targets in ["
       << LOWER_BOUND << ", " << UPPER_BOUND << "]: "
       << counter << endl << endl;

  return 0;
}

vector<int> load_array(string filename) {
  fstream file(filename);
  vector<int> array;

  int num;

  while (file >> num)
    array.push_back(num);

  return array;
}
