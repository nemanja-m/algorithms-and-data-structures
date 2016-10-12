#ifndef __COURSERA__
#define __COURSERA__

#include "vector"
#include "stdint.h"
#include "algorithm"
#include "unordered_set"

namespace Coursera {

  const int LOWER_BOUND = -10000;
  const int UPPER_BOUND = 10000;

  size_t count(std::vector<int64_t> &array) {
    std::sort(array.begin(), array.end(),
        [](int64_t x, int64_t y) { return x < y; });

    // Numbers in [LOWER_BOUND, UPPER_BOUND]
    std::unordered_set<int> sums;

    for (auto num : array) {
      auto lower = std::lower_bound(array.begin(), array.end(), LOWER_BOUND - num);
      auto upper = std::upper_bound(array.begin(), array.end(), UPPER_BOUND - num);

      for (auto iter = lower; iter != upper; ++iter) {
        if (*iter != num)
          sums.insert(num + *iter);
      }
    }

    return sums.size();
  }
}

#endif
