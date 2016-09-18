#ifndef __NODE__
#define __NODE__

template <class Object>
struct Node {
  int key;

  Node *parent;
  Node *left;
  Node *right;

  Object data;

  Node() { }
  Node(int k, const Object &d, Node *p = nullptr, Node *l = nullptr, Node *r = nullptr)
    : key(k), parent(p), left(l), right(r), data(d) { }

  ~Node() {
    if (parent != nullptr) delete parent;
    if (left != nullptr) delete left;
    if (right != nullptr) delete right;
  }
};

#endif
