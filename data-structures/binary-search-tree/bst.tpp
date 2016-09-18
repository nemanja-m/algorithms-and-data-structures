#ifdef __BST__

template <class Object>
void BinarySearchTree<Object>::insert_at(Node<Object> *node, Node<Object> **root) {
  // Empty tree
  if (*root == nullptr) {
    *root = node;
    return;
  }

  // Left subtree
  if (node->key <= (*root)->key) {
    if ( (*root)->left == nullptr) {
      (*root)->left = node;
      return;
    }

    insert_at(node, & (*root)->left);
  }
  // Right subtree
  else {
    if ( (*root)->right == nullptr) {
      (*root)->right = node;
      return;
    }

    insert_at(node, & (*root)->right);
  }
}

#endif
