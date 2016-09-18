#ifndef __NODE__
#define __NODE__

template <class Object>
struct Node {
  Node *parent;
  Node *left;
  Node *right;

  Object *data;
};

#endif
