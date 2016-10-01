#ifndef __CONVERTOR__
#define __CONVERTOR__

#include "string"
#include "stack"

#define to_digit(x) (x - '0')

bool is_operator(const char &op) {
  return (op == '-') || (op == '+') || (op == '*') || (op == '/');
}

// Checks weather first argument is lower priority than second
bool is_lower_priority(const char & first, const char & second) {
  switch (second) {
    case '(' : return first != ')';
    case '*' :
    case '/' : return (first == '+') || (first == '-');
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
    if (is_operator(symbol) || (symbol == '(') || (symbol == ')')) {

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
        while (!operators.empty() && !is_lower_priority(operators.top(), symbol)) {
          output.push_back(operators.top());
          operators.pop();
        }
      }

      // After popping, push current operator to stack
      operators.push(symbol);
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

#include "iostream"

double evaluate(std::string & expression) {
  std::string postfix = inline_to_postfix(expression);

  std::cout << "\npostfix: " << postfix << "\n\n";

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
