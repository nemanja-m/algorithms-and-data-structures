#ifndef __EVALUATOR__
#define __EVALUATOR__

#include "string"
#include "stack"
#include "vector"

namespace Evaluator {
  // Evaluates given expression.
  // Input vector contains all tokens (numbers and operators)
  // from given expression. Returns result of expression
  double evaluate(std::vector<std::string> &tokens);

  // Converts expression rom infix to postfix notation
  std::vector<std::string> infix_to_postfix(std::vector<std::string> & tokens);
}

#endif
