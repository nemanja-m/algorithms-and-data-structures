# About

Program that evaluates simple algebraic expression in linear time.

Supported operations: +, -, \*, /, ()

i.e. For an input expression `5 + 3 * 2 + (1 + 2) / 3` output should be 12.

Simple rules:

- Parenthesis have highest priority
- Multiplication and division are same priority
- Addition and substraction are same priority
- Multiplication and division are higher priority than addition and substraction

# How it works

Input expression is first converted to postfix notation in `O(n)` time where `n` is number of characters
in given input. After that, using stack, we can simply evaluate expression, also in `O(n)` time.

## Inline to Postfix Conversion

###TODO

## Postfix Notation Evaluation

###TODO

# Usage

Compile with:

``` bash
make
```

Run with given command line argument:


``` bash
./evaluate 1 + 1

# => 2
```

Assumption is that input expressions are valid and only have supported operators: +, -, \*, ()
