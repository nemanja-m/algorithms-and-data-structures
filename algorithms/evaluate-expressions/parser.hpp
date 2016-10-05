#ifndef __PARSER__
#define __PARSER__

#include "vector"
#include "string"
#include "algorithm"

// Checks weather given char can be part
// of number (digits and decimal dot)
bool is_num_char(const char &ch) {
  return isdigit(ch) || (ch == '.');
}

// Returns elements in given input expression.
// Parses numbers and operators.
//
// i.e. args = "1.23 + 7 * (2 / 2.5)"
//
// parse(args)
//
// => ["1.23", "+", "7", "*", "(", "2", "/", "2.5", ")"]
//
std::vector<std::string> parse(std::string args) {
  // Remove white spaces
  args.erase(remove_if(args.begin(), args.end(), ::isspace), args.end());

  std::string digit;
  std::vector<std::string> tokens;

  for (std::string::size_type i = 0; i < args.size(); ++i) {
    if (is_num_char(args[i])) {
      digit.push_back(args[i]);
    }
    else {
      // Push prevoius parsed number
      if (!digit.empty()) {
        tokens.push_back(digit);
        digit.clear();
      }

      // Push non-number character (operators)
      tokens.push_back(std::string(1, args[i]));
    }
  }

  if (!digit.empty())
    tokens.push_back(digit);

  return tokens;
}

#endif
