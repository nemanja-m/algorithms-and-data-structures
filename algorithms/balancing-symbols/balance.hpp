#ifndef __BALANCE__
#define __BALANCE__

#include "string"
#include "stack"

struct Result {
  bool   balanced = false;
  size_t idx = 0;
};

inline bool is_opening(const char &symbol) {
  return (symbol == '(') || (symbol == '[') || (symbol == '{');
}

inline bool are_match(const char &opening, const char &closing) {
  switch (closing) {
    case ')' : return opening == '(';
    case ']' : return opening == '[';
    case '}' : return opening == '{';
  }

  return false;
}

// Check weather input sequence of symbols (braces, brackets and parenthesis) are balanced.
// Returns struct with success info.
//
// {true, 0}      --> balanced
// {false, index} --> unbalanced
//
// where 'index' corresponds to char in input string which isn't balanced.
Result balance(const std::string &symbols) {
  Result ret;

  std::stack<char> stack;

  for (size_t i = 0; i < symbols.size(); ++i) {
    ret.idx = i;

    if (is_opening(symbols[i])) {
      stack.push(symbols[i]);
    }
    else {
      // Closing symbol and stack empty
      if (stack.empty())
        return ret;

      char top = stack.top();
      stack.pop();

      // Check weather popped symbol matches current input char
      if (!are_match(top, symbols[i]))
        return ret;
    }
  }

  ret.balanced = stack.empty();

  return ret;
}

#endif
