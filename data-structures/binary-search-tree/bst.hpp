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
    void remove(Node<Object> *node);
    void remove(int key) {
      Node<Object> *node = find(key);
      remove(node);
    }

    // Returns node with specific key or nullptr if node
    // doesn't exist in tree
    Node<Object> * find(int key) const { return find_at(key, root); }

    // Returns node with minimum key or nullptr is tree is empty
    Node<Object> * find_min() const {
      return root ? find_min_at(root) : nullptr;
    }

    // Returns node with maximim key or nullptr is tree is empty
    Node<Object> * find_max() const {
      return root ? find_max_at(root) : nullptr;
    }

    template <class Callback>
    void traverse_in_order(Node<Object> *root, Callback callback);

    template <class Callback>
    void traverse_pre_order(Node<Object> *root, Callback callback);

    template <class Callback>
    void traverse_post_order(Node<Object> *root, Callback callback);

    inline Node<Object> * get_root() const { return root; }

    void print(Node<Object> *node, int indent = 0) const;

  private:
    void insert_at(Node<Object> *node, Node<Object> **root, Node<Object> *parent = nullptr);
    Node<Object> * find_at(int key, Node<Object> *node) const;
    Node<Object> * find_min_at(Node<Object> *node) const;
    Node<Object> * find_max_at(Node<Object> *node) const;

    // Replaces 'node->parent' corresponding child with `replacement`
    void replace_in_parent(Node<Object> *node, Node<Object> *replacement = nullptr);

    Node<Object> *root;
};

#include "bst.tpp"

#endif
