#ifndef __HEAP_H__
#define __HEAP_H__

#include <stddef.h>
#include <vector>

enum Type   { MAX, MIN };
enum Order  { ASC, DESC };

// TODO
// Napraviti da klasa 'template' klasa
// Heap::sort treba da prima pocetak i kraj niza koji se sortira
// a duzina ce se sracunati na osnovu toga.
// Takodje treba proslijetiid funkciju za uporedjivanje elemenata
// niza koji se sortira, ako se ne proslijedi funkcija podrazumijeva se
// da su u pitanju osnovni tipovi i koriste se obicni relacioni operatori

template<class T>
class Heap {

 typedef std::vector<T> Nodes;

 public:
  Heap(const T *array, size_t length, Type type = MAX);

  static void sort(T *array, size_t length, Order ord = ASC);

  T get_root_element();
  T extract_root();

  void update_key(int node, T key);

  void insert(T key);
  T    remove(int node);

  void print();

  Nodes get_nodes()  { return nodes; }
  int   get_size()   { return size; }
  int   get_length() { return this->nodes.size(); }
  Type  get_type()   { return type; }
  bool  empty()      { return this->size == 0; }
 private:
  Nodes nodes;
  int   size;
  Type  type;

  void heapify(int node);
  int  find_replace_index(int left, int right, int parent);
  void build_heap();
};

#include "heap.tpp"

#endif
