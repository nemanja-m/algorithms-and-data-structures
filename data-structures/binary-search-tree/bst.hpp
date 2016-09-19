#ifndef __BST__
#define __BST__

#include "node.hpp"
#include "iostream"
#include "iomanip"

template <class Object>
class BinarySearchTree {
  public:
    BinarySearchTree() : root(nullptr) { }
    BinarySearchTree(Node<Object> *r) : root(r) { }
    ~BinarySearchTree() { delete root; }

    // Insertes node in correct place in tree
    // so the binary search tree property is satisfied
    void insert(Node<Object> *node) { insert_at(node, &root); }

    // Removes node from tree if it exists
    void remove(int key);
    void remove(Node<Object> *node) { remove(node->key); }

    // Returns node with specific key or nullptr if node
    // doesn't exist in tree
    Node<Object> * find(int key) { return find_at(key, root); }

    // Returns node with minimum key or nullptr is tree is empty
    Node<Object> * find_min() {
      return root ? find_min_at(root) : nullptr;
    }

    Node<Object> * get_root() const { return root; }

    void print(Node<Object> *node, int indent = 0);

  private:
    void insert_at(Node<Object> *node, Node<Object> **root);
    Node<Object> * find_at(int key, Node<Object> *node);
    Node<Object> * find_min_at(Node<Object> *node);

    Node<Object> *root;
};

#include "bst.tpp"

#endif
