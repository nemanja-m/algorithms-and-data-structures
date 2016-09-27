#ifndef __LIST__
#define __LIST__

#include "utility"
#include "stddef.h"
#include "stdexcept"

template <class Object>
class List {
  private:
    struct Node {
      Object data;
      Node  *next;
      Node  *prev;

      Node(const Object & obj = Object(), Node * p = nullptr,
          Node * n = nullptr)
        : data(obj), next(n), prev(p) { }

      Node(Object && obj, Node * p = nullptr, Node * n = nullptr)
        : data(obj), next(n), prev(p) { }
    };

  public:
    class  const_iterator {
      public:
        const_iterator() : current(nullptr), list(nullptr) {}

        const Object & operator* () const { return retreive(); }

        const_iterator & operator++ () {
          current = current->next;
          return *this;
        }

        const_iterator operator++ (int) {
          const_iterator old = *this;
          ++(*this);
          return old;
        }

        const_iterator operator-- () {
          current = current->prev;
          return *this;
        }

        const_iterator operator-- (int) {
          const_iterator old = *this;
          --(*this);
          return old;
        }

        bool operator== (const const_iterator & rhs) const {
          return current == rhs.current;
        }

        bool operator!= (const const_iterator & rhs) const {
          return current != rhs.current;
        }

        // Throws an exception if any assertion isn't met
        void assert_is_valid() {
          if (current == nullptr || list == nullptr || current == list->_head)
            throw std::out_of_range("Iterator out of range");
        }

      protected:
        Node *current;
        const List<Object> *list;

        Object & retreive() { return current->data; }

        const_iterator(const List<Object> &l, Node *p) : current(p), list(&l) { }

        friend class List<Object>;
    };

    class  iterator : public const_iterator {
      public:
        iterator() {}

        Object & operator* () { return const_iterator::retreive(); }
        const Object & operator* () const {
          return const_iterator::operator*();
        }

        iterator & operator++ () {
          this->current = this->current->next;
          return *this;
        }

        iterator operator++ (int) {
          iterator old = *this;
          ++(*this);
          return old;
        }

        iterator operator-- () {
          this->current = this->current->prev;
          return *this;
        }

        iterator operator-- (int) {
          iterator old = *this;
          --(*this);
          return old;
        }

      protected:
        iterator(const List<Object> &l, Node *p) : const_iterator(l, p) { }

        friend class List<Object>;
    };

  public:
    List() { init(); }

    List(const List & rhs) {
      init();
      for (auto &x : rhs)
        push_back(x);
    }

    List(List && rhs)
      : _size(rhs._size), _head(rhs._head), _tail(rhs._tail)
    {
      rhs._size = 0;
      rhs._head = nullptr;
      rhs._tail = nullptr;
    }

    List & operator= (const List & rhs) {
      List copy = rhs;
      std::swap(*this, copy);
      return *this;
    }

    List & operator= (List && rhs) {
      std::swap(_size, rhs._size);
      std::swap(_head, rhs._head);
      std::swap(_tail, rhs._tail);

      return *this;
    }

    ~List() {
      clear();
      delete _head;
      delete _tail;
    }

    iterator begin() { return ++(iterator(*this, _head)); }
    iterator end() { return iterator(*this, _tail); }

    const_iterator begin() const { return ++(const_iterator(*this, _head)); }
    const_iterator end() const { return const_iterator(*this, _tail); }

    size_t size() const { return _size; }
    bool empty() const { return _size == 0; }

    Object & front() { return *begin(); }
    const Object & front() const { return *begin(); }

    Object & back() { return *--end(); }
    const Object & back() const { return *--end(); }

    void push_front(const Object & x) { insert( begin(), x); }
    void push_front(Object && x) { insert( begin(), std::move(x)); }

    void push_back(const Object & x) { insert(end(), x); }
    void push_back(Object && x) { insert(end(), std::move(x)); }

    void pop_front() { erase(begin()); }
    void pop_back() { erase(--end()); }

    void clear() {
      while(!empty())
        pop_front();
    }

    // Insert node before iterator
    iterator insert(iterator itr, const Object & x) {
      itr.assert_is_valid();
      if (itr.list != this)
        throw std::invalid_argument("Iterator mismatch");

      Node * p = itr.current;
      _size++;
      p->prev = p->prev->next = new Node(x, p->prev, p);

      return { *this, p->prev };
    }

    iterator insert(iterator itr, Object && x) {
      itr.assert_is_valid();
      if (itr.list != this)
        throw std::invalid_argument("Iterator mismatch");

      Node * p = itr.current;
      _size++;
      p->prev = p->prev->next = new Node(std::move(x), p->prev, p);

      return { *this, p->prev };
    }

    // Erases element at iterator. Returns iterator of next element.
    iterator erase(iterator itr) {
      itr.assert_is_valid();
      if (itr.list != this)
        throw std::invalid_argument("Iterator mismatch");

      Node * p = itr.current;
      iterator ret(*this, p->next);
      p->prev->next = p->next;
      p->next->prev = p->prev;
      _size--;
      delete p;

      return ret;
    }

    // Erases elements in range [from, to)
    // Returns iterator to the first non-deleted element (to)
    iterator erase(iterator from, iterator to) {
      for (auto iter = from; iter != to;)
        iter = erase(iter);

      return to;
    }

  private:
    size_t _size;
    Node * _head;
    Node * _tail;;

    void init() {
      _size = 0;
      _head = new Node;
      _tail = new Node;
      _head->next = _tail;
      _tail->prev = _head;
    }
};

#endif
