#ifdef __BST__

#include "queue"

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

template <class Object>
void BinarySearchTree<Object>::print(Node<Object> *n, int indent) {
  std::queue<Node<Object> * > queue;
  queue.push(n);

  while (!queue.empty()) {
    Node<Object> *node = queue.front();
    queue.pop();

    if (node != nullptr) {
      std::cout << node->key << " ";

      queue.push(node->left);
      queue.push(node->right);
    }
  }
}

#endif
