#ifndef __VECTOR__
#define __VECTOR__

#include "algorithm"

template <class Object>
class Vector {
  public:
    explicit Vector( size_t init_size = 0 ) : _size(init_size)
    {
      _capacity = init_size <= INITIAL_CAPACITY ?
          INITIAL_CAPACITY : next_power(init_size);

     _objects = new Object[_capacity];
    }

    Vector(const Vector & rhs)
      : _size(rhs._size), _capacity(rhs._capacity)
    {
      _objects = new Object[_capacity];
      std::copy(rhs._objects, rhs._objects + rhs._size, _objects);
    }

    Vector(const Vector && rhs)
      : _size(rhs._size), _capacity(rhs._capacity), _objects(rhs._objects)
    {
      rhs._objects  = nullptr;
      rhs._size     = 0;
      rhs._capacity = 0;
    }

    Vector & operator= (const Vector & rhs) {
      Vector copy = rhs;
      std::swap(*this, copy);
      return *this;
    }

    Vector & operator= (Vector && rhs) {
      std::swap(_capacity, rhs._capacity);
      std::swap(_size, rhs._size);
      std::swap(_objects, rhs._objects);
      return *this;
    }

    ~Vector() {
      delete [] _objects;
    }

    void resize(size_t new_size) {
      if (new_size > _capacity)
        reserve(next_power(new_size));

      _size = new_size;
    }

    void reserve(size_t new_capacity) {
      if (new_capacity < _size)
        return;

      _capacity = new_capacity;
      Object *new_objects = new Object[_capacity];

      for (size_t i = 0; i < _size; i++)
        new_objects[i] = std::move(_objects[i]);

      std::swap(_objects, new_objects);
      delete[] new_objects;
    }

    Object & operator[] (int idx) {
      return _objects[idx];
    }

    const Object & operator[] (int idx) const {
      return _objects[idx];
    }

    void push_back(const Object & obj) {
      if (_size == _capacity)
        reserve(next_power(_size + 1));

      _objects[_size++] = obj;
    }

    void push_back(Object && obj) {
      if (_size == _capacity)
        reserve(next_power(_size + 1));

      _objects[_size++] = std::move(obj);
    }

    void pop_back() { _size--; }

    const Object & back() const { return _objects[_size - 1]; }

    typedef Object * iterator;
    typedef const Object * const_iterator;

    iterator begin() { return &_objects[0]; }
    iterator end() { return &_objects[_size]; }

    const_iterator begin() const { return &_objects[0]; }
    const_iterator end() const { return &_objects[_size]; }

    static const size_t INITIAL_CAPACITY = 16;

    size_t size() const { return _size; }
    size_t capactiy() const { return _capacity; }
    bool   empty() const { return _size == 0; }
  private:
    size_t   _size;
    size_t   _capacity;
    Object * _objects;

    // Returns next power of 2
    size_t next_power(size_t num) {
      return (size_t) pow(2, ceil( log(num) / log(2) ) );
    }
};

#endif
