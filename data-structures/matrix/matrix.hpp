#ifndef __MATRIX__
#define __MATRIX__

#include "vector"
#include "stddef.h"
#include "iostream"
#include "iomanip"

template<class Object>
class matrix {

  public:
    explicit matrix(size_t rows, size_t columns) : arrays(rows) {
      for (size_t i = 0; i < arrays.size(); i++) {
        arrays[i].resize(columns);
      }
    }

    matrix(std::vector<std::vector<Object> > &v) : arrays(v) { }
    matrix(std::vector<std::vector<Object> > &&v) : arrays(std::move(v)) { }

    size_t rows() const { return arrays.size(); }
    size_t columns() const { return rows() ? arrays[0].size() : 0; }

    const std::vector<Object> & operator[] (int row) const {
      return this->arrays[row];
    }

    std::vector<Object> & operator[] (int row) {
      return this->arrays[row];
    }

    void print() {
      for (auto &array : arrays) {
        for (auto &element : array) {
          std::cout << std::setw(3) << element << " ";
        }
        std::cout << std::endl;
      }
    }

  private:
    std::vector<std::vector<Object> > arrays;
};

#endif
