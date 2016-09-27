#ifndef __STACK__
#define __STACK__

#include "stddef.h"
#include "vector"

template <class Object>
class Stack {
  public:
    void push(const Object &x) {
      array.push_back(x);
    }

    void push(Object && x) {
      array.push_back(std::move(x));
    }

    const Object& top() const {
      return array.back();
    }

    void pop() {
      array.pop_back();
    }

    void clear() {
      array.clear();
    }

    size_t size() const {
      return array.size();
    }

  private:
    std::vector<Object> array;
};

#endif
