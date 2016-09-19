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
    ~BinarySearchTree() {
      delete root;
    }

    void insert(Node<Object> *node) { insert_at(node, &root); }

    void remove(int key);
    void remove(Node<Object> *node) { remove(node->key); }

    Node<Object> * find(int key) const;

    Node<Object> * get_root() const { return root; }

    void print(Node<Object> *node, int indent = 0);
  private:
    void insert_at(Node<Object> *node, Node<Object> **root);
    Node<Object> *root;
};

#include "bst.tpp"

#endif
