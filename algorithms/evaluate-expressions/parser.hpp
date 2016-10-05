#ifndef __PARSER__
#define __PARSER__

#include "vector"
#include "string"

namespace Parser {
  // Returns elements in given input expression.
  // Parses numbers and operators.
  //
  // i.e. args = "1.23 + 7 * (2 / 2.5)"
  //
  // parse(args)
  //
  // => ["1.23", "+", "7", "*", "(", "2", "/", "2.5", ")"]
  //
  std::vector<std::string> parse(std::string args);
}

#endif
