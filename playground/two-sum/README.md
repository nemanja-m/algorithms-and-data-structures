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

Run Coursera's test with:

``` bash
make coursera
```

Input test file contains million integers.
