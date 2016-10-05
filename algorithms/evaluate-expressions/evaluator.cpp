#include "evaluator.hpp"

namespace Evaluator {

  namespace {
    bool is_operator(const std::string &op) {
      return (op == "-")
          || (op == "+")
          || (op == "*")
          || (op == "/")
          || (op == "(")
          || (op == ")");
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
  }

  std::vector<std::string> infix_to_postfix(std::vector<std::string> & tokens) {

    std::vector<std::string> output;
    std::stack<std::string>  operators;

    for (auto &token : tokens) {
      if (is_operator(token)) {

        if (token == ")") {
          while ( !operators.empty() && (operators.top() != "(") ) {
            output.push_back(operators.top());
            operators.pop();
          }

          // Pop '('
          operators.pop();
        }
        else {
          // Pop stack until we find an operator with lower priority
          while (!operators.empty()
              && is_higher_priority(operators.top()[0], token[0])
              && (operators.top() != "("))
          {
            output.push_back(operators.top());
            operators.pop();
          }

          // After popping, push current operator to stack
          operators.push(token);
        }

      }
      else {
        // If current token is operand
        output.push_back(token);
      }
    }

    // Put remaining operators from stack to output
    while (!operators.empty()) {
      output.push_back(operators.top());
      operators.pop();
    }

    return output;
  }

  double evaluate(std::vector<std::string> & tokens) {
    std::vector<std::string> postfix = infix_to_postfix(tokens);
    std::stack<double> operands;

    for (auto &token : postfix) {
      if (is_operator(token)) {
        // All operators are binary so we pop 2 operands from stack
        double x = operands.top(); operands.pop();
        double y = operands.top(); operands.pop();

        // Apply current operator to popped operands
        // and push result into stack
        operands.push(apply(token[0], y, x));
      }
      else {
        // Convert string to double
        operands.push(std::stod(token));
      }
    }

    return operands.top();
  }
}
