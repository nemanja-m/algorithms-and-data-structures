# Problem

The goal of this problem is to implement the "Median Maintenance" algorithm. The text file contains a list of the integers from 1 to 10000 in unsorted order;
Letting `x<sub>i</sub>` denote the `ith` number of the file, the `kth` median `m<sub>k</sub>` is defined as the median of the numbers x1, …, xk.

So, if k is odd, then mk is ((k+1)/2)th smallest number among x1, …, xk; if k is even, then mk is the (k/2)th smallest number among x1, …, xk.

Calculate sum of these 10000 medians, modulo 10000 (i.e., only the last 4 digits). That is, we should compute (m1 + m2 + m3 + ⋯ +m10000)mod10000.

# Algorithm

The idea is to use tow heaps: `min_heap` where bigger half of input array is stored and `max_heap` where smaller half of input numbers is stored.
When we want to insert new number we check which in which heap we should insert element. If heaps are unbalanced we pop element from one to another heap
so we maintain balance between heaps (sizes of heaps is max 1). The median is always at the top of one of the heaps.

# Usage

Run test with:

``` bash
make test
```
