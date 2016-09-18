#ifdef __BST__

template <class Object>
void BinarySearchTree<Object>::insert_at(Node<Object> *node, Node<Object> **root) {
  // Empty tree
  if (*root == nullptr) {
    *root = node;
    return;
  }
}

#endif
