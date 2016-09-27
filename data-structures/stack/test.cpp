#include "stack.hpp"
#include "iostream"

using namespace std;

int main(int argc, char** argv) {
  Stack<int> stack;

  cout << "\n-- Push --" << endl;
  cout << "> 43 pushed" << endl;
  cout << "> 23 pushed" << endl;
  stack.push(43);
  stack.push(23);

  cout << "\n-- Top/Pop --" << endl;

  cout << stack.top() << endl; stack.pop();
  cout << stack.top() << endl; stack.pop();

  cout << "\n-- Clear --" << endl;
  stack.clear();
  cout << "> stack cleared" << endl;

  cout << "\n-- Size --" << endl;
  cout << "Size: " << stack.size() << endl;

  return 0;
}
