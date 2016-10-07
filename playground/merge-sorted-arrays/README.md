# Problem

Give an ```O(n lg k)``` time algorithm to merge k sorted arrays into one sorted array,
where n is the total number of elements in all the input arrays.

# Solution

We take one element of each array and put it in a min-heap.
Along with each element we have to track which array we took it from.
When merging, we take the minimum element from the heap
and insert another element off the array it came from (unless the array is empty).
We continue until we empty the heap.

We have n steps and at each step we're doing an insertion into the heap,
which is ```O(lg k)```. At any given time max height of heap is k.

# Run

Run test example with:
```bash
make run ARRAYS=number_of_arrays
```

Example:
```
make run ARRAYS=5
```

will generate 5 sorted arrays with random lengths and random elements.
