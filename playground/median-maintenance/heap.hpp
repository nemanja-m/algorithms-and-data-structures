#ifndef __HEAP__
#define __HEAP__

#include "algorithm"
#include "functional"
#include "vector"

template <class Object>
class Heap {
  public:
    // Default is min heap
    Heap(std::function<bool (Object, Object)> cmp = std::greater<Object>())
      : _cmp(cmp) { }

    void push(const Object &x) {
      _array.push_back(x);
      std::push_heap(_array.begin(), _array.end(), _cmp);
    }

    void pop() {
      std::pop_heap(_array.begin(), _array.end(), _cmp);
      _array.pop_back();
    }

    const Object & top() const {
      return _array[0];
    }

    int size() const { return _array.size(); }
    bool empty() const { return size() == 0; }

    friend void balance_heaps(Heap &min, Heap &max) {
      if ( (min.size() - max.size()) > 1) {
        Object tmp = min.top();
        min.pop();
        max.push(tmp);
      }

      if ( (max.size() - min.size()) > 1) {
        Object tmp = max.top();
        max.pop();
        min.push(tmp);
      }
    }

  private:
    std::vector<Object> _array;
    std::function<bool (Object, Object) > _cmp;
};

#endif
