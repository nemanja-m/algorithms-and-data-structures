#ifndef __NODE__
#define __NODE__

template <class Object>
struct Node {
  Node *parent;
  Node *left;
  Node *right;

  Object *data;

  ~Node() {
    delete parent;
    delete left;
    delete right;
  }
};

#endif
