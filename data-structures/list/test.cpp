#include "list.hpp"
#include "iostream"

using namespace std;

int main(int _argc, char** _argv) {

  List<int> list;
  list.push_back(42);
  list.push_back(23);

  cout << list.back() << endl;

  return 0;
}
