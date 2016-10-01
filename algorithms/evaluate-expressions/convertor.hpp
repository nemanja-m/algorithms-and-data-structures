#ifndef __CONVERTOR__
#define __CONVERTOR__

#include "string"
#include "stack"

#define to_digit(x) (x - '0')

bool is_operator(const char &op) {
  return (op == '-') || (op == '+') || (op == '*') || (op == '/');
}

double apply(const char & op, double x, double y) {
  double result;

  switch (op) {
    case '+' : result = x + y; break;
    case '-' : result = x - y; break;
    case '*' : result = x * y; break;
    case '/' : result = x / y; break;
  }

  return result;
}

// std::string inline_to_postfix(std::string & expression) {
//
// }

double evaluate(std::string & expression) {
  // std::string postfix = inline_to_postfix(expression);

  std::stack<double> operands;

  for (char &symbol : postfix) {
    if (is_operator(symbol)) {
      // All operators are binary so we pop 2 operands from stack
      double x = operands.top(); operands.pop();
      double y = operands.top(); operands.pop();

      // Apply current operator to popped operands
      // and push result into stack
      operands.push(apply(symbol, x, y));
    }
    else {
      operands.push(to_digit(symbol));
    }
  }

  return operands.top();
}

#endif
