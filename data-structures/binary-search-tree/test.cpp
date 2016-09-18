#include "bst.hpp"
#include "iostream"

using namespace std;

int main(int argc, char const *argv[]) {
  int data = 42;

  BinarySearchTree<int> bst;
  bst.insert(new Node<int>(5, data));
  bst.insert(new Node<int>(3, data));
  bst.insert(new Node<int>(7, data));

  auto root = bst.get_root();
  cout << root->key << endl;
  cout << root->left->key << endl;
  cout << root->right->key << endl;

  return 0;
}
