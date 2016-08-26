#ifdef __HEAP_H__

#include "../../helpers/helpers.hpp"
#include "stdexcept"
#include "math.h"
#include "iostream"
#include "iomanip"
#include "limits.h"
#include "utility"

#define PARENT(x) ( (x - 1) >> 1 )
#define LEFT(x)   ( (x << 1) + 1 )
#define RIGHT(x)  ( (x << 1) + 2 )

#define COMPARE(x, y) (this->type == MAX ? x > y : x < y)

template<class T>
int Heap<T>::find_replace_index(int left, int right, int parent) {
  int replace_idx;

  if ((left < this->size) && COMPARE(this->nodes[left], this->nodes[parent])) {
      replace_idx = left;
  } else {
      replace_idx = parent;
  }

  if ((right < this->size) && COMPARE(this->nodes[right], this->nodes[replace_idx])) {
      replace_idx = right;
  }

  return replace_idx;
}

template<class T>
void Heap<T>::heapify(int idx) {
  int for_replace = find_replace_index(LEFT(idx), RIGHT(idx), idx);

  if (for_replace != idx) {
      std::swap(this->nodes[idx], this->nodes[for_replace]);
      heapify(for_replace);
  }
}

template<class T>
void Heap<T>::build_heap() {
  for (int i = get_length() / 2 - 1; i >= 0; i--)
    this->heapify(i);
}

template<class T>
Heap<T>::Heap(const T *array, size_t length, Type type) {
  this->size = length;
  this->nodes = Nodes(array, array + length);
  this->type = type;

  build_heap();
}

template<class T>
T Heap<T>::get_root_element() {
  if (this->size == 0)
    throw std::runtime_error("Heap empty");

  return this->nodes[0];
}

template<class T>
T Heap<T>::extract_root() {
  if (this->size == 0)
    throw std::runtime_error("Heap empty");

  int root = get_root_element();
  this->nodes[0] = this->nodes[--this->size];
  this->nodes.erase(this->nodes.begin());
  heapify(0);

  return root;
}


template<class T>
void Heap<T>::update_key(int node, T key) {
  if (this->type == MAX && this->nodes[node] > key)
    throw std::runtime_error("New key is smaller than original!");

  if (this->type == MIN && this->nodes[node] < key)
    throw std::runtime_error("New key is bigger than original!");

  this->nodes[node] = key;

  while (node > 0 && COMPARE(this->nodes[node], this->nodes[PARENT(node)]) ) {
    std::swap(this->nodes[node], this->nodes[PARENT(node)]);
    node = PARENT(node);
  }
}

template<class T>
void Heap<T>::insert(T key) {
  // int limit = this->type == MAX ? INT_MIN : INT_MAX;
  // this->nodes.push_back(limit);
  // update_key(this->size++, key);
  this->nodes.push_back(key);
  this->size++;
  int node = get_length() - 1;
  while (node > 0 && COMPARE(this->nodes[node], this->nodes[PARENT(node)]) ) {
    std::swap(this->nodes[node], this->nodes[PARENT(node)]);
    node = PARENT(node);
  }
}

template<class T>
T Heap<T>::remove(int node) {
  if (node >= this->size)
    throw std::runtime_error("Index out of bounds");

  T ret = this->nodes[node];
  std::swap(this->nodes[node], this->nodes[--this->size]);
  this->nodes.pop_back();

  heapify(node);

  return ret;
}

template<class T>
void Heap<T>::sort(T *array, size_t length, Order ord) {
  Type type = (ord == ASC ? MAX : MIN);
  Heap<T> temp(array, length, type);

  for (size_t i = temp.get_length() - 1; i > 0; i--) {
    std::swap(temp.nodes[i], temp.nodes[0]);
    temp.size--;
    temp.heapify(0);
  }

  std::copy(temp.nodes.begin(), temp.nodes.end(), array);
}

template<class T>
void Heap<T>::print() {
  if (this->nodes.empty()) {
    std::cout << "Heap empty!" << std::endl;
    return;
  }

  size_t height = ceil(log2(this->size + 1) - 1);
  int idx = 0;
  int indent = pow(2, height) * 2;
  std::string spaces(indent, ' ');

  for (size_t i = 0; i <= height; i++) {
    size_t elems = pow(2, i);
    std::cout << std::setw(indent *= 0.8);
    for (size_t j = 0; j < elems; j++) {
      std::cout << this->nodes[idx++] << spaces;

      if (idx == this->size)
        break;
    }
    spaces.resize(indent *= 0.85);
    std::cout << std::endl;
  }
}

#endif
