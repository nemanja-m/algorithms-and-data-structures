# Problem

Given an array of integers, return number of pairs `(x, y), x != y` such as `x + y = t` where
target `t` is specified.

Input array may contain duplicate, positive or negative integers. Algorithm should run in `O(n)` time.

# Solution

Use `hash map` where key is input integer and value is number of occurances in given input array.

For an example array `{1, 1, 2, 0, -3}` map should be:

```
[1]  = 2
[2]  = 1
[0]  = 1
[-3] = 1
```

Than for a given tartget integer `t` and for each integer `x` in input array look up in map for `t - x` key.

# Tests

Run tests with:

``` bash
make test
```

Test files with input arrays are located in `test_data` folder.

# Coursera Modification

One of programming assignments (6th week assignment) in Coursera's [course](https://www.coursera.org/learn/algorithm-design-analysis) requires
modification on previous algorithm.

Task is to compute number of target values `t` in the interval [-10000, 10000] such that there are distinct numbers `x, y` in input array
that satisfy `x + y = t`

In this case we don't use `map` because even if lookup is `O(1)` we would still have billions of lookups. To be more precise, we would have
20001 * 1000000 lookups, and that is too much.

Instead, we sort input array and for each number `x` in array define window `[-10000 - x, 10000 - x]` then find numbers in that window.
Count of numbers in each window is equal to count of numbers in interval `[-10000, 10000]` that are equal to sum of some 2 distinct number from input file.

Run Coursera's test with:

``` bash
make coursera
```

Input test file contains million integers.
