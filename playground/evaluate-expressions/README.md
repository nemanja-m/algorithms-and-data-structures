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

When an operand is read, it is immediately placed onto output. operators are not immediately output, so they must be saved somewhere.
The correct thing to do is to place operators that have been seen, but not placed on the output, onto stack. We will also stack left parentheses when they are encountered. We start with an initially empty stack.

If we see a right parenthesis, then we pop the stack, writing symbols until we encouter a (corresponding) left parenthesis, which is popped but not output.

If we see any other symbol (+, \*, -, ( ), then we pop entries from the stack until we find an entry of lower priority. One exception is that we never remove a '(' from the stack except when processing a ')'. For the purpose of this operation, + has lowest priority and '(' highest.

When popping is done, we push the operator onto the stack.
Finally, if we read the end of input, we pop stack until it is empty, writing symbols onto the output.

## Postfix Notation Evaluation

When a number is seen, it is pushed onto stack. When an operator is seen, the operator is applied to the two numbers popped from the stack, and the result is pushed onto the stack.

For instance, the postfix expression

```
23+8*
```

is evaluated as follows:

- The first two symbols are placed onto the stack (2 and 3) `|2|3| <- top`
- Next, a '+' is read, so 2 and 3 are popped from the stack and their sum, 5, is pushed. `|5| <- top`
- Next, 8 is pushed `|5|8| <- top`
- When '\*' is read, 5 and 8 are popped and '\*' is applied, 40 is pushed. `|40| <- top`

We reached end of the input and stack contains final result: 40.

# Usage

Compile with:

``` bash
make
```

Start interactive shell with:

``` bash
./evaluate
```

Than write expressions:

``` bash
>>> 1 + 1
>>> 2
```

Assumption is that input expressions are valid and only have supported operators: +, -, \*, ()
