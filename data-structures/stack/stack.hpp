#ifndef __STACK__
#define __STACK__

#include "stddef.h"
#include "vector"

template <class Object>
class Stack {
  public:
    Stack() : _top(-1) { }

    void push(const Object &x) {
      array.push_back(x);
    }

    void push(Object && x) {
      array.push_back(std::move(x));
    }

    const Object& top() const {
      return array.back();
    }

  private:
    std::vector<Object> array;
    int _top;
};

#endif
