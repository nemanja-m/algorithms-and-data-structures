#include "bst.hpp"
#include "iostream"

using namespace std;

int main(int argc, char const *argv[]) {
  int data = 42;

  BinarySearchTree<int> bst;

  // Insert test
  bst.insert(new Node<int>(5, data));
  bst.insert(new Node<int>(3, ++data));
  bst.insert(new Node<int>(7, ++data));
  bst.insert(new Node<int>(2, ++data));
  bst.insert(new Node<int>(4, ++data));

  auto root = bst.get_root();

  bst.print(root);

  // Remove test
  cout << "\nAfter remove: " << endl;
  bst.remove(3);
  bst.print(root);

  // Search tree test
  cout << "\nNode at 3: " << (bst.find(3) ? to_string(bst.find(3)->data) : "null") << endl;
  cout << "Node at 5: " << (bst.find(5) ? to_string(bst.find(5)->data) : "null") << endl;;
  cout << "Node at 7: " << (bst.find(7) ? to_string(bst.find(7)->data) : "null") << endl;
  cout << "Node at 10: " << (bst.find(10) ? to_string(bst.find(10)->data) : "null") << endl;

  // Min and max
  Node<int> *min = bst.find_min();
  cout << "\nMin node: " << (min ? to_string(min->key) : "null" ) << endl;

  Node<int> *max = bst.find_max();
  cout << "Max node: " << (max ? to_string(max->key) : "null" ) << endl;

  // Traversal
  cout << "\nIn-order:" << endl;
  bst.traverse_in_order(root);
  cout << endl;

  cout << "\nPre-order:" << endl;
  bst.traverse_pre_order(root);
  cout << endl;

  cout << "\nPost-order:" << endl;
  bst.traverse_post_order(root);
  cout << endl;

  return 0;
}
