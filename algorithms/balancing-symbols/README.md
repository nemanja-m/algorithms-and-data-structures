# About

Program that checks wheather symbols are balanced. In this particular case it checks braces. Every right
brace, bracket and parenthesis must correspond to its left counterpart.
The sequence `[()]` is legal but `[(]` is wrong.

# Algorithm

The simple algorithm uses stack and is as follows:

1. Make an empty stack.
2. Read characters until end of input.
3. If it is opening characther, push it onto stack.
4. If it is closing character and stack is empty, report an error. Otherwise, pop the stack.
5. If hte popped element is not the corresponding opening symbol, report an error.
6. At the end of input if the stack is not empty, report an error.

Given algorithm has `O(n)` time complexity.

# Tests

To run tests use:

``` bash
make test
```

# Usage

Compile with:

``` bash
make
```

Run with:

``` bash
./balance symbol_sequence
```

For an example:

``` bash
./balance "[{()}]"

# => Balanced
```

``` bash
./balance "[(]"

# => Unbalanced! [ __(__ ]
```
