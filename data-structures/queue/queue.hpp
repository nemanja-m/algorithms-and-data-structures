#ifndef __QUEUE__
#define __QUEUE__

#define INIT_CAPACITY 16

#include "stddef.h"
#include "math.h"
#include "utility"
#include "stdexcept"

template <class Object>
class Queue {
  public:
    Queue(size_t capacity = INIT_CAPACITY) : _size(0) {
      _capacity = capacity <= INIT_CAPACITY ?
        INIT_CAPACITY : next_power(capacity);

      _array = new Object[_capacity];
      _front = 0;
      _back = -1;
    }

    ~Queue() {
      delete[] _array;
    }

    void enqueue(const Object & x) {
      check_capacity();
      _array[++_back] = x;
      ++_size;
    }

    void enqueue(Object && x) {
      check_capacity();
      _array[++_back] = std::move(x);
      ++_size;
    }

    Object & dequeue() {
      if (empty())
        throw std::runtime_error("Queue empty");

      --_size;
      Object &ret = _array[_front++];

      // Queue empty
      if (_front > _back) {
        _front = 0;
        _back = -1;
      }

      return ret;
    }

    void clear() {
      _front = 0;
      _back = -1;
      _size = 0;
      delete[] _array;

      _array = new Object[INIT_CAPACITY];
    }

    bool empty() const { return _size == 0; }
    size_t size() const { return _size; }
    size_t capacity() const { return _capacity; }

  private:
    Object * _array;
    size_t _size;
    size_t _capacity;
    int _front;
    int _back;

    // Returns next power of 2 greater than 'num'
    size_t next_power(int num) {
      return (size_t) pow(2, ceil( log(num) / log(2) ));
    }

    void check_capacity() {
      // Queue is full, we need more space
      if ((_back + 1) == _capacity) {
        size_t space = _size < (INIT_CAPACITY - 1) ?
          INIT_CAPACITY : next_power(_size + 1);

        reshape(space);
      }
    }

    // Allocates more space than previous array capacity
    // and copies all elements from original array to new one
    void reshape(size_t space) {
      if (space <= _size)
        return;

      Object * temp = new Object[space];
      _capacity = space;

      for (size_t i = _front, k = 0; i <= _back; i++)
        temp[k++] = std::move(_array[i]);

      std::swap(temp, _array);
      delete[] temp;

      _back = _size - 1;
      _front = 0;
    }
};

#endif
