#ifndef __TWO_SUM__
#define __TWO_SUM__

#include "map"
#include "vector"

namespace TwoSum {
  size_t count(const std::vector<int> &array, int target) {
    std::map<int, size_t> numbers;

    // Create map where key is input int
    // and value is number of occurances in input array
    for (auto &num : array)
      if (numbers.find(num) != numbers.end())
        ++numbers[num];
      else
        numbers[num] = 1;

    size_t counter = 0;

    for (auto &num : array)
      if (num != (target - num))
        if (numbers.find(target - num) != numbers.end())
          counter += numbers[target - num];

    // Return half because of duplicates
    return counter / 2;
  }
}

#endif
