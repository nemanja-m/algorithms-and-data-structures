#include "list.hpp"
#include "iostream"

using namespace std;

int main(int _argc, char** _argv) {

  List<int> list;

  cout << "\n-- Push back --" << endl;
  list.push_back(42);
  list.push_back(23);

  cout << "Back: " << list.back() << endl;
  cout << "Front: " << list.front() << endl;

  cout << "\n-- Push front --" << endl;
  srand(time(0));
  for (int i = 1; i < 10; i++)
    list.push_front(i);

  for (auto iter = list.begin(); iter != list.end(); iter++)
    cout << *iter << " ";

  cout << "\n\n-- Clear list --" << endl;
  list.clear();
  cout << "Size: " << list.size() << endl << endl;

  return 0;
}
