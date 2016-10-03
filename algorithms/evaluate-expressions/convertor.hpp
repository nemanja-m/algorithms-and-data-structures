#ifndef __CONVERTOR__
#define __CONVERTOR__

#include "string"
#include "stack"

#define to_digit(x) (x - '0')

bool is_operator(const char &op) {
  return (op == '-') || (op == '+') || (op == '*') || (op == '/');
}

// Checks weather first argument is higher priority than second
bool is_higher_priority(const char & first, const char & second) {
  switch (first) {
    case '(' : return true;
    case '/' :
    case '*' : return (second == '+') || (second == '-');
  }

  return false;
}

// Applies given operator to operands
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

std::string inline_to_postfix(std::string & expression) {
  std::string      output;
  std::stack<char> operators;

  for (char &symbol : expression) {
    if ( is_operator(symbol) || (symbol == '(') || (symbol == ')') ) {

      if (symbol == ')') {
        while ( !operators.empty() && (operators.top() != '(') ) {
          output.push_back(operators.top());
          operators.pop();
        }

        // Pop '('
        operators.pop();
      }
      else {
        // +, -, *, (
        // Pop stack until we find an operator with lower priority
        while (!operators.empty() && is_higher_priority(operators.top(), symbol)) {
          if (operators.top() == '(')
            break;

          // TODO
          output.push_back(operators.top());
          operators.pop();
        }

        // After popping, push current operator to stack
        operators.push(symbol);
      }

    }
    else {
      // If current symbol is operand
      output.push_back(symbol);
    }
  }

  // Put remaining operators from stack to output
  while (!operators.empty()) {
    output.push_back(operators.top());
    operators.pop();
  }

  return output;
}

double evaluate(std::string & expression) {
  std::string postfix = inline_to_postfix(expression);
  std::stack<double> operands;

  for (char &symbol : postfix) {
    if (is_operator(symbol)) {
      // All operators are binary so we pop 2 operands from stack
      double x = operands.top(); operands.pop();
      double y = operands.top(); operands.pop();

      // Apply current operator to popped operands
      // and push result into stack
      operands.push(apply(symbol, y, x));
    }
    else {
      operands.push(to_digit(symbol));
    }
  }

  return operands.top();
}

#endif
