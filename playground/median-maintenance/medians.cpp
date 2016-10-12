#include "iostream"
#include "string"
#include "fstream"
#include "heap.hpp"

using namespace std;

vector<int> load_array(string filename = "median.txt") {
  ifstream file(filename);
  vector<int> ret;

  int temp;

  while (file >> temp)
    ret.push_back(temp);

  return ret;
}

int main(int argc, const char *argv[]) {

  Heap<int> min_heap;
  Heap<int> max_heap( [](int x, int y) { return x < y; } );

  int sum = 0;

  vector<int> array = load_array();

  // Initial push
  max_heap.push(array[0]);
  sum += array[0];

  for (size_t i = 1; i < array.size(); ++i) {

    if (array[i] > max_heap.top())
      min_heap.push(array[i]);
    else
      max_heap.push(array[i]);

    balance_heaps(min_heap, max_heap);

    // i / 2 for even medians
    // (i + 1) / 2 for odd
    int median = i + 1;
    size_t idx = (median % 2 == 0 ? median / 2 : (median + 1) / 2);

    if (idx <= max_heap.size())
      sum += max_heap.top();
    else
      sum += min_heap.top();
  }

  cout << "Sum of medians: " << sum << endl;
  cout << "Moduo 10000: " << sum % 10000 << endl;

  return 0;
}
