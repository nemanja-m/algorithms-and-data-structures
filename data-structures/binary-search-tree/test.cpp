#include "bst.hpp"
#include "iostream"

using namespace std;

int main(int argc, char const *argv[]) {
  int data = 42;
  Node<int> *node = new Node<int>(1, data);

  BinarySearchTree<int> bst;
  bst.insert(node);

  cout << bst.get_root()->key << endl;

  return 0;
}
