#ifdef __BST__

#include "queue"

template <class Object>
void BinarySearchTree<Object>::insert_at(Node<Object> *node, Node<Object> **root) {
  if (*root == nullptr) {
    *root = node;
    return;
  }

  if (node->key <= (*root)->key)
    insert_at(node, & (*root)->left);
  else
    insert_at(node, & (*root)->right);
}

template <class Object>
Node<Object> * BinarySearchTree<Object>::find_at(int key, Node<Object> *node) const {
  if (node == nullptr || node->key ==key)
    return node;

  if (key <= node->key)
    return find_at(key, node->left);
  else
    return find_at(key, node->right);
}

template <class Object>
Node<Object> * BinarySearchTree<Object>::find_min_at(Node<Object> *node) const {
  while (node->left)
    node = node->left;

  return node;
}

template <class Object>
Node<Object> * BinarySearchTree<Object>::find_max_at(Node<Object> *node) const {
  while (node->right)
    node = node->right;

  return node;
}

template <class Object>
void BinarySearchTree<Object>::print(Node<Object> *n, int indent) const {
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

  std::cout << std::endl;
}

#endif
