#include "two_sum.hpp"
#include "iostream"

using namespace std;

int main(int argc, const char *argv[]) {

  vector<int> array = {1, 1, 2, -4, 0, 10, 5};

  int target = 6;

  cout << "Target: " << target << endl;
  cout << "Number of pairs: " << TwoSum::count(array, target) << endl;

  return 0;
}
