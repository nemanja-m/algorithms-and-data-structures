#include "helpers.hpp"
#include "iostream"

void print(int *array, size_t length) {
  for (size_t i = 0; i < length; i++) {
    std::cout << array[i] << " ";
  }

  std::cout << std::endl;
}

void print(const std::vector<int> vector) {
  for (auto element : vector)
    std::cout << element << " ";

  std::cout << std::endl;
}

void print(const std::vector<std::vector<int> > vector2D) {
  for (auto vector : vector2D) {
    for (auto element : vector) {
      std::cout << element << " ";
    }
    std::cout << std::endl;
  }
}
