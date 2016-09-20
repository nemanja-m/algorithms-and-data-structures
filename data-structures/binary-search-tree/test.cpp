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

  bst.print(bst.get_root());

  // Remove test
  cout << "After remove: " << endl;
  bst.remove(3);
  bst.print(bst.get_root());

  // Search tree test
  cout << "Node at 3: " << (bst.find(3) ? to_string(bst.find(3)->data) : "null") << endl;
  cout << "Node at 5: " << (bst.find(5) ? to_string(bst.find(5)->data) : "null") << endl;;
  cout << "Node at 7: " << (bst.find(7) ? to_string(bst.find(7)->data) : "null") << endl;
  cout << "Node at 10: " << (bst.find(10) ? to_string(bst.find(10)->data) : "null") << endl;

  // Min and max
  Node<int> *min = bst.find_min();
  cout << "Min node: " << (min ? to_string(min->key) : "null" ) << endl;

  Node<int> *max = bst.find_max();
  cout << "Max node: " << (max ? to_string(max->key) : "null" ) << endl;

  return 0;
}
