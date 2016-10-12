#include "iostream"
#include "algorithm"
#include "vector"
#include "string"
#include "fstream"

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
  vector<int> min_heap;
  vector<int> max_heap;

  vector<int> array = load_array();

  int sum = 0;

  return 0;
}
