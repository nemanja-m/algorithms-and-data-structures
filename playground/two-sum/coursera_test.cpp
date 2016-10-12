#include "iostream"
#include "fstream"
#include "string"
#include "coursera.hpp"

using namespace std;

vector<int64_t> load_array(string filename = "test_data/big_test.txt");

int main(int argc, const char *argv[]) {
  vector<int64_t> array = load_array();

  cout << "\nNumber of targets in ["
       << Coursera::LOWER_BOUND << ", " << Coursera::UPPER_BOUND << "]: "
       << Coursera::count(array) << "\n\n";

  return 0;
}

vector<int64_t> load_array(string filename) {
  fstream file(filename);
  vector<int64_t> array;

  int64_t num;

  while (file >> num)
    array.push_back(num);

  return array;
}
