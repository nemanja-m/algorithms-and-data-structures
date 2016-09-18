#ifndef __BST__
#define __BST__

#include "node.hpp"

template <class Object>
class BinarySearchTree {

  BinarySearchTree() : root(nullptr) { }
  ~BinarySearchTree() {
    delete root;
  }

  private:
    Node<Object> *root;
};

#endif
