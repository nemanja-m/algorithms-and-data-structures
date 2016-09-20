#ifdef __BST__

#include "queue"

template <class Object>
void BinarySearchTree<Object>::insert_at(Node<Object> *node, Node<Object> **root, Node<Object> *parent) {
  if (!*root) {
    *root = node;
    (*root)->parent = parent;
  }
  else if (node->key <= (*root)->key)
    insert_at(node, & (*root)->left, *root);
  else
    insert_at(node, & (*root)->right, *root);
}

template <class Object>
void BinarySearchTree<Object>::remove(Node<Object> *node) {
  // Node doesn't exist in tree
  if (!node) return;

  // Node have both child
  if (node->left && node->right) {
    Node<Object> *replacement = find_max_at(node->left);
    node->key = replacement->key;
    node->data = replacement->data;
    remove(replacement);
    return;
  }

  if (node->left)  // Node have only left child
    replace_in_parent(node, node->left);
  else if (node->right) // Node have only right child
    replace_in_parent(node, node->right);
  else  // Node doesn't have children
    replace_in_parent(node);

  node->left = node->right = nullptr;
  delete node;
}

template <class Object>
void BinarySearchTree<Object>::replace_in_parent(Node<Object> *node, Node<Object> *replacement) {
  if (node->parent) {
    if (node->parent->left == node)
      node->parent->left = replacement;

    if (node->parent->right == node)
      node->parent->right = replacement;

    if (replacement)
      replacement->parent = node->parent;
  }
}

template <class Object>
void BinarySearchTree<Object>::traverse_in_order(Node<Object> *root) {
  if (!root) return;

  traverse_in_order(root->left);
  std::cout << root->key << " ";
  traverse_in_order(root->right);
}

template <class Object>
void BinarySearchTree<Object>::traverse_pre_order(Node<Object> *root) {
  if (!root) return;

  std::cout << root->key << " ";
  traverse_pre_order(root->left);
  traverse_pre_order(root->right);
}

template <class Object>
void BinarySearchTree<Object>::traverse_post_order(Node<Object> *root) {
  if (!root) return;

  traverse_post_order(root->left);
  traverse_post_order(root->right);
  std::cout << root->key << " ";
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
