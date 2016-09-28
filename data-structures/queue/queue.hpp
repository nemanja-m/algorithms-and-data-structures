#ifndef __QUEUE__
#define __QUEUE__

#define INIT_CAPACITY 16

#include "stddef.h"
#include "math.h"

template <class Object>
class Queue {
  public:
    Queue(size_t capacity = INIT_CAPACITY) : _size(0) {
      _capacity = capacity <= INIT_CAPACITY ?
        INIT_CAPACITY : next_power(capacity);

      _array = new Object[_capacity];
    }

    ~Queue() {
      delete[] _array;
    }

    void enqueue(const Object & x) {

    }

    void enqueue(Object && x) {

    }

    Object & dequeue() {

    }

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
};

#endif
