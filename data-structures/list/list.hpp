#ifndef __LIST__
#define __LIST__

#include "iterator"

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
        const_iterator() : current(nullptr) {}

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

        bool operator== (const const_iterator & rhs) const {
          return current == rhs.current;
        }

        bool operator!= (const const_iterator & rhs) const {
          return current != rhs.current;
        }

      protected:
        Node *current;

        Object & retreive() { return current->data; }
        const_iterator(Node *p) : current(p) { }

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

      protected:
        iterator(Node *p) : const_iterator(p) { }

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

    iterator begin() { return _head->next; }
    iterator end() { return _tail; }
    const_iterator begin() const { return _head->next; }
    const_iterator end() const { return _tail; }

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

    // Insert node before iterator
    iterator insert(iterator itr, const Object & x) {
      Node * p = itr.current;
      _size++;
      return (p->prev->next = p->prev = new Node(x, p->prev, p));
    }

    iterator insert(iterator itr, Object && x) {
      Node * p = itr.current;
      _size++;
      return (p->prev->next = p->prev = new Node(std::move(x), p->prev, p));
    }
};

#endif
